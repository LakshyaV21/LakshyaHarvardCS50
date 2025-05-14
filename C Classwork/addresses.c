#include <stdio.h>
#include <cs50.h>

int main(void){
    string s  = "Hi!";
    printf("%c", *s);
    printf("%c", *(s+1));
    printf("%c\n", *(s+2));
}
