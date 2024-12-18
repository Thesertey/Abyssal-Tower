#ifndef CHARACTERS_H
#define CHARACTERS_H

#include "Items.h"

// Character Type Enum
typedef enum {
    MAGE,
    FIGHTER,
    ARCHER,
    ASSASSIN,
    TANK
} CharacterType;

// Character Struct
typedef struct {
    CharacterType type;
    char name[20];
    int health;        // Can
    int defense;       // Savunma
    int attack_power;  // Fiziksel Saldırı Gücü
    int ability_power; // Büyü Saldırı Gücü
    int attack_hits;   // Saldırı vuruş sayısı (Assassin için 2)
    Inventory *inventory;
} Character;

// Function Prototypes
Character create_character(CharacterType type);
void print_character_stats(const Character *character);

#endif // CHARACTERS_H
