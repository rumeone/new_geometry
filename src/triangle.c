#include "point.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void enter_triangle_coordinate(triangle* t)
{
    printf("\nВведите координаты треугольника\n");
    for (int i = 1; i <= 3; i++) {
        printf("Введите координаты вершины: %d\n", i);
        scanf("%d %d", &t->T[i].x, &t->T[i].y);
    }
    t->T[4].x = t->T[1].x;
    t->T[4].y = t->T[1].y;
}

int print_triangle(triangle* t, FILE* f)
{
    fprintf(f, "Triangle ( ");
    int c = check_triangle(t, f);
    if (c == 0) {
        for (int i = 1; i <= 3; i++) {
            fprintf(f, "(%d,%d)", t->T[i].x, t->T[i].y);
            if (i < 4) {
                fprintf(f, " ");
            }
        }
        fprintf(f, ")");
        for (int i = 1; i <= 3; ++i) {
            printf("(%d,%d)", t->T[i].x, t->T[i].y);
            if (i < 4) {
                printf(" ");
            }
        }
    } else {
        printf("Error: invalid triangle\n");
    }
    printf(")\n");
    return c;
}

int check_triangle(triangle* t, FILE* f)
{
    float a, b, c;

    a = sqrt((pow(t->T[2].x - t->T[1].x, 2) + pow(t->T[2].y - t->T[1].y, 2)));
    b = sqrt((pow(t->T[3].x - t->T[1].x, 2) + pow(t->T[3].y - t->T[1].y, 2)));
    c = sqrt((pow(t->T[3].x - t->T[2].x, 2) + pow(t->T[3].y - t->T[2].y, 2)));

    if ((a + b > c) || (a + c > b) || (c + b > a)) {
        return 0;
    } else {
        return -1;
    }
}

float perimeter_triangle(triangle* t, FILE* f)
{
    float a, b, c, P;
    a = sqrt((pow(t->T[2].x - t->T[1].x, 2) + pow(t->T[2].y - t->T[1].y, 2)));
    b = sqrt((pow(t->T[3].x - t->T[1].x, 2) + pow(t->T[3].y - t->T[1].y, 2)));
    c = sqrt((pow(t->T[3].x - t->T[2].x, 2) + pow(t->T[3].y - t->T[2].y, 2)));

    P = a + b + c;
    fprintf(f, "Perimeter triangle : %.2f\n", P);
    return P;
}

float area_triangle(triangle* t, FILE* f)
{
    float S;
    S = (fabs(((t->T[2].x) - (t->T[1].x)) * ((t->T[3].y) - (t->T[1].y)) - ((t->T[3].x) - (t->T[1].x)) * ((t->T[2].y) - (t->T[1].y)))) / 2;
    fprintf(f, "Area triangle: %.2f\n", S);

    return S;
}