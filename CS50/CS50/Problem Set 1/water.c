#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int m = 0;
    printf("minutes:");
    m =GetInt();
    printf("bottles:%d\n",m*12);
}