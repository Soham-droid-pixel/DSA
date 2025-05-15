#include<stdio.h>
int main()
{
    int revnum=0,num;
    printf("Enter number");
    scanf("%d",&num);
    int originalnum=num;
    while(num>0)
    {
        int rem=num%10;
        revnum=revnum*10+rem;
        num=num/10;
    }
    if(revnum==originalnum)
    {
        printf("Entered no is palindrome");
    }
    else{
        printf("Entered no is not palindrome");
    }
    return 0;
}