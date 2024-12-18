#ifndef BOSSES_H
#define BOSSES_H

#include <stdlib.h>
#include <time.h>

// Struct representing a boss
typedef struct Boss {
    char name[50];
    int health;
    int damage;
} Boss;

// Function prototypes
Boss create_boss(const char *name, int health, int damage);
void print_boss_info(const Boss *boss);
void drop_loot();
void initialize_bosses(Boss *minibosses, Boss *main_bosses); 

#endif // BOSSES_H
