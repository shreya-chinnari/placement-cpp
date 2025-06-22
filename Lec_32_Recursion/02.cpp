#include <iostream>
using namespace std;

void printDigitBEFORE(int n, string arr[])
{

   // Base case: if n is 0, print "zero" and return
   if (n == 0)
   {
      return;
   }
   // processing
   int lastDigit = n % 10; // rightmost digit
   n = n / 10;             // cut off the rightmost digit

   cout << arr[lastDigit] << " "; // Print the digit FIRST
   printDigitBEFORE(n, arr);      // Then go to next digit

   /*
⏳ So what happens?
   > Prints the last digit first
   > Recursion continues cutting digits
   > Prints digits in reverse order

🧪 Input: 368

   : : lastDigit = 8 → print "eight"
   : : lastDigit = 6 → print "six"
   : : lastDigit = 3 → print "three"
   */
}
void printDigitAFTER(int n, string arr[])
{

   // Base case: if n is 0, print "zero" and return
   if (n == 0)
   {
      return;
   }
   // processing
   int lastDigit = n % 10; // rightmost digit
   n = n / 10;             // cut off the rightmost digit

   printDigitAFTER(n, arr);       // Go deeper first
   cout << arr[lastDigit] << " "; // Print the digit AFTER

   /*
⏳ So what happens?

   > Recursion first reaches the leftmost digit
   > On the way back, prints digits one by one
   > Result: digits printed in correct left-to-right order

🧪 Input: 368:
   Execution:

   : : Reaches 3 → print "three"
   : : Back to 6 → print "six"
   : : Back to 8 → print "eight"
   */
}
int main()
{
   string arr[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

   // above can be accesed using index { }

   int num;
   cout << "Enter a number: ";
   cin >> num;

   cout << "cout BEFORE: ";
   printDigitBEFORE(num, arr);
   cout << endl;
   cout << "cout AFTER: ";
   printDigitAFTER(num, arr);
   cout << endl;

   return 0;
}

// Enter a number: 368

// cout BEFORE : eight six three
// cout AFTER : three six eight