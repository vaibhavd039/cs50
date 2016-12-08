#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // variable used to store height of half pyramid
    int height;
    // takes positive number as input for height
    do
    {
        printf("Height: ");
        height = GetInt();
        if (height == 0)
        {
            return 0;
        }
    } while (height < 0 || height > 23);
    for (int i = 1; i <= height; i++)
    {   
        // prints white spaces
        for (int j = height - i; j > 0; j--)
        {
            printf(" ");
        }
        // prints "#"
        for (int j = i + 1; j > 0; j--)
        {
            printf("#");
        }
        printf("\n");
    } 
}