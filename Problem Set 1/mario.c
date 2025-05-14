#include <cs50.h>
#include <stdio.h>
void print_pyramid(int height);

int main(void)
{
    int height;

    // Ask User to Give Height Integer
    do
    {
        height = get_int("Height:");
    }
    while (height < 1 || height > 8);

    print_pyramid(height);

    return 0;
}

void print_pyramid(int height)
{
    for (int row = 0; row < height; row++)
    {
        // Printing the spaces for the pyramid
        for (int space = 0; space < height - row - 1; space++)
        {
            printf(" ");
        }

        // Printing the left hashes
        for (int hash = 0; hash <= row; hash++) 
        {
            printf("#");
        }
        // Print the gap

        {
            printf("  ");
        }

        // Print the right hashes
        for (int hash = 0; hash <= row; hash++)
        {
            printf("#");
        }

        // Going to the next row
        printf("\n");
    }
}
