//Let’s write a program called caesar that enables you to encrypt messages using Caesar’s cipher.
//At the time the user executes the program, they should decide, by providing a command-line argument, 
// what the key should be in the secret message they’ll provide at runtime. We shouldn’t necessarily assume that the user’s key is going to be a number;
//though you may assume that, if it is a number, it will be a positive integer.

//Here are a few examples of how the program might work. For example, if the user inputs a key of 1 and a plaintext of HELLO: It's going to move each letter in 
//the plaintext one space away from their current positions in the alphabetical system. So "I" is after "H", "F" is after "E", and so on.

//$ ./caesar 1
//plaintext:  HELLO
//ciphertext: IFMMP
//Here’s how the program might work if the user provides a key of 13 and a plaintext of hello, world:

//$ ./caesar 13
//plaintext:  hello, world
//ciphertext: uryyb, jbeyq
//Notice that neither the comma nor the space were “shifted” by the cipher. Only rotate alphabetical characters!


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
