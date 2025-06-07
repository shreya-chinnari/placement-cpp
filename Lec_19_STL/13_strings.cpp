#include <iostream>
#include <string>
#include <algorithm> // For sort, reverse, count, transform
#include <cctype>    // For toupper, tolower

using namespace std;

int main()
{
   // Declaration and Initialization
   string str1 = "Hello";
   string str2 = "World";
   string str3;

   cout << "Initial str1: " << str1 << endl;
   cout << "Initial str2: " << str2 << endl;

   // Length of string
   cout << "\n1. Length of str1: " << str1.length() << endl;

   // Copy string
   str3 = str1;
   cout << "2. Copied str1 to str3: " << str3 << endl;

   // Concatenation
   str1 += str2; // same as str1 = str1 + str2;
   cout << "3. Concatenated str2 to str1: " << str1 << endl;

   // Compare strings
   cout << "4. Compare str1 and str2: ";
   if (str1 == str2)
      cout << "str1 == str2" << endl;
   else if (str1 < str2)
      cout << "str1 < str2" << endl;
   else
      cout << "str1 > str2" << endl;

   // Access character
   cout << "5. First character of str1: " << str1[0] << endl;
   cout << "   Last character of str1: " << str1[str1.size() - 1] << endl;

   // Find substring
   size_t pos = str1.find("loWo");
   cout << "6. Find substring 'loWo' in str1: ";
   if (pos != string::npos)
      cout << "Found at index " << pos << endl;
   else
      cout << "Not found" << endl;

   // Substring extraction
   string sub = str1.substr(2, 4); // from index 2, take 4 characters
   cout << "7. Substring of str1 from index 2, length 4: " << sub << endl;

   // Insert
   str1.insert(5, "123");
   cout << "8. After inserting '123' at index 5: " << str1 << endl;

   // Replace
   str1.replace(5, 3, "XYZ");
   cout << "9. After replacing '123' with 'XYZ': " << str1 << endl;

   // Erase
   str1.erase(5, 3);
   cout << "10. After erasing 'XYZ': " << str1 << endl;

   // Transform to uppercase
   transform(str1.begin(), str1.end(), str1.begin(), ::toupper);
   cout << "11. str1 in uppercase: " << str1 << endl;

   // Transform to lowercase
   transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
   cout << "12. str1 in lowercase: " << str1 << endl;

   // Reverse
   reverse(str1.begin(), str1.end());
   cout << "13. Reversed str1: " << str1 << endl;

   // Sort
   sort(str1.begin(), str1.end());
   cout << "14. Sorted str1: " << str1 << endl;

   // Count a specific character
   int count_l = count(str1.begin(), str1.end(), 'l');
   cout << "15. Count of 'l' in str1: " << count_l << endl;

   // Clear the string
   str1.clear();
   cout << "16. After clearing, str1: '" << str1 << "', empty? " << (str1.empty() ? "Yes" : "No") << endl;

   return 0;
}
