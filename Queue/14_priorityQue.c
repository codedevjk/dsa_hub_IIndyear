#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define MAXPR 5
#define MAXSIZE 5
int Q[MAXPR][MAXSIZE];
int front[MAXPR];
int rear[MAXPR];
void enqueue(int val, int prn)
{
    if (prn < 0 || prn >= MAXPR)
        return;
    if (rear[prn] == MAXSIZE - 1)
    {
        printf("\nOverflow");
        return;
    }
    if (front[prn] == -1)
    {
        front[prn]++;
    }
    rear[prn]++;
    Q[prn][rear[prn]] = val;
}
void display()
{
    int i, j;
    for (i = 0; i < MAXPR; i++)
    {
        for (j = 0; j < MAXSIZE; j++)
        {
            if (Q[i][j] == INT_MIN)
                printf("    ");
            else
                printf("%-2d ", Q[i][j]);
        }
        printf("\tFront[%d] = %2d, ", i, front[i]);
        printf("\tRear[%d] = %2d   ", i, rear[i]);
        printf("\n");
    }
}
int dequeue()
{
    int i, x;
    i = 0;
    while (i < MAXPR && front[i] == -1)
        i++;
    if (i == MAXPR)
    {
        printf("\nUnderflow");
        return INT_MIN;
    }
    x = Q[i][front[i]];
    Q[i][front[i]] = INT_MIN;
    if (front[i] == rear[i])
    {
        front[i] = -1;
        rear[i] = -1;
    }
    else
        front[i]++;
    return x;
}
int main()
{
    int i, j, x;
    for (i = 0; i < MAXPR; i++)
    {
        front[i] = -1;
        rear[i] = -1;
        for (j = 0; j < MAXSIZE; j++)
            Q[i][j] = INT_MIN;
    }
    enqueue(5, 1);
    enqueue(6, 2);
    enqueue(7, 1);
    enqueue(28, 4);
    enqueue(5, 2);
    enqueue(3, 2);
    enqueue(23, 0);
    display();
    x = dequeue();
    printf("\n%d is deleted\n", x);
    display();
    return 0;
}