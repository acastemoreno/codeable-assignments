#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string eptr;
    int k = strtol(argv[1], &eptr, 10);
    if (strcmp(eptr, "") != 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    string text = get_string("plaintext: ");
    int length_char;
    length_char = strlen(text);
    for (int i = 0; i < length_char; i++)
    {
        if (text[i] >= 'a' && text[i] <= 'z')
        {
            text[i] = (((text[i] - 'a') + k) % 26) + 'a';
        }
        else if (text[i] >= 'A' && text[i] <= 'Z')
        {
            text[i] = (((text[i] - 'A') + k) % 26) + 'A';
        }
    }

    printf("ciphertext: %s\n", text);

}