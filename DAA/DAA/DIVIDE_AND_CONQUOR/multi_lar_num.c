#include <stdio.h>
#include <limits.h>
#include <math.h>
unsigned long long MLN(unsigned long long a, unsigned long long b)
{
    if (a < 10 || b < 10)
    {
        return a * b;
    }
    int a_len = log10(a) + 1, b_len = log10(b) + 1;
    int n = a_len > b_len ? a_len : b_len;

    unsigned long long a0, b0, a1, b1;
    a0 = a / pow(10, n / 2);
    b0 = b / pow(10, n / 2);
    a1 = a % (int)pow(10, n / 2);
    b1 = b % (int)pow(10, n / 2);
    unsigned long long c2, c1, c0;
    c2 = MLN(a0, b0); //* pow(10,n) ;
    c0 = MLN(a1, b1);

    c1 = (MLN((a0 + a1), (b0 + b1)) - c0 - c2); //*pow(10,n/2);
    if (n % 2 == 1)
    {
        n = n - 1;
        return c2 * pow(10, n) + c1 * pow(10, n / 2) + c0;
    }
    return c2 * pow(10, n) + c1 * pow(10, n / 2) + c0;
}
int main()
{

    unsigned long long a = 184312335, x;
    unsigned long long b = 18123343;
    // printf("%d",n);
    x = MLN(a, b);
    printf("%llu", x);
    printf("\n%llu", a * b);
    return 0;
}
//18446744073709551615