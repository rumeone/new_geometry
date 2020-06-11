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

CTEST(circle, circle_perimeter_bad)
{
    // Given
    FILE* f = fopen("Print", "w");
    circle c;
    c.r = -1;
    // When
    float result = perimeter_circle(&c, f);
    // Then
    const float expected = -1;

    ASSERT_DBL_NEAR(expected, result);
}

CTEST(circle, area_circle)
{
    // Given
    FILE* f = fopen("Print", "w");
    circle c;
    c.r = 1;
    // When
    float result = area_circle(&c, f);
    // Then
    const float expected = M_PI;

    ASSERT_DBL_NEAR(expected, result);
}

CTEST(circle, area_circle_bad)
{
    // Given
    FILE* f = fopen("Print", "w");
    circle c;
    c.r = -1;
    // When
    float result = area_circle(&c, f);
    // Then
    const float expected = -1;

    ASSERT_DBL_NEAR(expected, result);
}

