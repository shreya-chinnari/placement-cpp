#include <iostream>
using namespace std;

int main()
{
   char ch[6] = "abcde"; // Creates a character array with 6 elements: {'a','b','c','d','e','\0'}
   char *c = ch;         // c is a pointer to the first element of ch (i.e., &ch[0])

   // Displaying values and addresses
   cout << "ch           : " << ch << endl;
   // ch decays to a pointer to its first element, i.e., &ch[0], and since it's a char array,
   // printing ch as a string prints "abcde" until the null character '\0'.

   cout << "&ch          : " << &ch << endl;
   // &ch is the address of the entire array (type: char(*)[6]).
   // But when sent to cout, it's implicitly converted to const char*, so it prints as "abcde".
   // This is same as ch in output, but NOT in type. (It's still the same memory address though.)

   cout << "&ch[0]       : " << &ch[0] << endl;
   // &ch[0] is the address of the first character of the array.
   // When output as a C-string, it again prints "abcde".

   cout << "ch[0]        : " << ch[0] << endl;
   // Accesses and prints the first character of the array: 'a'

   cout << "*ch          : " << *ch << endl;
   // *ch dereferences the pointer (points to first element of ch), so prints 'a'

   cout << "\n--- Pointer c ---\n";

   cout << "c             : " << c << endl;
   // c points to ch, so this prints the contents starting at ch, i.e., "abcde"

   cout << "*c            : " << *c << endl;
   // *c dereferences the pointer, points to first char 'a' in ch

   cout << "&c            : " << &c << endl;
   // &c gives the address of the pointer variable `c` itself,
   // which is different from the address `c` is pointing to

   cout << "\n--- Raw addresses ---\n";
   cout << "(void*)ch     : " << (void *)ch << endl;     // Address of ch
   cout << "(void*)&ch    : " << (void *)&ch << endl;    // Address of ch
   cout << "(void*)&ch[0] : " << (void *)&ch[0] << endl; // Address of ch's first element
   cout << "(void*)c      : " << (void *)c << endl;      // Address of c
   cout << "(void*)&c     : " << (void *)&c << endl;     // Address of c variable

   return 0;
}

/*
ch           : abcde
&ch          : 0x32285ff97a
&ch[0]       : abcde
ch[0]        : a
*ch          : a

--- Pointer c ---
c             : abcde
*c            : a
&c            : 0x32285ff970

--- Raw addresses ---
(void*)ch     : 0x32285ff97a
(void*)&ch    : 0x32285ff97a
(void*)&ch[0] : 0x32285ff97a
(void*)c      : 0x32285ff97a
(void*)&c     : 0x32285ff970
*/