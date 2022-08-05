#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int main (int argc, char *argv[])
{
    // check that there is only one command-line argument
    if (argc != 1)
    {
        printf("Usage: ./Caesar_decipher\n");
        return 1;
    }

    // Define the key
    int k;
    int key = k;

    //Get input from the user
    char *Ciphertext = ("Ciphertext: ");

    //Print ciphertext
    printf("Deciphertext: ");

    //Obtain deciphertext
    for (int k = 0; k < 26; k++)
    {
        for (int i = 0; i < strlen(Ciphertext); i++)
        {
            if (isupper(Ciphertext[i]))
            {
                printf("%c\n","Deciphertext ", k);
                printf("%c", (((Ciphertext[i] - 65) - k) + 26) + 65);
            }
            else if (islower(Ciphertext[i]))
            {
                printf("%c\n","Deciphertext ", k);
                printf("%c", (((Ciphertext[i] - 97) - k) + 26) + 97);
            }
            else
            {
                printf("%c", Ciphertext[i]);
            }
        }
        printf("\n");
    }
    printf("\n");
}
// Decipher formula
// (L - K) + 26 OR (L - K) % 26