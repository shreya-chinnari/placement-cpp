// check if a given number is power of 2

#include <iostream>
#include <cmath>
using namespace std;

void isTrue(int arr[], int size, int n)
{
   for (int i = 0; i < size; i++)
   {

      if (n == arr[i])
      {
         cout << "yes , it's power of 2:  " << pow(2, i) << endl;
      }
   }
}

int main()
{
   int pow2[31];
   for (int i = 0; i <= 30; i++)
   {
      pow2[i] = pow(2, i);
   }

   int n;
   cout << "Enter a number: " << endl;
   cin >> n;

   isTrue(pow2, 31, n);

   return 0;
}