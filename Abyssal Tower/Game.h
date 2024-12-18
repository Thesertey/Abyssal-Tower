#ifndef GAME_H
#define GAME_H

#include "Characters.h"
#include "Rooms.h"
#include "Bosses.h"

#define TOTAL_FLOORS 10

void start_game();
void save_game(int current_floor, int game_mode, Character *character);
int load_game(int *current_floor, int *game_mode, Character *character);
void end_game();
void main_menu();
void play_game(int *current_floor, int game_mode, Character *player, Room *tower, Inventory *inventory);
void simulate_battle(Character *player, Boss *boss);
void interactive_battle(Character *player, Boss *boss);

#endif // GAME_H
