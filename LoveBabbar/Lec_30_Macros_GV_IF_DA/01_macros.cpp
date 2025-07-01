// ✅ 1. Object - like Macros

#include <iostream>
using namespace std;

// Macro definition
#define PI 3.14159

int main()
{
   float radius;

   cout << "Enter radius: ";
   cin >> radius;

   // 1. Area of circle
   float area = PI * radius * radius;

   // 2. Circumference of circle
   float circumference = 2 * PI * radius;

   // 3. Volume of sphere
   float volume = (4.0 / 3) * PI * radius * radius * radius;

   // 4. Surface area of sphere
   float surfaceArea = 4 * PI * radius * radius;

   // Output
   cout << "\n--- Results ---" << endl;
   cout << "Area of Circle: " << area << endl;
   cout << "Circumference: " << circumference << endl;
   cout << "Volume of Sphere: " << volume << endl;
   cout << "Surface Area of Sphere: " << surfaceArea << endl;

   return 0;
}
