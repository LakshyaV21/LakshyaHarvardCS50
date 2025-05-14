#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>

typedef struct node{
    int number;
    struct node *next;
} node;

int main(void){
    node *list = NULL;

    for (int i = 0; i < 3; i++){
        node *n = malloc(sizeof(node)); //use node instead of string
        if (n == NULL){
            return 1;
        }
        n->number = get_int("Number: ");
        n->next = NULL;//make sure not a garbage value

//if list is empty
        if (list == NULL){

            list = n;

        }
        //if list has numbers already
        else{
            for (node *ptr = list; ptr != NULL; ptr = ptr->next){
                //if at the nd of list
                if(ptr->next == NULL){
                    break;
                }
            }
        }

    }

    //Time passes

   for (node *ptr = list; ptr != NULL; ptr = pyt->next){
    pritnf("%i\n", ptr->number);
   }

   //Time passes

nofr *ptr = list;
while(ptr != NULL){
    node *next = ptr->next;
    free (ptr); //freeing the node move on to the next till you reach NULL
    ptr = ptr->next;
}


   return 0;
}
