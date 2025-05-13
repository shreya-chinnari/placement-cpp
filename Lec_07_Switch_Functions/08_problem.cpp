// total amount of money: 1330
// how many 100,50,20,10,5,1 notes for 1330rs

#include <iostream>
using namespace std;

int main()
{
   int amount;
   cout << "Enter the amount: ";
   cin >> amount;

   int step = 1;
   while (step <= 6)
   {
      switch (step)
      {
      case 1:
         cout << "no. of 100rs notes:" << amount / 100 << endl;
         amount = amount % 100;
         break;

      case 2:
         cout << "no. of 50rs notes:" << amount / 50 << endl;
         amount = amount % 50;
         break;

      case 3:
         cout << "no. of 20rs notes:" << amount / 20 << endl;
         amount = amount % 20;
         break;

      case 4:
         cout << "no. of 10rs notes:" << amount / 10 << endl;
         amount = amount % 10;
         break;

      case 5:
         cout << "no. of 5rs notes:" << amount / 5 << endl;
         amount = amount % 5;
         break;

      case 6:
         cout << "no. of 1rs notes:" << amount / 1 << endl;
         amount = amount % 1;
         break;
      }
      step++; // increment step to move to the next denomination
   }
   return 0;
}