// pass by value

#include <iostream>
using namespace std;
void update(int a)
{
   a = a / 2;
}

int main()
{

   int a = 10;
   update(a);         // a remains 10
   cout << a << endl; // prints 10

   return 0;
}

// The function update receives a copy of the variable a. Changes to a inside update do not affect the original variable in main.

/*

If you want the update function to modify the original variable, pass it by reference:


void update(int &a) {
    a = a / 2;
}


*/