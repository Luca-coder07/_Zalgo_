/*

Author : Luca RANDRIANIRINA (lucarandrianirina2507@gmail.com)

AABB Collision Detection
Détection simple de collisions entre boîtes alignées sur les axes

*/

typedef struct {
    float x;
    float y;
    float width;
    float height;
} AABB;

int aabb_collide(AABB a, AABB b) {
    return !(a.x + a.width < b.x ||
             a.x > b.x + b.width ||
             a.y + a.height < b.y ||
             a.y > b.y + b.height);
}

// Main Test
#include <stdio.h>
int main(void) {
    AABB box1 = {0.0f, 0.0f, 2.0f, 2.0f};
    AABB box2 = {1.0f, 1.0f, 2.0f, 2.0f};
    AABB box3 = {3.0f, 3.0f, 1.0f, 1.0f};
    
    printf("Box 1 collides with Box 2: %s\n", aabb_collide(box1, box2) ? "Yes" : "No");
    printf("Box 1 collides with Box 3: %s\n", aabb_collide(box1, box3) ? "Yes" : "No");
    
    return 0;
}