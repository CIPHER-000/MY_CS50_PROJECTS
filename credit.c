#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    long card;
    do
    {
        card = get_long("Enter a card number: "); // card number must be greater than zero.
    }
    while (card < 0);

    //
    long card[8];
    {
    card[0]= ((card % 100) / 10 * 2);
    card[1] = ((card % 10000) / 1000 * 2);
    card[2] = ((card % 1000000) / 100000 * 2);
    card[3] = ((card % 100000000) / 10000000 * 2);
    card[4] = ((card % 10000000000) / 1000000000 * 2);
    card[5] = ((card % 1000000000000) / 100000000000 * 2);
    card[6] = ((card % 100000000000000) / 10000000000000 * 2);
    card[7] = ((card % 10000000000000000) / 1000000000000000 * 2);

    card[0] = (card[0] % 100 / 10) + (card[0] % 10);
    card[1] = (card[1] % 100 / 10) + (card[1] % 10);
    card[2] = (card[2] % 100 / 10) + (card[2] % 10);
    card[3] = (card[3] % 100 / 10) + (card[3] % 10);
    card[4] = (card[4] % 100 / 10) + (card[4] % 10);
    card[5] = (card[5] % 100 / 10) + (card[5] % 10);
    card[6] = (card[6] % 100 / 10) + (card[6] % 10);
    card[7] = (card[7] % 100 / 10) + (card[7] % 10);
    }
    
    long sum1 = card[0] + card[1] + card[2] + card[3] + card[4] + card[5] + card[6] + card[7];
   

    int card9, card10, card11, card12, card13, card14, card15, card16;
    card9 = (card % 10);
    card10 = (card % 1000 / 100);
    card11 = (card % 100000 / 10000);
    card12 = (card % 10000000 / 1000000);
    card13 = (card % 1000000000 / 100000000);
    card14 = (card % 100000000000 / 10000000000);
    card15 = (card % 10000000000000 / 1000000000000);
    card16 = (card % 1000000000000000 / 100000000000000);

    int sum2 = card9 + card10 + card11 + card12 + card13 + card14 + card15 + card16;
    int sum3 = sum1 + sum2;
    printf("%i\n ", sum3);

    int length = 0;
    long visa = card;
    long amex = card;
    long master = card;

    if ((sum3 % 10) != 0)
    {
        printf("%s\n", "INVALID");
        return 0;
    }

    while (card > 0)
    {
        card = card / 10;
        length++;
    }

    while (visa >= 10)
    {
        visa /= 10;
    }
    if (visa == 4 && (length == 13 || length == 16))
    {
        printf("%s\n", "VISA");
        return 0;
    }

    while (amex >= 10000000000000)
    {
        amex /= 10000000000000;
    }
    if (length == 15 && (amex == 34 || amex == 37))
    {
        printf("%s\n", "AMEX");
        return 0;
    }

    while (master >= 100000000000000)
    {
        master /= 100000000000000;
    }
    if (length == 16 && (master == 51 || master == 52 || master == 53 || master == 54 || master == 55))
    {
        printf("%s\n", "MASTERCARD");
        return 0;
    }
    else
    {
        printf("%s\n", "INVALID");
        return 0;
    }
}