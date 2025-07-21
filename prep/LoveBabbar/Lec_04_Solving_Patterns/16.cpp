/*
Enter a number: 4
   D
   D C
   D C B
   D C B A
*/

#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;
   int i = 1;

   while (i <= n)
   {
      int j = 1;
      char ch = 'A' + n - j;
      while (j <= i)
      {
         cout << ch << " ";
         ch--;
         j++;
      }
      cout << endl;
      i++;
   }
   return 0;
}