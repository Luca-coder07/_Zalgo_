/*

Author : Luca RANDRIANIRINA (lucarandrianirina2507@gmail.com)

Easing Functions
Fonctions d'accélération (quadratique, cubique, exponentiel) pour les transitions

*/

#include <math.h>

// Linear (already implemented)
float linear(float t) {
    return t;
}

// Quadratic easing functions
float ease_in_quad(float t) {
    return t * t;
}

float ease_out_quad(float t) {
    return 1 - (1 - t) * (1 - t);
}

float ease_in_out_quad(float t) {
    if (t < 0.5f) {
        return 2 * t * t;
    } else {
        return 1 - pow(-2 * t + 2, 2) / 2;
    }
}

// Cubic easing functions
float ease_in_cubic(float t) {
    return t * t * t;
}

float ease_out_cubic(float t) {
    return 1 - pow(1 - t, 3);
}

float ease_in_out_cubic(float t) {
    if (t < 0.5f) {
        return 4 * t * t * t;
    } else {
        return 1 - pow(-2 * t + 2, 3) / 2;
    }
}

// Exponential easing functions
float ease_in_expo(float t) {
    return t == 0.0f ? 0.0f : pow(2, 10 * t - 10);
}

float ease_out_expo(float t) {
    return t == 1.0f ? 1.0f : 1 - pow(2, -10 * t);
}

float ease_in_out_expo(float t) {
    if (t == 0.0f) return 0.0f;
    if (t == 1.0f) return 1.0f;
    if (t < 0.5f) return pow(2, 20 * t - 10) / 2;
    return (2 - pow(2, -20 * t + 10)) / 2;
}

// Main Test
#include <stdio.h>
int main(void) {
    printf("Easing functions demonstration:\n");
    printf("t    Linear  QuadIn   QuadOut  QuadInOut CubicIn   CubicOut  CubicInOut ExpIn    ExpOut   ExpInOut\n");
    printf("----------------------------------------------------------------------------------------------------------------\n");
    
    for (float t = 0.0f; t <= 1.0f; t += 0.1f) {
        printf("%.1f    %.2f    %.2f      %.2f      %.2f      %.2f      %.2f      %.2f      %.2f      %.2f      %.2f\n",
               t,
               linear(t),
               ease_in_quad(t),
               ease_out_quad(t),
               ease_in_out_quad(t),
               ease_in_cubic(t),
               ease_out_cubic(t),
               ease_in_out_cubic(t),
               ease_in_expo(t),
               ease_out_expo(t),
               ease_in_out_expo(t));
    }
    
    return 0;
}