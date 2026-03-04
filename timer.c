/*

Author : Luca RANDRIANIRINA (lucarandrianirina2507@gmail.com)

Reusable Timer System
Système de timer réutilisable pour les effets temporaires et les compte à rebours

*/

#include <time.h>

typedef struct {
    double duration;
    double start_time;
    int active;
} Timer;

void timer_init(Timer *timer, double duration) {
    timer->duration = duration;
    timer->active = 0;
}

void timer_start(Timer *timer) {
    timer->start_time = (double)clock() / CLOCKS_PER_SEC;
    timer->active = 1;
}

int timer_is_active(Timer *timer) {
    return timer->active;
}

int timer_has_finished(Timer *timer) {
    if (!timer->active)
        return 0;
    
    double current_time = (double)clock() / CLOCKS_PER_SEC;
    return (current_time - timer->start_time) >= timer->duration;
}

void timer_reset(Timer *timer) {
    timer->active = 0;
}

// Main Test
#include <stdio.h>
int main(void) {
    Timer timer;
    timer_init(&timer, 2.0);
    
    timer_start(&timer);
    printf("Timer started\n");
    
    while (timer_is_active(&timer)) {
        if (timer_has_finished(&timer)) {
            printf("Timer finished!\n");
            timer_reset(&timer);
        }
    }
    
    return 0;
}