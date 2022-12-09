
#include <stdio.h>
int main()
{
    int n;
    printf("Enter size of array");
    scanf("%d", n);
    int B[n];
    int A[n];
    int k, i, j, l;
    i = 0;
    j = 0;
    printf("Enter the values");
    for (l = 0; l < n; l++)
    {
        scanf(% d, A[l]);
    }
    printf(Enter number of element you want to rotate);
    scanf(% d, k);

    while (i < k)
    {
        B[n - k + i] = A[i];

        i++;
    }
    j = n - k;

    while (i < n)
    {
        B[n - k - j] = A[i];
        i++;
        j--;
    }
    for (i = 0; i < n; i++)
    {
        printf(% d\n, B[i]);
    }
    return 0;
}