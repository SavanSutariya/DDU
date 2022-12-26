// T Flip Flop using C
// Created: 2016-02-01

#include <stdio.h>
#include <stdlib.h>
int main()
{
    int t;
    int q = 0;
    int qn = 1;
    printf("Enter the number of inputs: ");
    scanf("%d", &t);
    int input[t];
    printf("Enter the inputs: ");
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &input[i]);
    }
    for (int i = 0; i < t; i++)
    {
        if (input[i] == 1)
        {
            qn = !qn;
            q = !q;
        }
        printf("Q%d = %d Qn%d = %d -- %d \n", i, q, i, qn, input[i]);
    }
    return 0;
}
