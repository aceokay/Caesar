#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    //making sure that there are only two arguments passed in
    if(argc != 2)
    {
        printf("How to use: ./caesar key");
        return 1;
    }
    
    //Turning the passed in string argument "key" into an integer
    int k = atoi(argv[1]);
    
    //Prompting for a string to encrypt
    char * str = GetString();
    
    //Encrypting the string with the key
    for(int i = 0, n = strlen(str); i < n; i++)
    {
        //This picks out the specific letter from the string
        int let = str[i];
        
        //This decides if the beginning letter was a letter to begin with, and encrypts and prints accordingly
        if(isalpha(str[i]))
        {
            if(isupper(str[i]))
            {
                //This encrypts every uppercase character
                int upRe = (let + k) % 91;
                if(upRe <= 25)
                {
                    upRe = upRe + 65;
                }
                else if (upRe > 25 && upRe < 65)
                {
                    upRe = upRe % 26 + 65;
                }
                printf("%c", upRe);
            }
            else
            {
                //This encrypts every lowercase letter
                int lowRe = (let + k) % 123;
                if(lowRe <= 25)
                {
                    lowRe = lowRe + 97;
                }
                else if (lowRe > 25 && lowRe < 97)
                {
                    lowRe = lowRe % 26 + 97;
                }
                        printf("%c", lowRe);
            }
        }
        //Where non alphabetical letters are printed
        else
        {
            printf("%c", str[i]);
        }
    }
    printf("\n");
    return 0;
}
