
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Bosses.h"


Boss create_boss(const char *name, int health, int damage) {
    Boss boss;
    snprintf(boss.name, sizeof(boss.name), "%s", name);
    boss.health = health;
    boss.damage = damage;
    return boss;
}

void print_boss_info(const Boss *boss) {
    printf("Boss Name: %s\n", boss->name);
    printf("Health: %d\n", boss->health);
    printf("Damage: %d\n", boss->damage);
}

void drop_loot() {
    srand(time(NULL));
    int loot_type = rand() % 5;

    switch (loot_type) {
        case 0:
            printf("Loot Dropped: Health Potion\n");
            break;
        case 1:
            printf("Loot Dropped: Armor Fragment\n");
            break;
        case 2:
            printf("Loot Dropped: Weapon Part\n");
            break;
        case 3:
            printf("Loot Dropped: Gold Coins\n");
            break;
        case 4:
            printf("Loot Dropped: Rare Gem\n");
            break;
        default:
            printf("Loot Dropped: Nothing\n");
            break;
    }
}

// Initialize all bosses
void initialize_bosses(Boss *minibosses, Boss *main_bosses) {
    minibosses[0] = create_boss("Shadow Imp", 25, 2);
    main_bosses[0] = create_boss("Dark Warlord", 100, 10);

    minibosses[1] = create_boss("Cave Stalker", 30, 3);
    main_bosses[1] = create_boss("Infernal Beast", 150, 15);

    minibosses[2] = create_boss("Venom Flinger", 30, 3);
    main_bosses[2] = create_boss("Soul Reaper", 250, 17);

    minibosses[3] = create_boss("Iron Golem", 35, 4);
    main_bosses[3] = create_boss("Flame Tyrant", 350, 22);

    minibosses[4] = create_boss("Spectral Phantom", 50, 6);
    main_bosses[4] = create_boss("Abyss King", 400, 25);
}