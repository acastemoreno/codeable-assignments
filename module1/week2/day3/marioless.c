#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    //Print for each row
    for (int i = 1; i <= height; i++)
    {
        //Print space
        for (int s = 1; s <= height - i; s++)
        {
            printf(" ");
        }
        //Print #
        for (int j = 1; j <= i; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}
