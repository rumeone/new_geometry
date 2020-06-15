#include "point.h"
#include <math.h>
#include <stdio.h>

int inter_triangle_circle(triangle* t, circle* c, FILE* fp)
{
    float a, b, c;
    if (!t1 || !t2) {
        return -1;
    }
    if (c->r > 0) {
        a = sqrt(((t->T[1].x - c->C.x) * (t->T[1].x - c->C.x)) - ((t->T[1].y - c->C.y) * (t->T[1].y - c->C.y)));
        b = sqrt(((t->T[2].x - c->C.x) * (t->T[2].x - c->C.x)) - ((t->T[2].y - c->C.y) * (t->T[2].y - c->C.y)));
        c = sqrt(((t->T[3].x - c->C.x) * (t->T[3].x - c->C.x)) - ((t->T[3].y - c->C.y) * (t->T[3].y - c->C.y)));
        if ((a < c->r) || (b < c->r) || (c < c->r)) {
            printf("Окружности пересекаются");
            return 1;
        }
    }
    return 0;
}