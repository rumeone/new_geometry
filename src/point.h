#include <stdio.h>

typedef struct point {
  int x;
  int y;

 } point_t;

typedef struct circle {
  point_t C;
  int r;
} circle;

int enter_coordinate_circle(circle* c);
void print_circle(circle* c, FILE* f);
float perimeter_circle(circle* c, FILE* f);
float area_circle(circle* c, FILE* f);
int inter_cir(circle* c1, circle* c2, FILE* f);
