#include <cs50.h>
#include <stdio.h>


bool luhn_check(long number);
void identify_card(long number);


int main(void)
{


   // ask user for input number of credit card
   long number = get_long("Number: ");


   // checking validity
   if (luhn_check(number))
   {
       identify_card(number);
   }
   else
   {
       printf("INVALID\n");
   }
   return 0;
}


bool luhn_check(long number)
{
   int sum = 0;
   int digit_count = 0;


   while (number > 0)
   {
       int digit = number % 10;


       // If the digit is in an odd position (from the end), add it directly
       if (digit_count % 2 == 0)
       {
           sum += digit;
       }
       else
       {
           // If the digit is in an even position, double it and add the digits of the product
           int product = digit * 2;
           sum += (product / 10) + (product % 10);
       }


       number /= 10;
       digit_count++;
   }


   // A valid card number has a sum divisible by 10
   return sum % 10 == 0;
}


void identify_card(long number)
{
   int length = 0;
   long start_digits = number;


   // Determine the length of the number and extract the starting digits
   while (start_digits >= 100)
   {
       start_digits /= 10;
       length++;
   }
   length += 2; // Add the last two digits


   // Check for card type
   if ((start_digits == 34 || start_digits == 37) && length == 15)
   {
       printf("AMEX\n");
   }
   else if ((start_digits >= 51 && start_digits <= 55) && length == 16)
   {
       printf("MASTERCARD\n");
   }
   else if ((start_digits / 10 == 4) && (length == 13 || length == 16))
   {
       printf("VISA\n");
   }
   else
   {
       printf("INVALID\n");
   }
}



