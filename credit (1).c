#include <cs50.h>
#include <stdio.h>

int get_dn(long num);
bool is_valid(long num, int dn);
int main(void)
{
    long n = get_long("Number: ");
    int x = get_dn(n);
    if (is_valid(n, x))
    {
        if (x == 13)
        {
            printf("VISA\n");
        }
        else if (x == 15)
        {
            if (n / 10000000000000 == 34 || n / 10000000000000 == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (x == 16)
        {
            if (n / 1000000000000000 == 4)
            {
                printf("VISA\n");
            }
            else if (n / 100000000000000 == 51 || n / 100000000000000 == 52 ||
                     n / 100000000000000 == 53 || n / 100000000000000 == 54 ||
                     n / 100000000000000 == 55)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}
int get_dn(long num)
{
    int dn = 1;
    while (num / 10 != 0)
    {
        num = num / 10;
        dn++;
    }
    return dn;
}
bool is_valid(long num, int dn) // dn is number of digits
{
    int s1;
    int s2;
    int total;
    int d; // d is the digit to be doubled
    s1 = 0;
    s2 = 0;
    d = (num / 10) % 10;
    s2 = s2 + ((d * 2) / 10) + ((d * 2) % 10);
    long i = num;
    i = i / 1000;
    while (num != 0)
    {
        s1 += num % 10;
        num = num / 100;
    }
    while (i != 0)
    {
        d = i % 10;
        s2 = s2 + ((d * 2) / 10) + ((d * 2) % 10);
        i = i / 100;
    }
    total = s1 + s2;
    if (total % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
