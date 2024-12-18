#ifndef ITEMS_H
#define ITEMS_H

#define MAX_INVENTORY_SLOTS 25

// Item türleri
typedef enum {
    ARMOR,
    WEAPON,
    ARMOR_PART,
    WEAPON_PART,
    RARE_GEM
} ItemType;

// Item yapısı
typedef struct {
    char name[30];
    ItemType type;
    int effect_value;      // Etki değeri (örneğin, can ekleme, saldırı gücü vb.)
    int quantity;          // Adet sayısı
    int slots_required;    // Envanterde kapladığı slot sayısı
} Item;

// Inventory yapısı
typedef struct {
    Item items[MAX_INVENTORY_SLOTS];
    int current_slots; // Şu an kullanılan slot sayısı
    int item_count;    // Envanterdeki toplam öğe sayısı
} Inventory;

// Fonksiyon prototipleri
Item create_item(const char *name, ItemType type, int effect_value, int quantity, int slots_required);
void initialize_inventory(Inventory *inventory);
void add_item_to_inventory(Inventory *inventory, Item item);
void print_inventory(const Inventory *inventory);
void apply_stat_upgrade(ItemType type, int *stat_to_upgrade, int upgrade_value);
void drop_random_loot(Inventory *inventory);

#endif // ITEMS_H
