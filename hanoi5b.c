#include<stdio.h>
#include<conio.h>
int count=0;
void tower(int n, char source, char dest, char temp)
{
    if(n==1)
    {
        printf("move %d disc from %c to %c\n",n,source,dest);
        count++;
        return;
    }
    tower(n-1,source,temp,dest);
    printf("move %d disc from %c to %c\n",n,source,dest);
    count++;
    tower(n-1,temp,dest,source);
}
void main()
{
    int n;
    printf("enter the number of discs\n");
    scanf("%d",&n);
    tower(n,'S','D','T');
    printf("the total number of disc moves=%d",count);
}