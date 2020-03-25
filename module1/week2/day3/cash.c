#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    float dollars;
    int list_coins[4] = {25, 10, 5, 1};
    int coins_total = 0;
    int coins;
    int cents;
    
    do
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);

    //round because float to integer transformation
    cents = round(dollars * 100);

    //coins per list element
    for (int i = 0; i <= 3; i++)
    {
        coins = floor(cents / list_coins[i]);
        coins_total += coins;
        cents -= coins * list_coins[i];
    }
    printf("%i\n", coins_total);
}