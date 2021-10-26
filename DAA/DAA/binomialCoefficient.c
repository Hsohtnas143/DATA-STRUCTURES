#include <stdio.h>
int choose(int n, int k)
{

    if (k == 0 || n == k)
    {
        return 1;
    }
    else if(n<k)
    {
        return 0;
    }
    else
    {
        return choose(n - 1, k - 1) + choose(n - 1, k);
    }

    //return 1;
}
int main()
{
    int n = 7;
    int k = 5;
    int val = choose(n, k);
    printf("%d", val);
    return 0;
}