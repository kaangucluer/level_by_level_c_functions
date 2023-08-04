/*
Assignment name  : repeat_alpha
Expected files   : repeat_alpha.c
Allowed functions: write
--------------------------------------------------------------------------------

Write a program called repeat_alpha that takes a string and display it
repeating each alphabetical character as many times as its alphabetical index,
followed by a newline.

'a' becomes 'a', 'b' becomes 'bb', 'e' becomes 'eeeee', etc...

Case remains unchanged.

If the number of arguments is not 1, just display a newline.

Examples:

$>./repeat_alpha "abc"
abbccc
$>./repeat_alpha "Alex." | cat -e
Alllllllllllleeeeexxxxxxxxxxxxxxxxxxxxxxxx.$
$>./repeat_alpha 'abacadaba 42!' | cat -e
abbacccaddddabba 42!$
$>./repeat_alpha | cat -e
$
$>
$>./repeat_alpha "" | cat -e
$
$>
*/

#include <unistd.h>

void repeat_alpha(char *stralpha)
{
    int i = 0;
    char lower_alphabet[26] = "abcdefghijklmnopqrstuvwxyz";
    char UPPER_alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    while(stralpha[i] != '\0')
    {
        int j = 0;
        int k = 0;
        int l = 0;

        while(stralpha[i] > 'a' && stralpha[i] < 'z')
        {
            while(lower_alphabet[j] == stralpha[i])
            {
                while(l <= j)
                {
                    write(1,&stralpha[i],1);
                    l++;
                }
            }
            j++;   
        }
        
        while(stralpha[i] > 'A' && stralpha[i] < 'Z')
        {
            while(UPPER_alphabet[k] == stralpha[i])
            {
                while(l <= k)
                {
                    write(1,&stralpha[i],1);
                    k++;
                }
            }
            k++;
        }

        i++;
    }
}

int main(int argc, char **argv)
{
    if(argc == 2)
    {
        repeat_alpha(argv[1]);
    }
    write(1,"\n",1);
    return 0;
}

