#include <cs50.h>
#include <stdio.h>

 void draw(int n);


 int main(void){
 int height = get_int("Height: ");
 draw(height);
 }

 void draw(int n)
 {
if (n <= 0)//make sure its NEVER negative or if nothing to draw or base case
{
return; }

    //Print pyramid of height n-1
  draw(n - 1);

//Print one more row
  for (int i = 0; i < n; i++)
  {
    printf("#");
  }
  printf("\n");
 }
