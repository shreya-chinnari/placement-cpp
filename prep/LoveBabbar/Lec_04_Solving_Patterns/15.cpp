/*
Enter a number: 4
   A
   B C
   D E F
   G H I J
*/

#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   int i = 1;
   // char ch = 'A'; // method 1
   while (i <= n)
   {
      int j = 1;
      char ch = 'A' + i + j - 2; // method 2
      while (j <= i)
      {
         cout << ch << " ";
         ch++;
         j++;
      }
      cout << endl;
      i++;
   }
   return 0;
}