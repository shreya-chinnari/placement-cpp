// decimal to binary

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
   int n;
   cout << "Enter a positive number: ";
   cin >> n;

   int binary = 0;
   int place = 1;

   while (n > 0)
   {
      int bit = n % 2;
      binary = bit * place + binary;
      place *= 10;
      n = n / 2;
   }

   cout << "Binary: " << binary << endl;
   return 0;
}
