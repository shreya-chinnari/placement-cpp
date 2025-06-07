#include <iostream>
#include <cstring>   // For C-string functions
#include <algorithm> // For STL algorithms like sort, reverse
#include <cctype>    // For toupper, tolower

using namespace std;

int main()
{
   // Declaration and Initialization
   char str1[50] = "Hello";
   char str2[50] = "World";
   char str3[50];

   cout << "Initial str1: " << str1 << endl;
   cout << "Initial str2: " << str2 << endl;

   // Length of a string
   cout << "\n1. Length of str1: " << strlen(str1) << endl;

   // Copy string
   strcpy(str3, str1);
   cout << "2. Copied str1 to str3: " << str3 << endl;

   // Concatenate strings
   strcat(str1, str2);
   cout << "3. Concatenated str2 to str1: " << str1 << endl;

   // Compare strings
   int cmpResult = strcmp(str1, str2);
   cout << "4. Compare str1 and str2: ";
   if (cmpResult == 0)
      cout << "str1 == str2" << endl;
   else if (cmpResult < 0)
      cout << "str1 < str2" << endl;
   else
      cout << "str1 > str2" << endl;

   // Find a character in str1
   char *found = strchr(str1, 'o');
   cout << "5. First occurrence of 'o' in str1: ";
   if (found)
      cout << found << endl;
   else
      cout << "Not found" << endl;

   // Find last occurrence of a character
   char *lastFound = strrchr(str1, 'l');
   cout << "6. Last occurrence of 'l' in str1: ";
   if (lastFound)
      cout << lastFound << endl;
   else
      cout << "Not found" << endl;

   // Substring search
   char *substr = strstr(str1, "loWo");
   cout << "7. Substring 'loWo' in str1: ";
   if (substr)
      cout << substr << endl;
   else
      cout << "Not found" << endl;

   // Convert to uppercase
   for (int i = 0; str1[i] != '\0'; ++i)
      str1[i] = toupper(str1[i]);
   cout << "8. str1 in uppercase: " << str1 << endl;

   // Convert to lowercase
   for (int i = 0; str1[i] != '\0'; ++i)
      str1[i] = tolower(str1[i]);
   cout << "9. str1 in lowercase: " << str1 << endl;

   // Reverse string using STL
   reverse(str1, str1 + strlen(str1));
   cout << "10. Reversed str1: " << str1 << endl;

   // Sort string using STL
   sort(str1, str1 + strlen(str1));
   cout << "11. Sorted str1: " << str1 << endl;

   // Count a specific character using STL
   int count_l = count(str1, str1 + strlen(str1), 'l');
   cout << "12. Count of 'l' in str1: " << count_l << endl;

   return 0;
}
