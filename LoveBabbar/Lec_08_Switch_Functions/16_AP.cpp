// arithmetic progression

#include <iostream>
using namespace std;

int AP(int a, int n, int d)
{
   int ans = a * (n - 1) * d;
   return ans;
}

int main()
{
   int a, n, d;

   cout << "enter 'a' : " << endl;
   cin >> a;
   cout << "enter 'd' : " << endl;
   cin >> d;
   cout << "AP: " << "a+(n-1)d" << endl;
   cout << "enter 'n' (nth term) : " << endl;
   cin >> n;

   int nth_term = AP(a, n, d);
   cout << "nth term is : " << nth_term;
   return 0;
}