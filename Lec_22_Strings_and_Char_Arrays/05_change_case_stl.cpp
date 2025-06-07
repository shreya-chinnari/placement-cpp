#include <iostream>
#include <cctype> // for tolower() and toupper()
using namespace std;

int main()
{
   char ch1 = 'D';
   char ch2 = 'g';
   char ch3 = '5';
   char ch4 = '#';

   // Using STL tolower()
   cout << "Original: " << ch1 << " -> tolower(): " << (char)tolower(ch1) << endl;
   cout << "Original: " << ch2 << " -> tolower(): " << (char)tolower(ch2) << endl;

   // Using STL toupper()
   cout << "Original: " << ch2 << " -> toupper(): " << (char)toupper(ch2) << endl;
   cout << "Original: " << ch1 << " -> toupper(): " << (char)toupper(ch1) << endl;

   // Non-alphabet characters
   cout << "Original: " << ch3 << " -> tolower(): " << (char)tolower(ch3) << " | toupper(): " << (char)toupper(ch3) << endl;
   cout << "Original: " << ch4 << " -> tolower(): " << (char)tolower(ch4) << " | toupper(): " << (char)toupper(ch4) << endl;

   return 0;
}
