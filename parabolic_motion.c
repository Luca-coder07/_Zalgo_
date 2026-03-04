/*

Author : Luca RANDRIANIRINA (lucarandrianirina2507@gmail.com)

Parabolic Motion System
Mouvement en arc de parabole pour les sauts et projectiles

*/

#include <math.h>

typedef struct {
    float x;
    float y;
    float vx;
    float vy;
    float gravity;
} Projectile;

void projectile_init(Projectile *proj, float x, float y, float vx, float vy, float gravity) {
    proj->x = x;
    proj->y = y;
    proj->vx = vx;
    proj->vy = vy;
    proj->gravity = gravity;
}

void projectile_update(Projectile *proj, float delta_time) {
    proj->x += proj->vx * delta_time;
    proj->vy += proj->gravity * delta_time;
    proj->y += proj->vy * delta_time;
}

int projectile_is_grounded(Projectile *proj, float ground_y) {
    return proj->y <= ground_y;
}

// Main Test
#include <stdio.h>
#include <time.h>

int main(void) {
    Projectile proj;
    projectile_init(&proj, 0.0f, 0.0f, 5.0f, 10.0f, -9.81f);
    
    float ground_y = 0.0f;
    float delta_time = 0.016f; // ~60 FPS
    
    printf("Projectile launched!\n");
    printf("Time    X        Y        Velocity\n");
    printf("-------------------------------\n");
    
    for (int i = 0; i < 100; i++) {
        projectile_update(&proj, delta_time);
        
        if (projectile_is_grounded(&proj, ground_y)) {
            printf("Impact at t=%.2fs: (%.2f, %.2f)\n", i * delta_time, proj.x, proj.y);
            break;
        }
        
        if (i % 5 == 0) {
            printf("%.2fs  %.2f    %.2f    %.2f\n", i * delta_time, proj.x, proj.y, proj.vy);
        }
    }
    
    return 0;
}