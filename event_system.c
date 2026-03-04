/*

Author : Luca RANDRIANIRINA (lucarandrianirina2507@gmail.com)

Event System
Système d'événements pour la communication entre composants

*/

typedef void (*EventHandler)(void*);

typedef struct {
    char* event_name;
    EventHandler handler;
    void* data;
} Event;

typedef struct {
    Event* events;
    int capacity;
    int count;
} EventManager;

void event_manager_init(EventManager *manager, int capacity) {
    manager->events = (Event*)malloc(sizeof(Event) * capacity);
    manager->capacity = capacity;
    manager->count = 0;
}

void event_manager_add(EventManager *manager, char* name, EventHandler handler, void* data) {
    if (manager->count < manager->capacity) {
        manager->events[manager->count].event_name = name;
        manager->events[manager->count].handler = handler;
        manager->events[manager->count].data = data;
        manager->count++;
    }
}

void event_manager_trigger(EventManager *manager, char* name) {
    for (int i = 0; i < manager->count; i++) {
        if (strcmp(manager->events[i].event_name, name) == 0) {
            manager->events[i].handler(manager->events[i].data);
        }
    }
}

void event_manager_free(EventManager *manager) {
    free(manager->events);
}

// Main Test
#include <stdio.h>
#include <time.h>
#include <string.h>

void on_player_died(void* data) {
    printf("Player died! %s\n", (char*)data);
}

void on_enemy_spawned(void* data) {
    printf("Enemy spawned: %s\n", (char*)data);
}

int main(void) {
    EventManager manager;
    event_manager_init(&manager, 10);
    
    event_manager_add(&manager, "player_died", on_player_died, "Health: 0");
    event_manager_add(&manager, "enemy_spawned", on_enemy_spawned, "Zombie");
    
    printf("Triggering player_died event...\n");
    event_manager_trigger(&manager, "player_died");
    
    printf("Triggering enemy_spawned event...\n");
    event_manager_trigger(&manager, "enemy_spawned");
    
    event_manager_free(&manager);
    
    return 0;
}