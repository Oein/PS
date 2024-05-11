#include <stdio.h>

int x(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    if (n % 2 == 0)
    {
        return (n == 2);
    }
    for (int i = 3; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int n, temp;

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &temp);
    }

    if (x(n) == 1)
    {
        printf("Yes");
    }
    else
    {
        printf("No");
    }

    return 0;
}