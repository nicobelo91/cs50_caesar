 
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>



int main(int argc, string argv[])

//Check if there are two comand- line arguments
{
    //If there aren't:
    
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    //If there are, then check if they are purely digits
    
    else
    {   
        int key = atoi(argv[1]);
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            char input = argv[1][i];
            
            //If they aren't:
            
            if (!isdigit(input))
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        
        //If they are all digits, then:
        
        for (int i = 0; i < strlen(argv[1]); i++)
        {
            char input = argv[1][i];
            
            if (isdigit(input))
            {
                    
                //Prompt the user for an input:
                    
                string plaintext = get_string("plaintext: ");
                printf("ciphertext: ");
                for (i = 0; i < strlen(plaintext); i++)
                {
                    
                    //If the input is an alphabetic character:
                    if (isalpha(plaintext[i])) 
                    {
                       
                        //If the input is uppercase:
                        
                        if (isupper(plaintext[i]))
                        {
                            
                            //Then convert ASCII to alphabetical index by substracting 65
                            
                            char cipher = (((plaintext[i] - 65) + key) % 26) + 65;
                            printf("%c", cipher);
                        }
                        
                        //If the input is lowercase:
                        
                        else if (islower(plaintext[i]))
                        {
                            
                            //Then convert ASCII to alphabetical index by substracting 97
                            
                            char cipher = (((plaintext[i] - 97) + key) % 26) + 97;
                            printf("%c", cipher);
                        }
                        
                    } 
                    else 
                    {
                        printf("%c", plaintext[i]);
                    }
                }
                printf("\n");
                return 0;
                
                
            }
            printf("\n");
        }
    }
}