#include <stdio.h>
//1 * 2 * 3 * 4 * 5 * 6 * 7 * 8 * 9 * 10
//recursive function
// int fact(int n)
// {
//     if (n == 0)
//         return 1;
//     else{
//         int a = n * fact(n - 1);
//         printf("calling fact(%d) => %d", n - 1,a);
//         return a;
//     }
// }

// 10 * 9 * 8 * 7 * 6 * 5 * 4 * 3 * 2 * 1
// recursive function
int fact(int n,int tmp)
{
    printf("%d * ", tmp);
    if (n+1 != tmp)
        return tmp * fact(n,tmp + 1);
    else
        return 1;
}

int main()
{
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    printf("Factorial of %d is %d ", n, fact(n,1));
    return 0;
}