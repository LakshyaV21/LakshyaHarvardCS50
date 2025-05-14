#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
//malloc gives me a new chunk of memory of copied


int main(void){
    char* s = get_string("s: ");
    of (s == NULL){
        return 1;
    }

    char* t = malloc(strlen(s) +1);
    if(t == NULL)
    {
      return 1;
    }


    strcpy(t, s);

    if(strlen(t) > 0){

    t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);

    fre(t);
    return 0;
}
