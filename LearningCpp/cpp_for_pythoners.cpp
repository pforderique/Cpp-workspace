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
    the switch variable can only be compared for equality with an integer 
        or something called an enumerated constant

    ----------------------- CODE -----------------------
    #include <iostream>
    using namespace std;

    int main(){
        float grade = 95;
        
        if(grade < 80){
            cout << 'C' << endl;
        } 
        else if(grade < 90){
            cout << 'B' << endl;
        }
        else cout << 'A' << endl;
    }

*/

//Ch 4: Functions
/*
    attach an “&” to the end of the type name in the formal parameter list 
        in order to let the compiler know that you intend to use pass by reference

    arrays are automatically passed by reference w/o having to use & in parameter!
    To prevent ourselves from accidentally modifying any of these arrays, 
        we can add the modifier const in the function head (ex: func(const int[] list) {})

    C++ supports Function overloading for either diff data types or # of parameters
    ----------------------- CODE -----------------------
    #include <iostream>
    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    using namespace std;

    double sqrt(double n){
        // returns sqrt of n using Netwons method 
        double root = n/2;    
        int times = 20;

        for(int i = 0; i < 20; i++){
            root = 0.5 * (root + n/root);
        }

        return root;
    }

    void swap(int &var1, int &var2){
        // swaps the values of actual parameters now 
        int temp;
        temp = var1;
        var1 = var2;
        var2 = temp;
    }

    void mutate(int list[]){
        list[0] = -1; // mutates!
    }

    string getRandomChar(int seed){
        // our list of chars
        char alpha[80]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z', ' '};
        srand(seed);
        string s(1, alpha[rand() % 27]);
        return s;
    }

    string getRandomSentence(int seed, int length){
        string sentence = "";
        for(int i = 0; i < length + 1; i++){
            if (i > 0) {
                sentence += getRandomChar(seed*i);
            }
        }
        return sentence;
    }

    int getSentenceScore(string sentence, string target){
        int score = 0;
        for(int i = 0; i < sentence.length(); i++){
            if(sentence[i] == target[i]){ score+=1; }
        }
        return score;
    }

    int main(){
        // int myNum = 47;
        // int myNum2 = 8;
        // cout << "square root of " << myNum << " is: " << sqrt(myNum) << endl; 
        
        // cout << "swapping the numbers " << myNum << " and " << myNum2;
        // swap(myNum, myNum2);
        // cout << " produces " << myNum << " and " << myNum2 << endl;

        // the infinite monkey
        int maxScore = 0;
        const string TARGET = "pie";

        for(int i = 1; i < 1000; i++){
            string sentence = getRandomSentence(i*13, TARGET.length());
            int score = getSentenceScore(sentence, TARGET);
            string prefix = "";

            if(score > maxScore){
                maxScore = score;
                prefix += "*";
            }

            cout << prefix << sentence << " SCORE: " << score << endl;
        }
    }
*/

//Ch 5: Collection Data Types
/*
    Collections sotre multiple values (or 0 or 1)
    ex: Arrays, vectors, strings, sets, and hash tables

    Arrays - ordered collection of identical data types. Can be...
        statically allocated in which the array size is fixed at compile-time and cannot change
            ex: double darray[40]; or int arr[] = {1, 2, 3, 4}
        dynamically allocated uses pointers are used in allocation process so size can change at run-time
            USUALLY, statically is used when speed is essential, and vectors are used if need flexibility
        elements are stored in memory in contiguous memory locations making look-up via index VERY fast
            comes w/ cost of minimal to no error checking
                Means you can accidentially rewrite values in another array while looping past an array!
        To get size, use sizeOf(arr)/sizeOf(arr[0]) since sizeOf() returns byte size
            Because all elements in C++ arrays are the same type, they take the same amount of space 
        In summary, only use fixed arrays for speed

    Vectors - dynamically allocated array
        Unlike Python lists, vectors are homogeneous
        However, vector seems like an obj, so it is not automatically passed by reference
        available through a library called the Standard Template Library (STL) (#include <vector>)
        use .length() to get size

    Strings - act like python strings...
        but apparently you can append characters to them without creating a new string :O

    Hash Tables - pythons dicts
        unordered_map must be included from library <unordered_map>
        In C++, the keyword first is used for the key, and second is used for the associated value.
        .size() to get the length
        hash tables are organized by the location given by the hash function 
            rather than being in any particular order with respect to the keys 
            this makes look-up extremely fast
        Iterators of an unordered_map are implemented using pointers

    Unordered Set - unordered_set
        gotta import as (#include <unordered_set>)
        Unordered_sets allow for fast retrieval of individual elements based on their value
        the value of an element is at the same time its key, that identifies it uniquely
        Keys are immutable, therefore, the elements in an set cannot be modified once in the container
        However, they can be inserted and removed.

    Glossary
        const (immutable) - unable to be modified.
        non-const (mutable) - the ability of an object to be modified.
        word - unit of data used by a particular processor design.

*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void countPastArray(int arr[]){
    for (int i=0; i<=8; i++){ // C++ WILL iterate past your array!
        cout << arr[i] << endl;
        cout << "id: " << &arr[i] << endl;
    }
}

void vectorExample(vector<int> &myvect){ // vector does not pass as ref automatically like array...
    cout << &myvect << endl;
    myvect.reserve(50); // reserve 50 spots (optional, but good idea bc it saves some time)
    for(int i=0; i<50; i++){
        myvect.push_back(i*i);
        cout << myvect[i] << endl;
        cout << "capacity: " << myvect.capacity() << endl;
    }
    // vector capacity upgrades to 100, but now vector had to be copied into a larger memory location :(
    myvect.push_back(4);
    cout << "capacity: " << myvect.capacity() << endl; 
}

void stringExample(){
    string mystring1 = "Hello";
    string mystring2 = "World!";
    string mystring3;

    mystring3 = mystring1 + " " + mystring2;
    cout << mystring3 << endl;

    cout << mystring2 << " begins at ";
    cout << mystring3.find(mystring2) << endl;
}

void hashTableExample(unordered_map<string, string> &sp_to_en){
    sp_to_en = { {"one", "uno"}, {"two", "dos"} }; // can initialize this way
    sp_to_en["three"] = "tres";
    sp_to_en["four"] = "cuatro"; // can also new ones like python

    cout << sp_to_en.size() << endl;
    cout << "one is " << sp_to_en["one"] << endl;

    // Iterators of an unordered_map are implemented using pointers to point to 
    // elements of the value type****************************************************
    for (auto i = sp_to_en.begin(); i != sp_to_en.end(); i++ ){
        //auto is used to automatically detect the data type when
        //a variable is declared. Use this ONLY when declaring complex
        //variables.

        cout << i->first << ":";
        cout << i->second << endl;
    }

}

void setChecker(unordered_set<char> set, char letter){
    if(set.find(letter) == set.end()){
        cout << "letter " << letter << " is not in the set." << endl;
    }
    else{
        cout << "letter " << letter << " is in the set." << endl;
    }
}

int main(){
    int myarray[] = {2,4,6,8};
    int arrsize = sizeof(myarray)/sizeof(myarray[0]); // outputs 4
    // countPastArray(myarray);

    vector<int> intvector;
    cout << &intvector << endl;
    // vectorExample(intvector);
    
    char cppchar = 'a';   // char values use single quotes
    char cstring[] = {"Hello World!"}; // C-string or char array uses double quotes (not recc)
    string cppstring = "Hello World!"; // C++ strings use double quotes - much like python strings
    cout << "address before adding char: " << &cppstring << endl;
    cppstring.push_back('!'); // can also use .append(string) 
    cout << "address after adding char: " << &cppstring << endl;
    // stringExample();

    unordered_map<string, string> spnumbers; //unordered_map is python dict
    // hashTableExample(spnumbers);

    unordered_set<char> charSet = {'d', 'c', 'b', 'a'};
    char letter = 'e';
    setChecker(charSet, letter);
    charSet.insert('e');
    setChecker(charSet, letter);

    return 0;
}