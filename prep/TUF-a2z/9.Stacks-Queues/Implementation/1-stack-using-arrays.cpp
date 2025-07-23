#include <iostream>
using namespace std;

class Stack
{
private:
   static const int maxSize = 100;
   int arr[maxSize];
   int topIdx;
   int length;

public:
   Stack() : topIdx(-1), length(0) {}

   bool push(int val)
   {
      if (topIdx == maxSize - 1)
      {
         cout << "Stack Overflow\n";
         return false;
      }
      arr[++topIdx] = val;
      ++length;
      return true;
   }

   bool pop()
   {
      if (topIdx == -1)
      {
         cout << "Stack Underflow\n";
         return false;
      }
      --topIdx;
      --length;
      return true;
   }

   int top()
   {
      if (topIdx == -1)
      {
         cout << "Stack is empty\n";
         return -1; // or throw exception
      }
      return arr[topIdx];
   }

   bool empty()
   {
      return topIdx == -1;
   }

   bool full()
   {
      return topIdx == maxSize - 1;
   }

   int size()
   {
      return length;
   }
};

int main()
{
   Stack s;
   s.push(10);
   s.push(20);
   cout << "Top: " << s.top() << endl;
   s.pop();
   cout << "Top: " << s.top() << endl;
   cout << "Is empty? " << s.empty() << endl;
   cout << "Is full? " << s.full() << endl;
   cout << "Size: " << s.size() << endl;
   return 0;
}
