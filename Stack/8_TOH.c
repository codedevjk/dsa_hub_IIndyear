#include <stdio.h>
void toh(int n,char from,char to,char aux)
{
    if(n==0)
    {
        return ;
    }
    toh(n-1,from,aux,to);
    printf("\nMove disk %d from rod %c to rod %c",n,from,to);
    toh(n-1,aux,to,from);
}
int main()
{
    int n=5;
    toh(n,'A','B','C');
    return 0;
}