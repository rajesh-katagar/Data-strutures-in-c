#include <stdio.h>
#include <stdlib.h>

void egyptian_fraction(int numerator, int denominator) {
    if (numerator == 0 || denominator == 0)//invalid number
    {
        printf("Not a number");
        exit(0);
    }
    if (denominator % numerator == 0)
    {
        printf("1/%d\n", denominator / numerator);
        return;
    }
    int quotient = (denominator + numerator - 1) / numerator; // calculate ceiling using integer arithmetic
    printf("1/%d + ", quotient);
    int nr,dr;
    nr = numerator*quotient-denominator;
    dr = denominator*quotient;
    egyptian_fraction(nr,dr);
}

int main()
{
    int numerator,denominator;

    printf("Enter numerator and denominator\n");
    scanf("%d %d",&numerator,&denominator);

    printf("Egyptian Fraction for %d/%d:\n", numerator, denominator);
    egyptian_fraction(numerator, denominator);
    return 0;
}
