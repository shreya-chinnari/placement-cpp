#include <iostream>
using namespace std;

void print(int arr[], int s, int e)
{
   cout << "Size of Array: " << (e - s + 1) << endl;
   cout << "s: " << s << ", e: " << e << endl;
   cout << "Elements of Array: ";
   for (int i = s; i <= e; i++)
   {
      cout << arr[i] << " ";
   }
   cout << endl;
}

bool binarySearch(int arr[], int s, int e, int key)
{
   print(arr, s, e); // Print the current state of the array being searched
   cout << endl;
   if (s > e)
      return false;
   int mid = s + (e - s) / 2;
   cout << "mid index: " << mid << "  |  element at index[mid] : " << arr[mid] << endl; // print mid
   if (arr[mid] == key)
      return true;
   else if (key < arr[mid])
      return binarySearch(arr, s, mid - 1, key);
   else
      return binarySearch(arr, mid + 1, e, key);
}

int main()
{
   int arr[] = {2, 3, 10, 11, 22, 24, 34, 69, 70, 90};

   int size = sizeof(arr) / sizeof(arr[0]);
   int key = 70;
   int s = 0;
   int e = size - 1;
   bool ans = binarySearch(arr, s, e, key);
   ans ? cout << "\nElement found.\n\n" : cout << "\nElement not found.\n\n";
   return 0;
}

/*
Size of Array: 10
s: 0, e: 9
Elements of Array: 2 3 10 11 22 24 34 69 70 90

mid index: 4  |  element at index[mid] : 22
Size of Array: 5
s: 5, e: 9
Elements of Array: 24 34 69 70 90

mid index: 7  |  element at index[mid] : 69
Size of Array: 2
s: 8, e: 9
Elements of Array: 70 90

mid index: 8  |  element at index[mid] : 70
Element found.
*/