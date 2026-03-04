/*

Author : Luca RANDRIANIRINA (lucarandrianirina2507@gmail.com)

Sinusoidal Interpolation (Smoothstep)
Interpolation avec accélération/décélération naturelle pour des transitions fluides

*/

#include <math.h>

float smoothstep(float pos_deb, float pos_fin, float factor) {
    if (factor < 0 || factor > 1)
        return pos_deb;
    
    // Smoothstep function: 3*t^2 - 2*t^3
    float t = factor;
    float smooth_t = t * t * (3 - 2 * t);
    
    return pos_deb + (pos_fin - pos_deb) * smooth_t;
}

// Main Test
#include <stdio.h>
int main(void) {
    for (float t = 0.0f; t <= 1.0f; t += 0.1f) {
        float result = smoothstep(0.0f, 10.0f, t);
        printf("Smoothstep(0, 10, %0.1f) = %0.2f\n", t, result);
    }
    return 0;
}