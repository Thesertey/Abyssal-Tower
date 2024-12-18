#include <stdio.h>
#include "game.h"
#include "rooms.h"
#include "items.h"
#include "bosses.h"
#include "characters.h"

int main() {
    // Oyun karşılama mesajı ve ana menüyü çağırma
    printf("\n--- Welcome to Abyssal Tower ---\n");
    printf("Prepare for an epic adventure full of challenges and rewards!\n");

    // Ana menüyü başlatıyoruz
    main_menu();

    // Oyunun çıkış mesajı
    printf("\nThank you for playing Abyssal Tower!\n");
    printf("See you in your next adventure!\n");

    return 0;
}
