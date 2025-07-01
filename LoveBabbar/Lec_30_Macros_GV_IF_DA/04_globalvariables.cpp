#include <iostream>
using namespace std;

// ✅ Renamed from 'count' to avoid macro conflicts
int globalCount = 0;
const int MAX_LIMIT = 100;

void printCount()
{
   cout << "[printCount] Current count is: " << globalCount << endl;
}

void incrementCount()
{
   globalCount++;
   cout << "[incrementCount] Count incremented to: " << globalCount << endl;
}

void checkLimit()
{
   if (globalCount < MAX_LIMIT)
      cout << "[checkLimit] Within limit.\n";
   else
      cout << "[checkLimit] Limit exceeded!\n";
}

void shadowVariable()
{
   int localCount = 10;
   cout << "[shadowVariable] Local variable: " << localCount << endl;
   cout << "[shadowVariable] Global count: " << globalCount << endl;
}

void recursiveDecrement()
{
   if (globalCount <= 0)
      return;
   cout << "[recursiveDecrement] count = " << globalCount << endl;
   globalCount--;
   recursiveDecrement();
}

int main()
{
   cout << "Initial count: " << globalCount << "\n";

   printCount();
   incrementCount();
   checkLimit();
   shadowVariable();
   incrementCount();
   incrementCount();
   printCount();

   cout << "\nNow testing recursion using global count:\n";
   recursiveDecrement();

   cout << "\nFinal global count: " << globalCount << endl;
   return 0;
}

/*
Initial count: 0
[printCount] Current count is: 0
[incrementCount] Count incremented to: 1
[checkLimit] Within limit.
[shadowVariable] Local variable: 10
[shadowVariable] Global count: 1
[incrementCount] Count incremented to: 2
[incrementCount] Count incremented to: 3
[printCount] Current count is: 3

Now testing recursion using global count:
[recursiveDecrement] count = 3
[recursiveDecrement] count = 2
[recursiveDecrement] count = 1

Final global count: 0
*/