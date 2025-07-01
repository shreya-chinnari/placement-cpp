#include <iostream>
#include <cstring> // For strlen and strcpy

class Person
{
private:
   char *name; // Member variable to store name

public:
   // Constructor: Takes input string and demonstrates two types of memory handling
   Person(const char *inputName)
   {
      std::cout << "===== Inside Constructor =====\n";

      // -----------------------------------------------
      // PART 1: Using `this->name` (Member Variable)
      // -----------------------------------------------
      std::cout << "Step 1: Allocating memory for this->name (member variable)\n";

      // Allocate dynamic memory for name and copy inputName into it
      this->name = new char[strlen(inputName) + 1]; // +1 for null terminator
      strcpy(this->name, inputName);                // Deep copy of string into member variable

      std::cout << "this->name points to: " << this->name << std::endl;

      // -----------------------------------------------
      // PART 2: Using `char* ch` (Local Variable)
      // -----------------------------------------------
      std::cout << "\nStep 2: Creating a separate local pointer ch\n";

      // Allocate dynamic memory separately for local pointer `ch`
      char *ch = new char[strlen(inputName) + 1]; // Same size as before
      strcpy(ch, inputName);                      // Deep copy of inputName into ch

      std::cout << "ch points to: " << ch << std::endl;

      // Deallocate memory for ch to avoid memory leak
      delete[] ch;
      std::cout << "\nMemory freed for ch\n";

      // Note: We don’t delete this->name here, because it is a class member.
      // It will be deleted in the destructor.
   }

   // Destructor: Automatically called when object goes out of scope
   ~Person()
   {
      std::cout << "\n===== Inside Destructor =====\n";

      // Free memory that was allocated for this->name
      delete[] name;
      std::cout << "Memory freed for this->name\n";
   }
};

int main()
{
   std::cout << "===== Creating Person Object =====\n";

   const char *sampleName = "Shreya";

   // Create object — triggers constructor
   Person p(sampleName);

   // Object goes out of scope — triggers destructor
   std::cout << "===== Exiting main() =====\n";

   return 0;
}
