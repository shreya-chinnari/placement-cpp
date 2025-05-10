#include <iostream>
using namespace std;

int main()
{
   int n;
   cout << "Enter a number: ";
   cin >> n;

   int i = 1;
   int count = 1; // important change

   while (i <= n)
   {
      int j = 1;
      while (j <= n)
      {
         cout << count << " "; // important change
         count++;              // important change
         j++;
      }
      cout << endl;
      i++;
   }

   return 0;
}