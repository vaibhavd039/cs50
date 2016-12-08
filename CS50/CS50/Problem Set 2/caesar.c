#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    string plainText;
    // checks for no. of command line arguments
    if (argc != 2)
    {
        printf ("No command line argument passed \n");
        return 1; 
    }
    // converts string key into number
    int key = atoi(argv[1]);
    // to get plain text from user
    plainText = GetString();
    // adds key to the plain text
    for(int i = 0, n = strlen(plainText); i < n; i++)
    {
        // condition for capital letters
        if (plainText[i] >= 'A' && plainText[i] <= 'Z')
        {
            plainText[i] = (((plainText[i] - 65) + key) % 26) + 65;
        }
        else if (plainText[i] >= 'a' && plainText[i] <= 'z')
        {
            // condition for small letters
            plainText[i] = (((plainText[i] - 97) + key) % 26) + 97;
        }
    }
    printf("%s",plainText);
    printf("\n");
    return 0;
}