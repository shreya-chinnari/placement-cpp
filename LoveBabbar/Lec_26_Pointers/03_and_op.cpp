#include <iostream>
using namespace std;

int main()
{
   int a[5] = {10, 20, 30, 40, 50};

   cout << "Address of first element (&a[0])       : " << &a[0] << endl;
   cout << "Array name (a) - address of first elem : " << a << endl;
   cout << "Address of the whole array (&a)        : " << &a << endl;

   int *p = &a[0];
   cout << "\nPointer p (points to a[0])            : " << p << endl;
   cout << "Address of pointer variable p (&p)     : " << &p << endl;
   cout << "Value pointed by p (*p)                : " << *p << endl;

   int *q = &a[2];
   cout << "\nAddress of third element (&a[2])       : " << &a[2] << endl;
   cout << "Pointer q (points to a[2])            : " << q << endl;
   cout << "Address of pointer variable q (&q)     : " << &q << endl;
   cout << "Value pointed by q (*q)                : " << *q << endl;

   return 0;
}

/*
Address of first element (&a[0])       : 0x9f31fffc40
Array name (a) - address of first elem : 0x9f31fffc40
Address of the whole array (&a)        : 0x9f31fffc40

Pointer p (points to a[0])            : 0x9f31fffc40
Address of pointer variable p (&p)     : 0x9f31fffc38
Value pointed by p (*p)                : 10

Address of third element (&a[2])       : 0x9f31fffc48
Pointer q (points to a[2])            : 0x9f31fffc48
Address of pointer variable q (&q)     : 0x9f31fffc30
Value pointed by q (*q)                : 30
*/