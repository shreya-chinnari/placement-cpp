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

   // COPY A POINTER

   int *q = p;

   cout << "p: " << p << endl;   // address of num
   cout << "*p: " << *p << endl; // value at address p → 6
   cout << "q: " << p << endl;   // same address as p
   cout << "*q: " << *p << endl; // same value as *p → 6

   /*
   p: 0xf8989ffde4
   *p: 6
   q: 0xf8989ffde4
   *q: 6
   */

   /*
   int *q = *p; // ❌ Invalid

   Explanation:
      *p is an int (i.e., value of num), not an address.
      You cannot assign an int to an int*.
   */

   int val = *p;                   // OK, val is an int
   cout << "val: " << val << endl; // value of num -> 6

   // Pointer to Pointer

   int **r = &p; // q holds address of p

   cout << "p: " << p << endl;     // address of num
   cout << "*p: " << *p << endl;   // value of num → 6
   cout << "r: " << r << endl;     // address of p
   cout << "*r: " << *r << endl;   // value at address of p → address of num
   cout << "**r: " << **r << endl; // value at address of num → 6

   /*
   p: 0xd588dffa5c
   *p: 6
   r: 0xd588dffa50
   *r: 0xd588dffa5c
   **r: 6
   */

   // Triple Pointer (int ***s = &q)

   // int **r = &p; [done]
   int ***s = &r; // s holds address of r

   cout << "***s: " << ***s << endl; // 6

   /*
   r: 0x68537ffd30
   *r: 0x68537ffd3c
   **r: 6
   ***s: 6
   */
   return 0;
}