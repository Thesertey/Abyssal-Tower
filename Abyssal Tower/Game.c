#include "game.h"
#include "rooms.h"
#include "items.h"
#include "bosses.h"
#include "characters.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void start_game() {
    printf("\nWelcome to 'Abyssal Tower'!\n");
    printf("Choose your mode:\n");
    printf("1. Normal Mode\n");
    printf("2. Hard Mode\n");
    printf("3. Exit\n");
}

void save_game(int current_floor, int game_mode, Character *character) {
    FILE *file = fopen("savegame.txt", "w");
    if (file == NULL) {
        printf("Error: Unable to save the game.\n");
        return;
    }
    fprintf(file, "%d\n", current_floor);
    fprintf(file, "%d\n", game_mode);
    fprintf(file, "%s %d %d %d %d %d\n", character->name, character->health, character->defense, character->attack_power, character->ability_power, character->attack_hits);
    fclose(file);
    printf("Game saved successfully!\n");
}

int load_game(int *current_floor, int *game_mode, Character *character) {
    FILE *file = fopen("savegame.txt", "r");
    if (file == NULL) {
        printf("No saved game found.\n");
        return 0;
    }
    fscanf(file, "%d", current_floor);
    fscanf(file, "%d", game_mode);
    fscanf(file, "%s %d %d %d %d %d", character->name, &character->health, &character->defense, &character->attack_power, &character->ability_power, &character->attack_hits);
    fclose(file);
    printf("Game loaded successfully!\n");
    return 1;
}

void end_game() {
    printf("\nCongratulations Adventurer! You have survived the trials and defeated all the bosses.\n");
    printf("A warrior like you is rare to find.\n");
    printf("\n--- Abyssal Tower ---\n");
}

void main_menu() {
    int choice;
    int current_floor = 1;
    int game_mode = 0;
    Character player;
    Inventory player_inventory;

    do {
        printf("\n1. New Game\n");
        printf("2. Load Game\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                start_game();
                printf("Select your mode: ");
                scanf("%d", &game_mode);
                if (game_mode == 1 || game_mode == 2) {
                    printf("Character Selection:\n");
                    printf("1. Mage\n2. Fighter\n3. Archer\n4. Assassin\n5. Tank\n");
                    int character_choice;
                    scanf("%d", &character_choice);
                    player = create_character((CharacterType)(character_choice - 1));

                    initialize_inventory(&player_inventory); // Envanteri başlat

                    printf("Do you want to enter the Tower? (1: Yes, 2: No): ");
                    int enter_tower;
                    scanf("%d", &enter_tower);

                    if (enter_tower == 1) {
                        Room *tower = create_tower();
                        play_game(&current_floor, game_mode, &player, tower, &player_inventory);
                        free_tower(tower);
                    } else {
                        printf("Returning to main menu.\n");
                    }
                } else {
                    printf("Invalid mode selection. Returning to main menu.\n");
                }
                break;
            case 2:
                if (load_game(&current_floor, &game_mode, &player)) {
                    initialize_inventory(&player_inventory); // Envanteri yükle
                    printf("Resuming at floor %d.\n", current_floor);
                    Room *tower = create_tower();
                    play_game(&current_floor, game_mode, &player, tower, &player_inventory);
                    free_tower(tower);
                }
                break;
            case 3:
                printf("Exiting the game. See you next time!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);
}

void play_game(int *current_floor, int game_mode, Character *player, Room *tower, Inventory *inventory) {
    Boss minibosses[5];
    Boss main_bosses[5];
    initialize_bosses(minibosses, main_bosses);

    printf("Entering Abyssal Tower...\n");
    while (*current_floor <= TOTAL_FLOORS) {
        Room *current_room = find_room(tower, *current_floor);
        print_room_description(current_room);

        printf("Do you want to start the boss battle? (1: Yes, 2: No): ");
        int battle_choice;
        scanf("%d", &battle_choice);

        if (battle_choice == 1) {
            Boss *boss;
            if (current_room->type == MINIBOSS_ROOM) {
                boss = &minibosses[*current_floor / 2];
            } else {
                boss = &main_bosses[*current_floor / 2 - 1];
            }

            simulate_battle(player, boss);

            if (player->health <= 0) {
                printf("This time it didn't work out, but don't worry! You'll come back stronger next time.\n");
                *current_floor = 1;
                player->health = player->health;
                Room *tower = create_tower();
                free_tower(tower);
                break;
            } else if (boss->health <= 0) {
                printf("You defeated the boss!\n");
                drop_random_loot(inventory); // Loot düşürme eklendi
                printf("Current Inventory:\n");
                print_inventory(inventory); // Envanteri yazdır

                (*current_floor)++;
                if (game_mode == 1) {
                    save_game(*current_floor, game_mode, player);
                }
            }
        } else {
            printf("Skipping the boss battle. Returning to the main menu.\n");
            break;
        }
    }
    if (*current_floor > TOTAL_FLOORS) {
        end_game();
    }
}

void simulate_battle(Character *player, Boss *boss) {
    printf("\n=== Simulated Battle ===\n");
    while (player->health > 0 && boss->health > 0) {
        boss->health -= player->attack_power;
        if (boss->health <= 0) {
            printf("%s defeated the boss %s with %d HP remaining!\n", player->name, boss->name, player->health);
            player->health = 100;
            printf("Your health has been fully restored to %d.\n", 100);
            return;
        }

        player->health -= boss->damage;
        if (player->health <= 0) {
            printf("The boss %s defeated %s with %d HP remaining!\n", boss->name, player->name, boss->health);
            return;
        }
    }    

}