#include <iostream>
using namespace std;

void reverseString(char str[], int start, int end)
{
   while (start < end)
   {
      swap(str[start++], str[end--]); // Swap characters at start and end, then move pointers

      /*
      / Manual swap without using STL

         char temp = str[start];
         str[start] = str[end];
         str[end] = temp;

         start++;
         end--;
      */
   }
}

int main()
{

   char str[] = "Hello";
   reverseString(str, 0, 4); // Call the function to reverse the string from index 0 to 4
   cout << "Reversed string (without STL): " << str << endl;
   return 0;
}