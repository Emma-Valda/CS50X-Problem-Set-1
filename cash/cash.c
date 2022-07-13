#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    // Prompt the user for the number of cents that a customer is owed and then prints the smallest number of coins with which that change can be made. 
    int cents;
    do
    {
        cents = get_int("Cents Owed: ");
    }
    // If the user enters a negative number, prompt the user again to input a valid amount (a positive amount)
    while (cents < 0);
    return cents;
}

// The calulate_quarters function calculates (and returns as an int) how many quarters a customer should be given if they’re owed some number of cents. 
// For instance, if cents is 25, then calculate_quarters should return 1.
// If cents is 50 or 74 (or anything in between), then calculate_quarters should return 2. And so forth.
int calculate_quarters(int cents)
{

    int quarters = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        quarters++;     //Add a quarter everytime cents is >= 25
    }
    return quarters;
}

// Similar functionality to the above function, for the case of dimes (which is 10c)
int calculate_dimes(int cents)
{

    int dimes = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        dimes++;    //Add a dime everytime dimes is >= 10
    }
    return dimes;
}

// Similar functionality to the above function, for the case of nickles (which is 5c)
int calculate_nickels(int cents)
{

    int nickles = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        nickles++;
    }
    return nickles;
}

// Similar functionality to the above function, for the case of pennies (which is 1c)
int calculate_pennies(int cents)
{

    int pennies = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        pennies++;
    }
    return pennies;
}
