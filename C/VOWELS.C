#include <stdio.h>
#include <string.h>

int main()
{
    char s[30];
    int i;

    printf("Enter string: ");
    fgets(s, sizeof(s), stdin);

    /* remove newline if present */
    s[strcspn(s, "\n")] = '\0';

    for (i = 0; i < strlen(s); i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
            s[i] == 'o' || s[i] == 'u' ||
            s[i] == 'A' || s[i] == 'E' || s[i] == 'I' ||
            s[i] == 'O' || s[i] == 'U')
        {
            printf("%c is a Vowel\n", s[i]);
        }
        else
        {
            printf("%c is a Consonant\n", s[i]);
        }
    }

    return 0;
}
