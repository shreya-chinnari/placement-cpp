#include <iostream>
using namespace std;

int main()
{
   int i = 3;

   int *t = &i;
   // here, [t] stores address of i, [*t] stores value at adress 't', [&i] stores the address of 'i', [i] stores the value 3

   cout << "i : " << i << endl;           // 3
   cout << "*t : " << *t << endl;         // 3
   cout << "t : " << t << endl;           // 0x1001ffa04
   cout << "(*t)++ : " << (*t)++ << endl; // 3

   *t = *t + 1;                   //(*t)++
   cout << "*t : " << *t << endl; // 5

   t = t + 1;                     // refer to {13_02.png}
   cout << "t : " << t << endl;   // 0x1001ffa08 [4 byte aage badh chuka hai]
   cout << "*t : " << *t << endl; // some randomg integer

   return 0;
}