#include <iostream>
using namespace std;

int main()
{
   char multiple_words[50];
   cout << "Enter a long word: " << endl;
   cin >> multiple_words;
   cout << "You entered: " << multiple_words << endl;

   /*
   Ip: Enter a long word:
   shreya chinnari
   Op: You entered: shreya
   */

   char break_words[50];
   cout << "Enter a word with \\ 0 in between: " << endl;
   cin >> break_words;
   cout << "You entered: " << break_words << endl;

   /*
   Ip: Enter a word with \ 0 in between:
   shre\0ya
   Op: You entered: shre\0ya

   but in {cout << "Enter a word with \0 in between: " << endl;} it only showed till ["Enter a word with]
   */

   char str[50] = "Hello World";
   str[1] = '\0'; // Null-terminate the string at index 10
   cout << "String after null termination: " << str << endl;
   return 0;

   /*
   Op: String after null termination: H
   */
}