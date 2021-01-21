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

    ----------------------- CODE -----------------------
    #include <iostream>
    using namespace std;

    int main(){
        float num;
        cout << "Give me a number: ";
        cin >> num;
        cout << "Here is your number, doubled: " << num*2 << endl;
        return 0;
    }
*/

//Ch 2: Atomic C++ Data Types
/*
    Built-in atomic data types:
        int, float, double, bool, char, pointer
    
    (int) x/y instead of x//y (if x or y is float, else / is int div)
    pow() for exp from cmath library

    booleans true and false are actually represented as 1 and 0, res.
    thus, you can actually assign ints to them (bool isTrue = 4;)

    technically, a variable's data type CANNOT change. 

    POINTERS
        variable that sotres a memory address and can be used to indirectly 
            access data stored at that memory location
        Python requires 2 memory locations for varaibles: 1 for the object 
            reference and 1 for the value itself
        C++ stores the value directly in memory w/out need for either a
            reference or an object!
        This ^ makes access FASTER, but its why we need to declare each 
            variable bc diff types use diff amounts of data
        
        Instead of id to reference the address, we the address-operator &

    POINTER SYNTAX
        HAVE to use a * to declare a pointer that will "point" to the memory address
            of some data type (ex: varType *identifier; // syntax to declare pointer)
        Have a pointer refer to another variable by using the address-of operator
            (ex: variableType *ptrN = &varN;)
            the pointer needs to reference the same type as the variable or constant to which it points!
        DEREFERNCE a pointer, by using the asterisk before the pointer variable
            varN and *ptrN (note the asterisk in front!) reference the same value in the code above.

    NULL POINTER
        nullptr points to nothing (can also use NULL or 0, but nullptr is better)
        null pointer is often used in conditions and/or in logical operations. (like pythons None)

    ----------------------- CODE -----------------------
    #include <iostream>
    #include <cmath>
    #include <string>
    using namespace std;

    int main(){
        bool myBool = -1; // true!
        string strvar = "b"; // double quotes for strings
        char charvar = 'b'; //single for chars
        bool *ptrx; // a pointer!
        ptrx = &myBool; // get myBool's address! (if you forget &, ptrx will store whatevs at location 1)

        cout << pow(5, 3) << endl; // thx cmath library!
        cout << "my bool: " << myBool << endl;  
        cout << "bool's address: " << &myBool << endl; //lets see that memory address!
        cout << "copy of address at ptrx: " << ptrx << endl;
        cout << "dereferencing pointer by *ptrx: " << *ptrx << endl;

        while(ptrx){
            cout << "pointer is not none!" << endl;
            ptrx = nullptr;
        }
        return 0;
    }

*/

//Ch 3: Control Structures
/*
    
*/