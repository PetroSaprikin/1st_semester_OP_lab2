#include <stdio.h> // бібліотека для printf(), scanf(), getchar(), putchar()
#include <math.h> // для sqrt
#include <conio.h> // для getch()

// навіщо все робити окремо, якщо можна просто написати ф-цію
float number_check()
{
    float number = 0.f;
    char ch = 0;

    while (1)
    {
        if (scanf("%f%c", &number, &ch) != 2 || ch != '\n')
        {
            printf("Invalid input. Enter a real number: ");
            while ((ch = getchar()) != '\n' && ch != EOF);
            continue;
        }
        if (number < 0.001f || number > 1000.f)
        {
            printf("Invalid input. Must be between 0.001 and 1000: ");
            continue;
        }
        return number;
    }
}

// виводить тільки 0 або 1
int is_triangle(float a, float b, float c)
{
    if (a + b > c && a + c > b && b + c > a)
        return 1;

    printf("\nCannot build triangle, please try again\nPress any key to restart...");
    getch();
    return 0;
}

float triangle_perimeter(float a, float b, float c)
{
    return a + b + c;
}

float triangle_area(float a, float b, float c, float half_p)
{
    return sqrtf(half_p * (half_p - a) * (half_p - b) * (half_p - c));
}

float triangle_altitude(float side, float area)
{
   return (2.f * area) / side;
}

//sqrt вертає double
float triangle_bisector(float side_to_find, float side1, float side2, float half_p)
{
    return 2.f * sqrtf(side1 * side2 * half_p * (half_p - side_to_find)) / (side1 + side2);
}

float triangle_median(float side_to_find, float side1, float side2)
{
    return (sqrtf(2.f * side1 * side1 + 2.f * side2 * side2 - side_to_find * side_to_find)) / 2.f;
}

int main()
{
    while (1)
    {
        printf("Triangle Calculator\n");
        printf("Enter the lengths of sides a, b, and c (0.001 - 1000).\n");
        printf("The program will calculate:\n");
        printf("- Area\n");
        printf("- Perimeter\n");
        printf("- Altitudes to sides a, b, and c\n");
        printf("- Bisectors to sides a, b, and c\n");
        printf("- Medians to sides a, b, and c\n\n");

        printf("Enter size of 'a' side: ");
        float a = number_check(); // float достатньо для такої задачі
        printf("Enter size of 'b' side: ");
        float b = number_check();
        printf("Enter size of 'c' side: ");
        float c = number_check();

        if (!is_triangle(a, b, c))
            continue;
        printf("Triangle is created\n");
        const float p = triangle_perimeter(a, b, c);
        const float half_p = p/2.f;
        const float area = triangle_area(a, b, c, half_p);
        const float altitude_a = triangle_altitude(a, area);
        const float altitude_b = triangle_altitude(b, area);
        const float altitude_c = triangle_altitude(c, area);
        const float bisector_a = triangle_bisector(a, b, c, half_p);
        const float bisector_b = triangle_bisector(b, a, c, half_p);
        const float bisector_c = triangle_bisector(c, a, b, half_p);
        const float median_a = triangle_median(a, b, c);
        const float median_b = triangle_median(b, a, c);
        const float median_c = triangle_median(c, a, b);

        printf("Perimeter: %.5f\n", p);
        printf("\nArea: %.5f\n", area);

        printf("Altitude a: %.5f\n", altitude_a);
        printf("Altitude b: %.5f\n", altitude_b);
        printf("Altitude c: %.5f\n", altitude_c);

        printf("Bisector a: %.5f\n", bisector_a);
        printf("Bisector b: %.5f\n", bisector_b);
        printf("Bisector c: %.5f\n", bisector_c);

        printf("Median a: %.5f\n", median_a);
        printf("Median b: %.5f\n", median_b);
        printf("Median c: %.5f\n", median_c);

        printf("\nPress any key to restart...\n\n\n");
        getch();
    }
}
