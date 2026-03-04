/*

Author : Luca RANDRIANIRINA (lucarandrianirina2507@gmail.com)

Object Pool System
Système de pool d'objets pour la réutilisation et éviter les allocations

*/

#include <stdlib.h>

typedef struct {
    int active;
    void* data;
} PoolObject;

typedef struct {
    PoolObject* objects;
    int capacity;
    int count;
    int next_free;
} ObjectPool;

void object_pool_init(ObjectPool *pool, int capacity, size_t object_size) {
    pool->objects = (PoolObject*)malloc(sizeof(PoolObject) * capacity);
    pool->capacity = capacity;
    pool->count = 0;
    pool->next_free = 0;
    
    for (int i = 0; i < capacity; i++) {
        pool->objects[i].active = 0;
        pool->objects[i].data = malloc(object_size);
    }
}

void* object_pool_acquire(ObjectPool *pool) {
    for (int i = pool->next_free; i < pool->capacity; i++) {
        if (!pool->objects[i].active) {
            pool->objects[i].active = 1;
            pool->count++;
            pool->next_free = i + 1;
            return pool->objects[i].data;
        }
    }
    
    // Wrap around if we reached the end
    for (int i = 0; i < pool->next_free; i++) {
        if (!pool->objects[i].active) {
            pool->objects[i].active = 1;
            pool->count++;
            pool->next_free = i + 1;
            return pool->objects[i].data;
        }
    }
    
    return NULL; // Pool is full
}

void object_pool_release(ObjectPool *pool, void* data) {
    for (int i = 0; i < pool->capacity; i++) {
        if (pool->objects[i].data == data && pool->objects[i].active) {
            pool->objects[i].active = 0;
            pool->count--;
            // Update next_free if this was before the current next_free
            if (i < pool->next_free) {
                pool->next_free = i;
            }
            return;
        }
    }
}

void object_pool_free(ObjectPool *pool) {
    for (int i = 0; i < pool->capacity; i++) {
        free(pool->objects[i].data);
    }
    free(pool->objects);
}

// Main Test
#include <stdio.h>

typedef struct {
    int id;
    float x, y;
} GameObject;

void print_object(GameObject* obj) {
    printf("Object %d at (%.1f, %.1f)\n", obj->id, obj->x, obj->y);
}

int main(void) {
    ObjectPool pool;
    object_pool_init(&pool, 5, sizeof(GameObject));
    
    GameObject* obj1 = (GameObject*)object_pool_acquire(&pool);
    if (obj1) {
        obj1->id = 1;
        obj1->x = 10.0f;
        obj1->y = 20.0f;
        printf("Acquired object 1: ");
        print_object(obj1);
    }
    
    GameObject* obj2 = (GameObject*)object_pool_acquire(&pool);
    if (obj2) {
        obj2->id = 2;
        obj2->x = 30.0f;
        obj2->y = 40.0f;
        printf("Acquired object 2: ");
        print_object(obj2);
    }
    
    printf("Releasing object 1...\n");
    object_pool_release(&pool, obj1);
    
    GameObject* obj3 = (GameObject*)object_pool_acquire(&pool);
    if (obj3) {
        obj3->id = 3;
        obj3->x = 50.0f;
        obj3->y = 60.0f;
        printf("Acquired object 3: ");
        print_object(obj3);
    }
    
    object_pool_free(&pool);
    
    return 0;
}