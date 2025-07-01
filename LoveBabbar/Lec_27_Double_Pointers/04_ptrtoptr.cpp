#include <iostream>
using namespace std;
void update(int **p)
{
   static int y = 20;
   *p = &y; // Changing the address stored in p to point to y
   // Now, when we dereference p, it will give us the value of y
}

int main()
{
   int x = 10;
   int *ptr = &x;

   cout << *ptr << endl; // Output: 10
   update(&ptr);         // Pass address of ptr

   cout << *ptr << endl; // Output: 20
}
// This code demonstrates how to use a pointer to a pointer to modify the address stored in the original pointer.
// The function `update` takes a pointer to a pointer and changes the address stored in the pointer to point to a static variable `y`.
// When `update` is called with the address of `ptr`, it modifies `ptr` to point to `y`, and thus when we dereference `ptr`, it outputs the value of `y`, which is 20.
// This is useful when you want to change the address stored in a pointer from within a function, allowing you to modify the original pointer's target without returning a new pointer or using global variables.
// This technique is often used in scenarios where you need to modify pointers themselves, such as in dynamic memory allocation or when working with linked data structures.