#include <iostream>
using namespace std;

int main()
{
   int arr[5] = {10, 20, 30, 40, 50};
   int *ptr = arr; // ptr points to arr[0]

   cout << "arr (address of first element): " << arr << endl;             // prints address of arr[0]
   cout << "*arr (value at first element): " << *arr << endl;             // prints 10
   cout << "&arr (address of whole array): " << &arr << endl;             // prints address of entire array
   cout << "ptr (same as arr): " << ptr << endl;                          // same address as arr
   cout << "*ptr (value ptr points to): " << *ptr << endl;                // prints 10
   cout << "&ptr (address of pointer variable itself): " << &ptr << endl; // address where ptr is stored

   cout << "\n--- Sizes in bytes ---\n";
   cout << "Size of arr (array of 5 ints): " << sizeof(arr) << " bytes" << endl; // 5 * 4 = 20 bytes
   cout << "Size of *arr (value): " << sizeof(*arr) << " bytes" << endl;         // value of arr[0], i.e., int = 4 bytes
   cout << "Size of &arr (address): " << sizeof(&arr) << " bytes" << endl;       // address of array (pointer) = 8 bytes on 64-bit
   cout << "Size of ptr (pointer to int): " << sizeof(ptr) << " bytes" << endl;  // pointer = 8 bytes
   cout << "Size of *ptr (value): " << sizeof(*ptr) << " bytes" << endl;         // value at ptr, i.e., int = 4 bytes
   cout << "Size of &ptr (address): " << sizeof(&ptr) << " bytes" << endl;       // address of pointer variable = 8 bytes

   /*
> arr (address of first element): 0x1201ff810
> *arr (value at first element): 10
> &arr (address of whole array): 0x1201ff810
> ptr (same as arr): 0x1201ff810
> *ptr (value ptr points to): 10
> &ptr (address of pointer variable itself): 0x1201ff808

--- Sizes in bytes ---
> Size of arr (array of 5 ints): 20 bytes
> Size of *arr (value): 4 bytes
> Size of &arr (address): 8 bytes
> Size of ptr (pointer to int): 8 bytes
> Size of *ptr (value): 4 bytes
> Size of &ptr (address): 8 bytes
   */
   return 0;
}
