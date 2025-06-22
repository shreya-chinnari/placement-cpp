#include <iostream>
using namespace std;

int main()
{
   int arr[5] = {1, 2, 3, 4, 5};

   cout << "arr[0]: " << arr[0] << endl;
   cout << "'arr' is the address of the first memory block (arr[0]): " << arr << endl; // 0x77947ffc80
   cout << "'&arr[0]' is also the address of arr[0]: " << &arr[0] << endl;             // 0x77947ffc80

   // both will point to same address

   // &arr[0] : means :
   // & : means "address of"
   // arr[0]

   int arr1[3] = {30, 24, 15};
   cout << "arr1 : " << arr1 << endl;   // 0x77947ffc74
   cout << "*arr1 : " << *arr1 << endl; // 30

   // *p : points to the value whose address is stored in p

   cout << "*arr1 + 1: " << *arr1 + 1 << endl; // 30+1 = 31 : It's the value at index 0 plus 1.

   cout << "(*arr1) + 1: " << (*arr1) + 1 << endl; // 30+1 = 31 : It's the value at index 0 plus 1.
   cout << "*(arr1 + 1): " << *(arr1 + 1) << endl; // So this directly accesses index 1, which is 24.

   /*

   *arr1 : 30
   *arr1 + 1: 31
   (*arr1) + 1: 31
   *(arr1 + 1): 24

   */

   // ===============================
   // arr[i] =  *(arr + i)
   // i[arr] = *(i + arr)
   // ===============================

   int i = 5;
   cout << "arr[i] : " << arr[i] << endl;
   cout << "*(arr + i) : " << *(arr + i) << endl;
   cout << "i[arr] : " << i[arr] << endl;
   cout << "*(i + arr) : " << *(i + arr) << endl;

   // arr[i] : 0
   // *(arr + i) : 0
   // i[arr] : 0
   // *(i + arr) : 0
   return 0;
}