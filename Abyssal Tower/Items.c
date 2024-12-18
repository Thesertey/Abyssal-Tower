#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "items.h"

// Yeni bir item oluşturma
Item create_item(const char *name, ItemType type, int effect_value, int quantity, int slots_required) {
    Item item;
    strcpy(item.name, name);
    item.type = type;
    item.effect_value = effect_value;
    item.quantity = quantity;
    item.slots_required = slots_required;
    return item;
}

// Inventory başlangıç durumu
void initialize_inventory(Inventory *inventory) {
    inventory->current_slots = 0;
    inventory->item_count = 0;

    // Başlangıç silahı
    Item starting_weapon = create_item("Starter Weapon", WEAPON, 10, 1, 2);
    add_item_to_inventory(inventory, starting_weapon);

    // Başlangıç zırhı
    Item starting_armor = create_item("Starter Armor", ARMOR, 20, 1, 3);
    add_item_to_inventory(inventory, starting_armor);

}

// Envantere item ekleme
void add_item_to_inventory(Inventory *inventory, Item item) {
    if (inventory->current_slots + item.slots_required > MAX_INVENTORY_SLOTS) {
        printf("Not enough space in the inventory!\n");
        return;
    }

    inventory->items[inventory->item_count] = item;
    inventory->current_slots += item.slots_required;
    inventory->item_count += 1;
    printf("%s has been added to the inventory! (Slots used: %d)\n", item.name, item.slots_required);
}

// Envanteri yazdırma
void print_inventory(const Inventory *inventory) {
    printf("=== Inventory ===\n");

    int used_slots = 0;
    for (int i = 0; i < inventory->item_count; ++i) { // Döngü sınırı item_count ile kontrol ediliyor
        printf("%s x%d | Slots Required: %d\n", 
               inventory->items[i].name, 
               inventory->items[i].quantity, 
               inventory->items[i].slots_required);
        used_slots += inventory->items[i].slots_required * inventory->items[i].quantity;
    }

    printf("Total Slots Used: %d/%d\n", used_slots, MAX_INVENTORY_SLOTS);
}

// Rastgele loot düşürme
void drop_random_loot(Inventory *inventory) {
    int drop_chance = rand() % 100;

    if (drop_chance < 25) {
        add_item_to_inventory(inventory, create_item("Armor Part", ARMOR_PART, 0, 1, 1));
    } else if (drop_chance < 50) {
        add_item_to_inventory(inventory, create_item("Weapon Part", WEAPON_PART, 0, 1, 2));
    } else if (drop_chance < 75) {
        add_item_to_inventory(inventory, create_item("Rare Gem", RARE_GEM, 0, 1, 1));
    } else {
        printf("Nothing dropped!\n");
    }
}

// Stat geliştirme uygulama
void apply_stat_upgrade(ItemType type, int *stat_to_upgrade, int upgrade_value) {
    *stat_to_upgrade += upgrade_value;
    printf("Stat has been upgraded! New value: %d\n", *stat_to_upgrade);
}
