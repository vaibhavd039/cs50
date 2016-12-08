#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name;
    int length;
    // takes name as input
    name = GetString();
    // calculates length of string
    length = strlen(name);
    // converts first letter in capital case
    printf("%c",toupper(name[0]));
    for (int i = 0; i < length; i++)
    {
       // converts letter after space in capital case
        if (name[i] == ' ')
        {
            printf("%c",toupper(name[i + 1]));
        }
    }
    printf("\n");
}