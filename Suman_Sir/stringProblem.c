/**
 * Write a program that will accept any sentence (Max length of 200 characters). 
 * If input is more than 200 characters system will prompt a warning to user. 
 * Thereafter it will accept another string and find the occurrence of the position of the second string 
 * in the first sentence. 
 * The second string length is also of max 200 characters.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    char *sentence1 = malloc(sizeof(char) * 200);
    char *sentence2 = malloc(sizeof(char) * 200);

    printf("Enter a sentence1 ( max length 200 ): \n");
    scanf("%[^\n]%*c", sentence1);
    if (strlen(sentence1) > 200)
    {
        printf("\nWarning: Input is more than 200 characters. Only the first 200 characters will be taken.\n");
        sentence1[200] = '\0';
    }
    printf("Enter a sentence2 ( max length 200 ): \n");
    scanf("%[^\n]%*c", sentence2);
    if (strlen(sentence2) > 200)
    {
        printf("\nWarning: Input is more than 200 characters. Only the first 200 characters will be taken.\n");
        sentence2[200] = '\0';
    }
    while (strstr(sentence1, sentence2) != NULL)
    {
        int pos = strstr(sentence1, sentence2) - sentence1;
        printf("Position %d\n", pos + 1);
        for (int j = 0; j < strlen(sentence2); j++)
        {
            sentence1[pos + j] = '*';
        }
    }
}