#include <iostream>
using namespace std;

int main()
{
   int i = 5;
   int *p = &i;   // Pointer to i
   int **q = &p;  // Pointer to pointer to i
   int ***r = &q; // Pointer to pointer to pointer to i

   cout << "Value of i: " << i << endl;
   cout << "Address of variable i: " << &i << endl;

   cout << "Value stored in pointer p (i.e., address of i): " << p << endl;
   cout << "Value pointed to by p (i.e., value of i): " << *p << endl;
   cout << "Address of pointer p: " << &p << endl;

   cout << "Value stored in pointer q (i.e., address of p): " << q << endl;
   cout << "Value pointed to by q (i.e., value stored in p): " << *q << endl;
   cout << "Value pointed to by *q (i.e., value of i): " << **q << endl;
   cout << "Address of pointer q: " << &q << endl;

   cout << "Value stored in pointer r (i.e., address of q): " << r << endl;
   cout << "Value pointed to by r (i.e., value stored in q): " << *r << endl;
   cout << "Value pointed to by *r (i.e., value stored in p): " << **r << endl;
   cout << "Value pointed to by ***r (i.e., value of i): " << ***r << endl;
   cout << "Address of pointer r: " << &r << endl;

   return 0;
}
