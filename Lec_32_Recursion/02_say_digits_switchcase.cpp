// if i/p is 245, output should be "two four five".
// This code snippet is a C++ program that prints the digits of a number in words using recursion.

#include <iostream>
using namespace std;

// Helper function to print the word for a digit
void printDigitWord(int digit)
{
   switch (digit)
   {
   case 0:
      cout << "zero ";
      break;
   case 1:
      cout << "one ";
      break;
   case 2:
      cout << "two ";
      break;
   case 3:
      cout << "three ";
      break;
   case 4:
      cout << "four ";
      break;
   case 5:
      cout << "five ";
      break;
   case 6:
      cout << "six ";
      break;
   case 7:
      cout << "seven ";
      break;
   case 8:
      cout << "eight ";
      break;
   case 9:
      cout << "nine ";
      break;
   }
}

// Recursive function to print number in words
void printNumberInWords(int num)
{
   // Base case: when number becomes 0, stop recursion
   if (num == 0)
      return;

   // Recursive step: first handle the left part
   printNumberInWords(num / 10); // Recursive call on number excluding last digit

   // After recursion returns, process the last digit
   int lastDigit = num % 10;
   printDigitWord(lastDigit); // Print the current digit as word
}

int main()
{
   int num;
   cout << "Enter a number: ";
   cin >> num;

   // Special case for zero
   if (num == 0)
   {
      printDigitWord(0);
   }
   else
   {
      printNumberInWords(num); // Print digits in words
   }

   cout << endl;
   return 0;
}
