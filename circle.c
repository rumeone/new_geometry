#include "point.h"
#include <math.h>
#include <stdio.h>


int enter_coordinate_circle(circle* c)
{
    printf("Введите координаты окружности: ");
    scanf("%d %d", &c->C.x, &c->C.y);
    printf("Введите радиус окружности: ");
    scanf("%d", &c->r);
    if( c->r < 0) {
        printf("Неккоректный радиус\n");
        return -1;
    }
    return 0;
}

void print_circle(circle* c, FILE* f)
{
    fprintf(f, "Circle((%d:%d),  %d)\n", c->C.x, c->C.y, c->r);
    printf("Circle((%d;%d), R=%d)\n", c->C.x, c->C.y, c->r);
}

float perimeter_circle(circle* c, FILE* f)
{
    if (c->r > 0) {
        float P = 2 * M_PI * c->r;
        printf("Circle perimeter = %.2f\n", P);
        fprintf(f, "Circle perimeter = %.2f\n", P);
        return P;
    }
    return -1;
}

float area_circle(circle* c, FILE* f)
{
    if (c->r > 0) {
        float S = M_PI * c->r * c->r;
        printf("Circle area = %.2f\n", S);
        fprintf(f, "Circle area = %.2f\n", S);
        return S;
    }
    return -1;
}

