#include "../src/point.h"
#include "../thirdparty/ctest.h"
#include <math.h>

CTEST(circle, circle_perimeter)
{
    // Given
    FILE* f = fopen("Print", "w");
    circle c;
    c.r = 1;
    // When
    float result = perimeter_circle(&c, f);
    // Then
    const float expected = 2 * M_PI;

    ASSERT_DBL_NEAR(expected, result);
}