#include <stdio.h>
int main()
{
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    if (a + b > c && a + c > b && b + c > a)
    {
        if (a == b && b == c)
        {
            printf("Equilateral_Triangle");
        }
        else if (a == b || b == c || a == c)
        {
            printf("Isosceles_Triangle");
        }
        else
        {
            if ((a * a) + (b * b) == (c * c) || (a * a) + (c * c) == (b * b) || (b * b) + (c * c) == (a * a))
            {
                printf("Right-angle_Triangle");
            }
            else
            {
                printf("Scalene_Triangle");
            }
        }
    }
    else
    {
        printf("This_Triangle_is_NOT_possible.");
    }
}