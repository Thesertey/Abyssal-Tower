#include <stdio.h>
#include <stdlib.h>
#include "Rooms.h"

Room *create_room(int floor_number, RoomType type) {
    Room *new_room = (Room *)malloc(sizeof(Room));
    if (!new_room) {
        perror("Failed to allocate memory for room");
        exit(EXIT_FAILURE);
    }
    new_room->floor_number = floor_number;
    new_room->type = type;
    new_room->miniboss_defeated = 0; 
    new_room->next = NULL;

    return new_room;
}

Room *create_tower() {
    Room *head = NULL;
    Room *current = NULL;

    for (int i = 1; i <= TOTAL_FLOORS; i++) {
        RoomType type = (i % 2 == 0) ? BOSS_ROOM : MINIBOSS_ROOM;
        Room *new_room = create_room(i, type);

        if (!head) {
            head = new_room;
        } else {
            current->next = new_room;
        }
        current = new_room;
    }

    return head;
}

void free_tower(Room *head) {
    Room *current = head;
    while (current) {
        Room *temp = current;
        current = current->next;
        free(temp);
    }
}

Room *find_room(Room *head, int floor) {
    Room *current = head;
    while (current) {
        if (current->floor_number == floor) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void print_room_description(Room *room) {
    if (!room) {
        printf("This room does not exist.\n");
        return;
    }

    printf("Floor %d: ", room->floor_number);
    if (room->type == MINIBOSS_ROOM) {
        printf("A challenging miniboss awaits you!\n");
    } else {
        printf("You face a powerful boss!\n");
    }
}
