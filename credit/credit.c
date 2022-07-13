#include <cs50.h>
#include <stdio.h>

int main(void)
{
    long long cardNumber = 0;
    do
    {
        cardNumber = get_long_long("Number: ");
    }
    // The card number entered must be greater than zero. If the user enters a negative credit card number, 
    // they will be prompted again to enter a valid credit card number.
    while (cardNumber <= 0); 

    // For the following calculations, Luhn's Algorithm was used to determine if the entered credit card number is syntactically valid
    int card1, card2, card3, card4, card5, card6, card7, card8;
    card1 = ((cardNumber % 100) / 10) * 2;
    card2 = ((cardNumber % 10000) / 1000) * 2;
    card3 = ((cardNumber % 1000000) / 100000) * 2;
    card4 = ((cardNumber % 100000000) / 10000000) * 2;
    card5 = ((cardNumber % 10000000000) / 1000000000) * 2;
    card6 = ((cardNumber % 1000000000000) / 100000000000) * 2;
    card7 = ((cardNumber % 100000000000000) / 10000000000000) * 2;
    card8 = ((cardNumber % 10000000000000000) / 1000000000000000) * 2;

    // Working
    // 1034 mod 100 = 34
    // 34/10 = 3

    // 1034 mod 10000 = 1034
    // 1034 / 1000 = 1

    // 4003600000000014 mod 100 = 14
    // 14 / 10 = 1

    // 4003600000000014 mod 10000 = 14
    // 14 / 1000 = 0


    card1 = (card1 % 100 / 10) + (card1 % 10);
    card2 = (card2 % 100 / 10) + (card2 % 10);
    card3 = (card3 % 100 / 10) + (card3 % 10);
    card4 = (card4 % 100 / 10) + (card4 % 10);
    card5 = (card5 % 100 / 10) + (card5 % 10);
    card6 = (card6 % 100 / 10) + (card6 % 10);
    card7 = (card7 % 100 / 10) + (card7 % 10);
    card8 = (card8 % 100 / 10) + (card8 % 10);

    int sum1 = card1 + card2 + card3 + card4 + card5 + card6 + card7 +card8;

    //Now the digits that were not multiplied by 2 need to be identified
    int card9, card10, card11, card12, card13, card14, card15, card16;
    card9 = ((cardNumber % 10) / 1);
    card10 = ((cardNumber % 1000) / 100);
    card11 = ((cardNumber % 100000) / 10000);
    card12 = ((cardNumber % 10000000) / 1000000);
    card13 = ((cardNumber % 1000000000) / 100000000);
    card14 = ((cardNumber % 100000000000) / 10000000000);
    card15 = ((cardNumber % 10000000000000) / 1000000000000);
    card16 = ((cardNumber % 1000000000000000) / 100000000000000);

    int sum2 = card9 + card10 + card11 + card12 + card13 + card14 + card15 + card16;

    int sum3 = sum1 + sum2;
    //Determine whether the card number is valid or invalid
    int length = 0;
    long visa = cardNumber;
    long amex = cardNumber;
    long master = cardNumber;
    if ((sum3 % 10) != 0)
    {
        printf("%s\n", "INVALID");
        return 0;
    }

    //Now identify whether the credit card is a VISA, Master Card or American Express(Amex)
    while (cardNumber > 0)
    {
        cardNumber = cardNumber / 10;
        length++;
    }

    //Identify is the card is a VISA
    while (visa >= 10)
    {
        visa /= 10;
    }
    if (visa == 4 && (length == 13 || length == 16))
    {
        printf("%s\n", "VISA");
        return 0;
    }

    //Iidentify if the card is an AMEX
    while (amex >= 10000000000000)
    {
        amex /= 10000000000000;
    }
    if (length == 15 && (amex == 34 || amex == 37))
    {
        printf("%s\n", "AMEX");
        return 0;
    }

    //Identify is the card is a Mastercard
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