#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    // check that there is only one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //Define the key
    string key = argv[1];

    //check that input is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n ");
            return 1;
        }
    }
    printf("Success\n%s\n", key);

    //Getting text from user
    string Plaintext = get_string("Plaintext: ");

    //convert key to integer
    int k = atoi(key);
    printf("Ciphertext: ");

    //Obtain Ciphertext
    for (int i = 0; i < strlen(Plaintext); i++)
    {
        if (isupper(Plaintext[i]))
        {
            printf("%c", (((Plaintext[i] - 65) + k) % 26) + 65);
        }
        else if (islower(Plaintext[i]))
        {
            printf("%c", (((Plaintext[i] - 97) + k) % 26) + 97);
        }
        else
        {
            printf("%c", Plaintext[i]);
        }
    }
    printf("\n");
}