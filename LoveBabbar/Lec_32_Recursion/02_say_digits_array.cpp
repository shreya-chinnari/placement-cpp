#include <iostream>
using namespace std;

// Recursive function to print digits in words using array
void printNumberInWords(int num, string words[])
{
   // Base case: stop when number becomes 0
   if (num == 0)
      return;

   // Recursive call for left part of number
   printNumberInWords(num / 10, words); // Remove last digit and go left

   // After recursion, print the current digit's word
   int lastDigit = num % 10;
   cout << words[lastDigit] << " ";
}

int main()
{
   int num;
   cout << "Enter a number: ";
   cin >> num;

   // Array of digit-to-word mappings (index = digit)
   string words[] = {
       "zero", "one", "two", "three", "four",
       "five", "six", "seven", "eight", "nine"};

   // Special case: if number is 0, print zero directly
   if (num == 0)
   {
      cout << words[0] << endl;
   }
   else
   {
      printNumberInWords(num, words);
      cout << endl;
   }

   return 0;
}
