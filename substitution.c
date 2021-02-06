#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <cs50.h>

// Prototypes.
void cipher_printer(string key);
int indexer(char);

int main(int argc, string argv[2])
// Validates argc and argv or prints error and returns 1.
// Gives key a name, makes sure only the file name and one
// command line argument are entered, and makes sure the
// key is exactly 26 unique letters long.

// If key is good, run it through cipher_printer.
{
    string key = argv[1];
 
    if (argc == 2 && strlen(key) == 26)
    {
        for (int i = 0; i < 26; i++)
        {
            if (isalpha(key[i]))
            {   
                // For the dupe check.
                for (int j = i + 1; j < 26; j++)
                {
                    if (key[j] != key[i])
                    {
                        continue;
                    }
                    else
                    {
                        printf("Key must be 26 unique letters\n");
                        return 1;
                    }
                }
            }
            else
            {
                printf("Key must be letters only.\n");
                return 1;
            }
        }
    }
    else
    {
        printf("Only one command line argument.\nKey must be 26 unique characters.\n");
        return 1;
    }

    cipher_printer(key);

    return 0;
}

void cipher_printer(string key)
// Gets text for and decides which chars are letters to
// be enciphered.  Runs indexer to see which of the key
// chars are to be used in place of plain chars.

// key_i holds index of plain letter from alphabet to use
// in matching key letter at same index.

// Prints ciphertext right from the function.
{
    string plaintext = get_string("plaintext: ");
    int i = 0, len = strlen(plaintext), key_i;

    printf("ciphertext: ");

    for (; i < len; i++)
    {
        if (tolower(plaintext[i]) >= 'a' && tolower(plaintext[i]) <= 'z')
        {
            key_i = indexer(tolower(plaintext[i]));
            if (isupper(plaintext[i]))
            {
                printf("%c", toupper(key[key_i]));
            }
            else
            {
                printf("%c", tolower(key[key_i]));
            }
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }

    printf("\n");
}

int indexer(char c)
// Figures out where, in standard sequence, letters
// in plaintext are, for matching against key letter
// at same index.
{
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    int index = 0, i = 0;

    for (; ; i++)
    {
        if (c == alphabet[i])
        {
            index = i;
            break;
        }
    }

    return index;
}