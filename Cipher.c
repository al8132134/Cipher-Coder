#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

bool check_char(string key);
string cipher(string input, string key);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    bool check = check_char(argv[1]);
    if (check == true)
    {
        string input = get_string("plaintext: ");
        string output = cipher(input, argv[1]);
        printf("ciphertext: %s\n", output);
    }
    else if (check == false)
    {
        return 1;
    }
}

bool check_char(string key)
{
    int length;
    length = strlen(key);
    char seen[26];
    if (length != 26)
    {
        printf("Key must contain 26 characters");
        return false;
    }
    for (int i = 0; i < length; i++)
    {
        if (isalpha(key[i]) == false)
        {
            printf("Error: Invalid character in key");
            return false;
        }

        for (int j = i + 1; j < strlen(key) + 1; j++)
        {
            if ((key[j] == toupper(key[i])) || (key[j] == tolower(key[i])))
            {
                printf("Error: Key must have all unique characters");
                return false;
            }
        }
    }
    return true;
}

string cipher(string input, string key)
{
    string ciphertext = input;
    for (int i = 0; i < strlen(input); i++)
    {
        if (isupper(input[i]))
        {
            int x = input[i] - 65;
            ciphertext[i] = toupper(key[x]);
        }
        else if (islower(input[i]))
        {
            int x = input[i] - 97;
            ciphertext[i] = tolower(key[x]);
        }
    }
    return ciphertext;
}