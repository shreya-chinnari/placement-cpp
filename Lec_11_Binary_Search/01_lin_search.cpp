#include <iostream>
using namespace std;

// int main()
// {
//    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    int key = 5;
//    bool found = false;
//    for (int i = 0; i < 10; i++)
//    {
//       if (key == arr[i])
//       {
//          cout << "Key found at index: " << i << endl;
//          found = true;
//          break;
//       }
//    }
//    if (!found)
//    {
//       cout << "Key not found" << endl;
//    }
//    return 0;
// }

int main()
{
   int arr[] = {1, 2, 3, 4, 5};
   int key = 3;

   for (int i = 0; i < 5; i++)
   {
      if (arr[i] == key)
      {
         cout << "Found at index " << i << endl;
         return 0;
      }
   }

   cout << "Not found" << endl;
   return 0;
}