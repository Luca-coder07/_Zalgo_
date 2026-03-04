/*

Author : Luca RANDRIANIRINA (lucarandrianirina2507@gmail.com)

Delta Time System
Calcul du temps écoulé entre frames pour des mouvements indépendants du framerate

*/

#include <stdio.h>
#include <time.h>

typedef struct {
    double last_time;
    double delta_time;
} DeltaTime;

void delta_time_init(DeltaTime *dt) {
    dt->last_time = (double)clock() / CLOCKS_PER_SEC;
    dt->delta_time = 0.0;
}

double delta_time_update(DeltaTime *dt) {
    double current_time = (double)clock() / CLOCKS_PER_SEC;
    dt->delta_time = current_time - dt->last_time;
    dt->last_time = current_time;
    return dt->delta_time;
}

// Main Test
int main(void) {
    DeltaTime dt;
    delta_time_init(&dt);
    
    for (int i = 0; i < 5; i++) {
        double dt_value = delta_time_update(&dt);
        printf("Delta time: %0.6f seconds\n", dt_value);
    }
    
    return 0;
}