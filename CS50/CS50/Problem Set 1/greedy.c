#include <cs50.h>
#include <stdio.h>
#include <math.h>
int main(void)
{
    int coins[] = {25, 10, 5, 1};
    float change;
    int iChange;
    int coinsNumber = 0;
    // to get a positive value from user
    do
    {
        printf("How much change is owed?: \n");
        change = GetFloat();
    } while (change < 0);
    // convert dollar into cents
    iChange = round(change * 100);
    // to calculate no. of coins
    int i;
    for(i = 0; i < 4; i++)
    {
        int count = 0;
        count = iChange / coins[i];
        iChange = iChange - ( count * coins[i] );
        coinsNumber = coinsNumber + count;
    }
    // printing no. of coins
    printf("%i\n", coinsNumber);
}
