/*
    Learning C++ from Runestone Academy: C++ for Python Programmers
    Piero Orderique
    21 Jan 2021

    Chapters:
    1. Introduction to C++ for Python Programmers
    2. Atomic C++ Data Types
    3. Control Structures
    4. Functions
    5. Collection Data Types
    6. Input and Output
    7. Exception Handling
    8. Graphics in C++
*/

//Ch 1: Introduction to C++ for Python Programmers
/*
    Python:
        dynamic language (performs type checking at runtime)
        interpreted language (aka scripting language)
    C++
        statically typed language (type checking at compile time)
        compiled language / industrial strength language
        OOP: abstraction, inheritance, polymorphism, and encapsulation.
        programmer can use the pointer data type explicitly, which can
            increase control over both memory and performance
        FAST, language of choice for VR and 2D/3D games

    #include = pythons import
        #include <libraryname>
        #include "filename"
    
    No "docstrings" in c++, but use /** * / before classes and funcs 
*/
#include <iostream>
using namespace std;

int main(){
    float num;
    cout << "Give me a number: ";
    cin >> num;
    cout << "Here is your number, doubled: " << num*2 << endl;
    return 0;
}

