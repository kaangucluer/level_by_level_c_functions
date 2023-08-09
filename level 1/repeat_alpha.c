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

void put_alphabet(char letter, int size)
{
    int k = 0;
    while(k < size)
    {
        write(1,&letter,1);
        k++;
    }
}

void repeat_alphabet(char *str)
{
    int i = 0;
    while(str[i] != '\0')
    {
        if(str[i] >= 'a' && str[i] <= 'z')
        {
            put_alphabet(str[i], str[i] + 1 - 'a');
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
        {
            put_alphabet(str[i], str[i] + 1 - 'A');
        }
        else
            write(1,&str[i],1);
        i++;
    }
}

int main(int argc, char *argv[])
{
    if(argc == 2)
    {
        repeat_alphabet(argv[1]);
    }
    write(1, "\n", 1);
    return 0;
}