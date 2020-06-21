#include "point.h"
#include <math.h>
#include <stdio.h>

int main()
{

    FILE* f = fopen("Print", "w");
    circle c;
    circle c1;
    triangle t;
    
    printf("Первая окружность:\n");
    enter_coordinate_circle(&c);
    print_circle(&c, f);
    perimeter_circle(&c, f);
    area_circle(&c, f);
    printf("Вторая окружность:\n");
    enter_coordinate_circle(&c1);
    inter_cir(&c, &c1, f);

    enter_triangle_coordinate(&t);
    print_triangle(&t, f);
    check_triangle(&t, f);
    perimeter_triangle(&t, f);
    area_triangle(&t, f);
    inter_triangle_circle(&t, &c, f);

    fclose(f);
    printf("Для просмотра результата введите команду cat Print\n");

    return 0;
}
