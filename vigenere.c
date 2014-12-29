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

//Test for non-alphabetical characters
    
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i])) 
        {
            printf("Error! Keyword can contain ONLY alphabetical characters. Please restart.\n"); 
            return 1;
        }
    } 

//At this stage we have a keyword, made of only alphabetical characters    
// Upon key confirmation, get message(argv[2])
    
    string message = GetString(); 

// ALGORITHM TIME....

    for (int i = 0, j = 0, n = strlen(message); i < n;) 
     
    {                                                     
        //Keyloop: Reset key index if equal to length of keyword 
        
        if (j == strlen(argv[1])) 
        {
            j = 0;
        } 
        
        //Check if msg char is not alphabetic (ie, space, numbers, symbols)
        
        else if (!isalpha(message[i])) 
        {
            printf("%c",message[i]); 
            i++;
        }
        
        //Check if char is alphabetic
        
        else if (isalpha(message[i])) 
        { 
        
        // Message lowercase tests (note: also tests case of key)
        
           if(islower(message[i]) && islower(argv[1][j])) 
           {                
                char cipherletter = ((message[i] - 'a') + (argv[1][j] - 'a')) % 26 + 'a';  
                printf("%c",cipherletter);
                
                i++;
                j++;
           } 
            
           else if(islower(message[i]) && isupper(argv[1][j])) 
           {                
                char cipherletter = ((message[i] - 'a') + (argv[1][j] - 'A')) % 26 + 'a';  
                printf("%c",cipherletter);
                
                i++;
                j++;
           }     
            
            //Message uppercase tests (note: also tests case of key)
            
            else if (isupper(message[i]) && islower(argv[1][j])) 
            {   
                char cipherletter = ((message[i] - 'A') + (argv[1][j] - 'a')) % 26 + 'A';
                printf("%c",cipherletter);
                
                i++;
                j++; 
            }
            
            else if(isupper(message[i]) && isupper(argv[1][j])) 
            {                
                char cipherletter = ((message[i] - 'A') + (argv[1][j] - 'A')) % 26 + 'A';  
                printf("%c",cipherletter);
                
                i++;
                j++;
            } 
        }
    }
   
   printf("\n");
   
return 0;

}
