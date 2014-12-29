#include <stdio.h>
#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])

{

//Check command line arguments (tests: > 1 cmd-line arguments && < 1 cmd-line arguments) 

    if (argc != 2)
    {
        printf("ERROR! Only single command line argument accepted. Please restart.\n");
        return 1;
    }

//Convert command line number (string) to an int
    
    int key = atoi(argv[1]);

//Test for non-negative integer
    
    if (key < 0)
    {
        printf("ERROR! Only non-negative integers accepted. Please restart.\n");
        return 1; 
    }  

// Upon key confirmation, get string (message)

    string message = GetString();       

//Rotate string by key (Note: non-alhphabetic chars remain unchanged, case of chars retained)

    for (int i = 0, n = strlen(message); i < n; i++)
    {
        
        if (!isalpha(message[i])) //Check if char is nonp-alphabetic (ie, spaces, numbers, symbols)
        {
            printf("%c",message[i]);
        }
        else if (isalpha(message[i])) //Check if char is alphabtic
        { 
           if(islower(message[i])) //Check if alphabetic char is lowercase, if so, cipher.
            {
                char cipherletter = (((message[i] - 'a') + key) % 26) + 'a';
                printf("%c",cipherletter);
            }    
            else if (isupper(message[i])) //Check if alphabetic char is uppercase
            {
                char cipherletter = (((message[i] - 'A') + key) % 26) + 'A';
                printf("%c",cipherletter);
            }
        }
    }

    printf("\n");
    
return 0;

}
