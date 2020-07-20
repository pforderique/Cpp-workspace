#include <iostream> //pre-processor directive - allows input and output to streams, like console window
// #include <string> //use this instead to use strings without 'using namespace std' line

/*GENERAL NOTES:
    >>> All operators are basically the same as those from Java
    >>> Without the break statement, the code will "fall through" to the remaining cases until it encounters a break statement.
    >>> y=x++ will set y=to original value of x, AND THEN increment x. y=++x, will increment x, and then set y=to NEW value of x
*/

//two ways to initialize variables
int myVar = 0;
int yourVar{1}; 
//USE CONSTs ANYWHERE YOU CAN - helps save you from errors later on! int const or const int
const double pi{3.14};
//namespace
using namespace std;

int main()  //all must have a main method! int is return type
{
    //widening/expanding conversion:
    int myInt = 12;
    long myLong;
    myLong = myInt; //c++ implicitly casts int to double
    //static_cast to convert to or from numeric values
    char ch = static_cast<char>(33);   // int to char
    //auto will figure out the type based on initialization. Hovwer over i to see what it is
    auto num = 3/2;

    //ARRAYS
    cout << "ARRAYS OUTPUT:" << endl;
    int arrayName[10]; //ints 0-9
    int arrayName2[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int arrayName3[10] = {1, 2, 3}; //you can declare an array but only initialize some elements! rest will be initialized to 0
    //accessing
    int firstNum = arrayName2[0];
    int errorBound = arrayName2[20]; //OUT OF COUNDS WILL STILL RUN! There is no runtime error. HOWEVER, data returned makes no sense
        /*Why does it still return something?
            The reason for this is because an array is simply a pointer to a memory location. 
            The first element of the array is the starting memory address for the entire array. 
            If you have an array of integer data types, then the number of the elements multiplied 
                by the size of the int data type on your system, determines how much memory is used by the array, 
                and at the same time, permits the access of the elements in the array by performing 
                math on the memory address to get at the required element. 
            If you attempt to access oldNumbers[5], the program will simply return the data found at the memory 
                address that is the next memory address location beyond the last array element. 
            This can be a dangerous situation and is in fact, the result of some security issues found in software.*/
    //Iterating Over an Array
    int oldNumbers[] = { 1, 2, 3, 4, 5 };
    for (int n = 0; n < 5; n++){ std::cout << oldNumbers[n];}
    cout << "\n";

    //STRINGS
    cout << "\nSTRINGS OUTPUT:" << endl;
    char isAString[6] = { 'H', 'e', 'l', 'l', 'o', '\0'}; //LAST CHAR MUST BE THE NULL CHARACTER \0
    char isNotAString[5] = { 'H', 'e', 'l', 'l', 'o'};
    char betterIsAString[6] = "Hello"; //you STILL have to account for \0 that gets put at end by saying arr[6] instead of arr[5]
    char betterString[] = "Length of this string is inferred.";
    string myString = "I can use string class because I am using namespace std"; //normally std::string name = ...

    //Structures - like classes, or Python's Tuples
    cout << "\nSTRUCTURES OUTPUT:" << endl;
    struct coffeeBean
    {
        string name;
        string country;
        int strength;
    };
    coffeeBean myBean = { "Strata", "Colombia", 10 };
    coffeeBean newBean;
    newBean.name = "Flora";
    newBean.country = "Mexico";
    newBean.strength = 9;
    cout << "Coffee bean " + newBean.name + " is from " + newBean.country << endl;

    //UNIONS - can only store a value in ONE of its fields at a time
    cout << "\nUNIONS OUTPUT:" << endl;
    union numericUnion
    {
        int intValue;
        long longValue;
        double doubleValue;
    };
    numericUnion myUnion;
    myUnion.intValue = 3;
    cout << myUnion.intValue << endl;
    myUnion.doubleValue = 4.5;
    cout << myUnion.doubleValue << endl;
    cout << myUnion.intValue; cout << endl; //outputs 0 becuase we initialized another varaible of this structure
    //why use this? Well, what if your device has limited memory...?

    //ENNUMERATIONS - like Python's Dictionaries
    cout << "\nENNUMERATIONS OUTPUT:" << endl;
    enum Day { Sunday = 1, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday }; //use when there only a few possible values for your variable
    //By default enum values start at 0 and each successive member is increased by a value of 1. 
    //By putting Sunday=1, Monday will now equal 2, Tuesday=3, and so on
    Day payDay;
    payDay = Thursday;
    cout << payDay << endl;

    //CONDITIONAL OPERATOR
    cout << "\nCONTIONAL OPERATOR OUTPUT:" << endl;
    int i = 1, j = 2;
    cout << ( i > j ? i : j ) << " is greater." << endl; //checks conditional, outputs based on which is higher

    //INLINE FUNCTIONS - avoid the overhead associated with traditional function calls
    cout << "\nINLINE FUNCTION OUTPUT:" << endl;
    int test1 = 8;
    int test2 = 10;
    ::swap(test1, test2); //:: by itself is used to declare that swap is from your own namespace and not std's
    cout << "Test1 equals " << test1 << " Test2 equals " << test2 << endl;

    std::cout << "\n"+myString; //std:: indicates that cout is part of std namespace


    return 0;    //COULD return 0 if executed correctly or non-zero if failed
}

// each time that a call to the swap() method is encountered in your code, 
//the compiler will insert the body of the function in that location as opposed to making a function call
inline void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}