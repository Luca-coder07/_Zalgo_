/*

Author : Luca RANDRIANIRINA (lucarandrianirina2507@gmail.com)

Vector2D Operations
Opérations de base sur les vecteurs 2D (addition, soustraction, normalisation, produit scalaire)

*/

typedef struct {
    float x;
    float y;
} Vector2D;

Vector2D vector2d_add(Vector2D a, Vector2D b) {
    Vector2D result = {a.x + b.x, a.y + b.y};
    return result;
}

Vector2D vector2d_sub(Vector2D a, Vector2D b) {
    Vector2D result = {a.x - b.x, a.y - b.y};
    return result;
}

Vector2D vector2d_scale(Vector2D v, float scale) {
    Vector2D result = {v.x * scale, v.y * scale};
    return result;
}

float vector2d_length(Vector2D v) {
    return sqrtf(v.x * v.x + v.y * v.y);
}

Vector2D vector2d_normalize(Vector2D v) {
    float length = vector2d_length(v);
    if (length == 0.0f)
        return (Vector2D){0.0f, 0.0f};
    return (Vector2D){v.x / length, v.y / length};
}

float vector2d_dot(Vector2D a, Vector2D b) {
    return a.x * b.x + a.y * b.y;
}

// Main Test
#include <stdio.h>
#include <math.h>
int main(void) {
    Vector2D a = {3.0f, 4.0f};
    Vector2D b = {1.0f, 2.0f};
    
    printf("Vector A: (%.1f, %.1f)\n", a.x, a.y);
    printf("Vector B: (%.1f, %.1f)\n", b.x, b.y);
    
    Vector2D sum = vector2d_add(a, b);
    printf("A + B = (%.1f, %.1f)\n", sum.x, sum.y);
    
    float dot = vector2d_dot(a, b);
    printf("A · B = %.1f\n", dot);
    
    Vector2D norm = vector2d_normalize(a);
    printf("Normalized A = (%.3f, %.3f)\n", norm.x, norm.y);
    
    return 0;
}