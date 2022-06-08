#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Enter a text: ");
    printf("%s\n", text);

    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
        {
            letters++;
        }

    }

    int words = 1;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ')
        {
            words++;
        }
    }

    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if ((text[i] == '?') || (text[i] == '.') || (text[i] == '!'))
        {
            sentences++;
        }
    }
    //printf("%i sentences\n", sentences);


    float calculation = ((0.0588 * letters / words * 100) - (0.296 * sentences / words * 100) - 15.8);
    int index = round(calculation);

    if (index < 1)
    {
        printf("%s\n", "Before Grade 1");
        return 0;
    }
    else if (index > 16)
    {
        printf("%s\n", "Grade 16+");
        return 0;
    }
    else
    {
        printf("Grade %i\n", index);
        return 0;
    }
}