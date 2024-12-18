#ifndef ROOMS_H
#define ROOMS_H

#include <stddef.h>

#define TOTAL_FLOORS 10

typedef enum {
    MINIBOSS_ROOM,
    BOSS_ROOM
} RoomType;

typedef struct Room {
    int floor_number;
    RoomType type;
    int miniboss_defeated;
    struct Room *next;
} Room;

Room *create_tower();
void free_tower(Room *head);
Room *find_room(Room *head, int floor);
void print_room_description(Room *room);

#endif
