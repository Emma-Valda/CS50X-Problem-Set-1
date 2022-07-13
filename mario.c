#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare integer variables called "height", "row", "column" and "space"
    int height, row, column, space;
    // Allow the user to decide just how tall the pyramids should be by first prompting them for a positive integer between 1 and 8, inclusive.
    do
    {
        height = get_int("Enter height here: ");
    }
    while (height < 1 || height > 8);

    //When row is less than height, print a new row. ++ increases the value of the variable by 1.
    for (row = 0; row < height; row++)
    {
        //Workings: space = height - row - 1, this is the spaces along the left-hand side of the right-aligned half of the pyramid
        for (space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        // Print the "#" that form the pyramid under the constant condition that column <= row, this forms the left half of the pyramid
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        // Hard code the double spaces between the two halves of the pyramid
        printf("  ");

        // Print the "#" that form the pyramid under the constant condition that column <= row, this forms the right half of the pyramid
        for (column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("\n");
    }

}
