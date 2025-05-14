#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Assignment
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Computation of score for each word
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Debug prints for scores (optional during testing)
    printf("Player 1 score: %d\n", score1);
    printf("Player 2 score: %d\n", score2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 Wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 Wins!\n");
    }
    else
    {
        printf("It's a Tie!\n");
    }
}

int compute_score(string word)
{
    // Score tracking
    int score = 0;

    // Computation of score for each character
    for (int i = 0, len = strlen(word); i < len; i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }

    return score;
}
