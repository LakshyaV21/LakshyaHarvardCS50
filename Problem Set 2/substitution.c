#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// Function prototypes
bool validate_key(string key);
string encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    // Ensure the key is correct
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    string key = argv[1];

    // Validate the substitution key
    if (!validate_key(key))
    {
        printf("Key must contain 26 alphabetic characters.\n");
        return 1;
    }

    // Get plaintext from the user
    string plaintext = get_string("plaintext: ");

    // Encrypt the plaintext using the substitution key
    string ciphertext = encrypt(plaintext, key);

    // Output the ciphertext
    printf("ciphertext: %s\n", ciphertext);

    return 0;
}

// Function to validate the substitution key
bool validate_key(string key)
{
    // Check length
    if (strlen(key) != 26)
    {
        return false;
    }

    // Check for unique alphabetic characters
    bool seen[26] = {false};
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            return false;
        }

        int index = toupper(key[i]) - 'A';
        if (seen[index])
        {
            return false;
        }
        seen[index] = true;
    }
    return true;
}

// Function to encrypt the plaintext using the substitution key
string encrypt(string plaintext, string key)
{
    int length = strlen(plaintext);
    char *ciphertext = malloc((length + 1) * sizeof(char));

    for (int i = 0; i < length; i++)
    {
        char currentChar = plaintext[i];

        if (isupper(currentChar))
        {
            // Map uppercase character using the substitution key
            int index = currentChar - 'A';
            ciphertext[i] = toupper(key[index]);
        }
        else if (islower(currentChar))
        {
            // Map lowercase character using the substitution key
            int index = currentChar - 'a';
            ciphertext[i] = tolower(key[index]);
        }
        else
        {
            // Non-alphabetic characters remain unchanged
            ciphertext[i] = currentChar;
        }
    }
    ciphertext[length] = '\0';
    return ciphertext;
}
