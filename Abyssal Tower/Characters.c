
#include <stdio.h>
#include <string.h>
#include "Characters.h"

Character create_character(CharacterType type) {
    Character character;

    switch (type) {
        case MAGE:
            strcpy(character.name, "Mage");
            character.health = 100;
            character.defense = 5;
            character.attack_power = 100;
            character.ability_power = 100;
            character.attack_hits = 1;
            break;
        case FIGHTER:
            strcpy(character.name, "Fighter");
            character.health = 100;
            character.defense = 15;
            character.attack_power = 100;
            character.ability_power = 100;
            character.attack_hits = 1;
            break;
        case ARCHER:
            strcpy(character.name, "Archer");
            character.health = 100;
            character.defense = 5;
            character.attack_power = 100;
            character.ability_power = 100;
            character.attack_hits = 1;
            break;
        case ASSASSIN:
            strcpy(character.name, "Assassin");
            character.health = 100;
            character.defense = 10;
            character.attack_power = 100;
            character.ability_power = 100;
            character.attack_hits = 2;
            break;
        case TANK:
            strcpy(character.name, "Tank");
            character.health = 100;
            character.defense = 25;
            character.attack_power = 100;
            character.ability_power = 100;
            character.attack_hits = 1;
            break;
    }

    return character;
}

void print_character_stats(const Character *character) {
    printf("Character: %s\n", character->name);
    printf("Health: %d\n", character->health);
    printf("Defense: %d\n", character->defense);
    printf("Attack Power: %d\n", character->attack_power);
    printf("Ability Power: %d\n", character->ability_power);
    printf("Attack Hits: %d\n", character->attack_hits);
}
