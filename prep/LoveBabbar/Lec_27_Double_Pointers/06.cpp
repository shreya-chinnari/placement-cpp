#include <iostream>
using namespace std;

// -------- Pass by Value --------
void passByValue(int x)
{
   cout << "\n[passByValue] Before: x = " << x << endl;
   x = 100; // Changes only local copy
   cout << "[passByValue] After: x = " << x << " (only local x changed)\n";
}

// -------- Pass by Single Pointer --------
void passByPointer(int *x)
{
   cout << "\n[passByPointer] Before: x (address) = " << x << ", *x = " << *x << endl;

   x = nullptr; // Changes local copy of pointer only (does NOT affect main)
   *x = 999;    // ❌ Error: dereferencing nullptr! Will crash if not commented

   // To show proper effect, reset x to valid value first:
   // *x = 999;          // Valid version (if x wasn't null)

   cout << "[passByPointer] After: x = " << x << ", *x = invalid (crashed if dereferenced)\n";

   // Explanation:
   // - Changing `*x` updates value at address ⇒ reflected in main
   // - Changing `x` itself does NOT affect original pointer
}

// -------- Safe Version for Single Pointer --------
void passByPointerSafe(int *x)
{
   cout << "\n[passByPointerSafe] Before: x (address) = " << x << ", *x = " << *x << endl;

   *x = 77;   // Modifies actual value (reflected in main)
   x = x + 1; // Changes local pointer only (no effect in main)

   cout << "[passByPointerSafe] After: x = " << x << ", *x = " << *x << " (main sees updated value, not address)\n";
}

// -------- Pass by Double Pointer --------
void passByDoublePointer(int **x)
{
   static int newVal = 888;

   cout << "\n[passByDoublePointer] Before: x = " << x
        << ", *x = " << *x
        << ", **x = " << **x << endl;

   **x = 55;     // Changes actual value (reflected in main)
   *x = &newVal; // Changes what the original pointer points to (affects main)
   x = nullptr;  // Only affects local copy of double pointer

   cout << "[passByDoublePointer] After: x = nullptr"
        << ", *x = &newVal"
        << ", **x = 888 (updated)\n";

   // Explanation:
   // - `**x` modifies original variable value (like `a`)
   // - `*x = &newVal` makes main's pointer point to different location
   // - `x = nullptr` has no effect outside (just local copy)
}

// =========== MAIN FUNCTION ==============
int main()
{
   int a = 10;
   int *ptr = &a;

   cout << "\n=========================\n";
   cout << "Initial state: a = " << a << ", ptr = " << ptr << ", *ptr = " << *ptr << "\n";
   cout << "=========================\n";

   // ---- PASS BY VALUE ----
   passByValue(a);
   cout << "[main] After passByValue: a = " << a << " (unchanged)\n";

   // ---- PASS BY POINTER (SAFE) ----
   passByPointerSafe(&a);
   cout << "[main] After passByPointerSafe: a = " << a << " (updated to 77)\n";

   // ---- PASS BY POINTER (UNSAFE EXAMPLE: COMMENTED TO AVOID CRASH) ----
   // passByPointer(&a);

   // ---- PASS BY DOUBLE POINTER ----
   cout << "\nBefore passByDoublePointer: a = " << a << ", ptr = " << ptr << ", *ptr = " << *ptr << "\n";
   passByDoublePointer(&ptr);
   cout << "[main] After passByDoublePointer: *ptr = " << *ptr << ", ptr points to new value (888)\n";

   return 0;
}

/*
=========================
Initial state: a = 10, ptr = 0xabbdff7cc, *ptr = 10
=========================

[passByValue] Before: x = 10
[passByValue] After: x = 100 (only local x changed)
[main] After passByValue: a = 10 (unchanged)

[passByPointerSafe] Before: x (address) = 0xabbdff7cc, *x = 10
[passByPointerSafe] After: x = 0xabbdff7d0, *x = -1142949808 (main sees updated value, not address)
[main] After passByPointerSafe: a = 77 (updated to 77)

Before passByDoublePointer: a = 77, ptr = 0xabbdff7cc, *ptr = 77

[passByDoublePointer] Before: x = 0xabbdff7c0, *x = 0xabbdff7cc, **x = 77
[passByDoublePointer] After: x = nullptr, *x = &newVal, **x = 888 (updated)
[main] After passByDoublePointer: *ptr = 888, ptr points to new value (888)

*/