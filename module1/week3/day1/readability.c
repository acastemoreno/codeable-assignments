#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    string name = get_string("Text: ");
    int count_let = count_letters(name);
    int count_w = count_words(name);
    int count_s = count_sentences(name);
    float l;
    l = 100 * (float)count_let / (float)count_w;
    float s;
    s = 100 * (float)count_s / (float)count_w;
    int index = round(0.0588 * l - 0.296 * s - 15.8);

    if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }

}

int count_letters(string text)
{
    int length_char;
    int cl = 0;
    length_char = strlen(text);
    for (int i = 0; i < length_char; i++)
    {
        if ((text[i] >= 'A' && text[i] <= 'Z') || (text[i] >= 'a' && text[i] <= 'z'))
        {
            cl += 1;
        }
    }

    return cl;
}

int count_words(string text)
{
    int length_char;
    int cw = 0;
    length_char = strlen(text);
    for (int i = 0; i < length_char; i++)
    {
        if (text[i] == ' ')
        {
            cw += 1;
        }
    }

    return cw + 1;
}


int count_sentences(string text)
{
    int length_char;
    int cs = 0;
    length_char = strlen(text);
    for (int i = 0; i < length_char; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            cs += 1;
        }
    }

    return cs;
}

