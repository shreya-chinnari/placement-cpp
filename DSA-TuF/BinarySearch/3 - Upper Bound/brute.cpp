#include <iostream>
using namespace std;

int linSearch(int arr[], int size, int n)
{
   for (int i = 0; i < size; i++)
   {
      if (arr[i] > n)
      {
         return i;
      }
   }
   return -1; // If no element found greater than n
}

int main()
{

   return 0;
}