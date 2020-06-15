#include "point.h"
#include <math.h>
#include <stdio.h>

int inter_triangle_circle(triangle* t, circle* c, FILE* f)
{
    float distance_one, distance_two, distance_three;
    if (!t || !c) {
        return -1;
    }
    if (c->r > 0) {
        distance_one = sqrt(((t->T[1].x - c->C.x) * (t->T[1].x - c->C.x)) - ((t->T[1].y - c->C.y) * (t->T[1].y - c->C.y)));
        distance_two = sqrt(((t->T[2].x - c->C.x) * (t->T[2].x - c->C.x)) - ((t->T[2].y - c->C.y) * (t->T[2].y - c->C.y)));
        distance_three = sqrt(((t->T[3].x - c->C.x) * (t->T[3].x - c->C.x)) - ((t->T[3].y - c->C.y) * (t->T[3].y - c->C.y)));
        if ((distance_one < c->r) || (distance_two < c->r) || (distance_three < c->r)) {
            printf("Окружность и тругольник пересекаются\n");
            return 1;
        }
    }
    printf("Окружность и треугольник не пересекаются\n");
    return 0;
}