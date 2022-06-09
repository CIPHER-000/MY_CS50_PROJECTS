//Now this one is one of my favorites..

//In many cases, a human expert might read a book and make a decision on the grade (i.e., year in school) for which they think the book is most
//appropriate. But an algorithm could likely figure that out too!

//So what sorts of traits are characteristic of higher reading levels? Well, longer words probably correlate with higher reading levels.
// Likewise, longer sentences probably correlate with higher reading levels, too.

//A number of “readability tests” have been developed over the years that define formulas for computing the reading level of a text. 
// One such readability test is the Coleman-Liau index. The Coleman-Liau index of a text is designed to output that (U.S.) grade level 
//that is needed to understand some text. The formula is: (index = 0.0588 * L - 0.296 * S - 15.8),
//where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.

//So this is a program called readability that takes a text and determines its reading level. For example, if user types in a line of text from Dr. Seuss,
//the program should behave as follows:

//$ ./readability
//Text: Congratulations! Today is your day. You're off to Great Places! You're off and away!
//Grade 3

// So, the more complex a sentance is, the hgher the grade and vice-versa.


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
