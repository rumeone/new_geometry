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

CTEST(circle, inter) {
	// Given
	FILE* f = fopen("Print", "w");

	circle c1;
	circle c2;

	c1.r = 1;
	c2.r = 2;

    c1.C.x = 1;
    c1.C.y= 1;
    c2.C.x = 2;
    c2.C.y = 2;

	// When
	int result = inter_cir(&c1, &c2, f);
	// Then 
	const int expected = 1;

	ASSERT_EQUAL(expected, result);
}

CTEST(circle, inter_bad_1s) {
	// Given
	FILE* f = fopen("Print", "w");

	circle c1;
	circle c2;

	c1.r = -1;
	c2.r = 2;

    c1.C.x = 1;
    c1.C.y= 1;
    c2.C.x = 2;
    c2.C.y = 2;

	// When
	int result = inter_cir(&c1, &c2, f);
	// Then 
	const int expected = -1;

	ASSERT_EQUAL(expected, result);
}

CTEST(circle, inter_bad_2) {
	// Given
	FILE* f = fopen("Print", "w");

	circle c1;
	circle c2;

	c1.r = 1;
	c2.r = -2;

    c1.C.x = 1;
    c1.C.y= 1;
    c2.C.x = 2;
    c2.C.y = 2;

	// When
	int result = inter_cir(&c1, &c2, f);
	// Then 
	const int expected = -1;

	ASSERT_EQUAL(expected, result);
}
