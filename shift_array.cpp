#include<stdio.h>
/*
    [1, 2, 3, 4, 5] --2--> [3, 4, 5, 1, 2]
    [1, 2, 3, 4, 5] --4--> [5, 1, 2, 3, 4]
    
*/
void shift(int A[], int n, int k)
{
    int i, first;
    while(k--)
    {
        first = A[0];
        for(i = 1; i<n; i++)
            A[i-1] = A[i];
        A[i-1] = first;
    }
}
int main(void)
{
    int A[7] = {2,4,5,1,3,7,6};
    shift(A, 7, 4);
    for(int i = 0; i<7; i++)
        printf("%d ", A[i]);
}
