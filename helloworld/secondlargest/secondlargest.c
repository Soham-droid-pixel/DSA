//Write a C program that takes n integers from the user, stores them in an array, and finds the second largest element in the array.//
#include<stdio.h>
int main()
{
    int n, i, first, second;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    first = second = -1;
    for(i = 0; i < n; i++)
    {
        if(arr[i] > first)
        {
            second = first;
            first = arr[i];
        }
        else if(arr[i] > second && arr[i] != first)
        {
            second = arr[i];
        }
    }
    if(second == -1)
        printf("There is no second largest element.\n");
    else
        printf("The second largest element is %d\n", second);
    
    return 0;
}
