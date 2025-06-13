#include <iostream>
using namespace std;

int main()
{
   int num = 5;
   int *p = &num; // p points to the memory location of num

   cout << "num: " << num << endl;
   cout << "p: " << p << endl;
   cout << "*p: " << *p << endl;
   /*
   num: 5
   p: 0x8a45ffc80
   *p: 5 (= num)
   */

   int a = *p; // This creates a new variable a, and initializes it with the value pointed to by p, which is 5. So now, a = 5, but it's an independent copy.

   cout << "a: " << a << endl;
   cout << "num: " << num << endl;
   cout << "p: " << p << endl;
   cout << "*p: " << *p << endl;
   /*
   a: 5
   num: 5 [But num is unaffected since a is a copy of *p (value of num), not a reference.]
   p: 0x8a45ffc80
   *p: 5
   */
   a++;

   cout << "a: " << a << endl;
   cout << "num: " << num << endl;
   cout << "p: " << p << endl;
   cout << "*p: " << *p << endl;
   /*
   a: 6
   num: 5
   p: 0x8a45ffc80
   *p: 5
   */

   (*p)++;

   cout << "a: " << a << endl;
   cout << "num: " << num << endl;
   cout << "p: " << p << endl;
   cout << "*p: " << *p << endl;
   /*
   a: 6 [a remains unchanged because it was copied earlier]
   num: 6 [*p is num → so num++ happens]
   p: 0x4ce85ffcf0
   *p: 6 [*p is num → so num++ happens]
   */
   return 0;
}