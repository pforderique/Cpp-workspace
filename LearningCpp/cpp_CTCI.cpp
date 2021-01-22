// Classes: CTCI Ch 12: C and C++

/*
NOTES:
    All data members are private by default in C++. use public instead!

    public - members are accessible from outside the class
    private - members can only be accessed/viewed from within class (by either public or private methods)
    protected - members can only be accessed/viewed from within class or inherited classes

    if a class inherits from multiple classes, it will first call the constructors of those classes
        before calling its own constructor. 
        Ex: class C : public B, public A {...}; will call A's constructor, then B's, then its own
*/

// w3 Examples
#include <iostream>
using namespace std;

#define NAME_SIZE 50 // defines a macro

class Person {
    int id; // all members are private by default
    public:
        Person(){
            cout << "person created." << endl;
        }
        void aboutMe(){
            cout << "I am a person." << endl;
        }
        // Encapsulation: keep variables private and use getters and setters
        int getID(){return id;}
        void setID(int id){this->id = id;}
};

class Student : public Person {
    public:
        Student(){
            cout << "that person is a student." << endl;
        }
        void aboutMe(){
            cout << "I am a student." << endl;
        }
        void payTuition(int amount);
};

// you can also define class methods OUTSIDE of class definition (as long as it WAS DECLARED)
void Student::payTuition(int amount){
    cout << "I paid " << amount << " dollars." << endl;
}

class MITStudent : public Student {
    public:
        // first calls Student construct, which first calls Person cons, then student, and then MITStud
        MITStudent(int id){
            cout << "that student is from MIT." << endl; 
        }
        // Polymorphism allows us to perform a single action in different ways
        void payTuition(int amount){
            cout << "just paid " << amount << " dollars to MIT" << endl;
        }
};

void w3schools(){
    Student *p = new Student(); 
    p->aboutMe(); // prints "I am a Student." 
    p->payTuition(60000); // uses -> because p is a pointer and not obj itself
    delete p; // Important! make sure to delete allocated memory

    MITStudent *piero = new MITStudent(1);
    MITStudent tonystark(2); // when declaring obj, dont have to use "new" (unless using pointer)
    piero->payTuition(50000); // calls its own method (polymorphism!) instead of Student's pay tuition
}

// CTCI examples
class CTCIPerson {
    int id; // all members are private by default

    public:
        string name;

        // can also initialize like this: (necessary when the fields are constant or class types)
        CTCIPerson(int a, string n) : id(a), name(n) { 
            cout << "CTCI Person created." << endl;
        }

        // DECONSTRUCTOR cleans up upon object deletion (automatically called when obj is destroyed)
            // virtual bc now when we delete jim (Person *jim = new Student()), the student deconstructor
                // will be called instead 
        virtual ~CTCIPerson(){
            cout << "Deleting a person..." << endl;
            delete &name; // free any memory allocated within class
        }
    
        // what if we want to to use the STUDENT's about me for Person jim? make Person's method virtual!
        virtual void aboutMe(){
            cout << "I am a person." << endl;
        }
        // another reason to use virtual functions:
        // we want our student and teacher classes to have addCourse(), 
        //  but cant really implement it for a single "Person" class
        virtual bool addCourse(string s, string school) = 0; 

        // Encapsulation: keep variables private and use getters and setters
        int getID(){return id;}
        void setID(int id){this->id = id;}
};

class CTCIStudent : public CTCIPerson {
    public:
        CTCIStudent(int a, string n) : CTCIPerson(a, n) { //this is how you "super" in c++
            cout << "CTCI student made" << endl;
        }
        ~CTCIStudent(){
            cout << "deleting a student..." << endl;
        }
        void aboutMe(){
            cout << "I am a student." << endl;
        }
        bool addCourse(string s, string school = "MIT"){ // supports defualt parameters!
            cout << "added course " << s << " to student." << endl;
            return true;
        }
        // operator overloading!
        CTCIStudent operator+(CTCIStudent &other){
            // lol adding doesnt make sense here but you get the point!
        }

};

/*
TEMPLATES
    A way of reusing code to apply the same calss to different data types
    Ex: we can have a list-like data structure that we want to use for lists of various types
*/
template <class T>class ShiftedList
{
    T *array;
    int offset, size;

public:
    ShiftedList(int sz) : offset(0), size(sz){
        array = new T[size];
    }
    ~ShiftedList(){
        delete array;
    }
    void shiftBy(int n){
        offset = (offset + n) % size;
    }
    T getAt(int i){
        return array[convertIndex(i)];
    }
    void setAt(T item, int i){
        array[convertIndex(i)] = item;
    }
private:
    int convertIndex(int i){
        int index = (i - offset) % size;
        while(index < 0) index += size;
        return index;
    }

};

int main(){
    // w3schools();

    // ** cant declare person obj anymore since we have a pure virtual function in class!
    // CTCIPerson bob(7, "bob"); 
    // cout << bob.getID() << bob.name << endl;

    // I need to declare Person's aboutMe as virtual if I want to use Student's method instead!
    CTCIPerson *jim = new CTCIStudent(10, "jim");
    jim->aboutMe();
    // will deconstruct using student class first 
    //then the person class (since its virtual ~Person(){...})
    delete jim; 
    cout << endl;

    // when two pointers equal each other - changing value of one changes the other
    int *p = new int;
    *p = 7; // dereference p and set value to 7
    int *q = p; // pointer q is pointer p
    *q = 8;
    cout << *p << endl; // prints 8

    // references do not have their own memory. 
    // they also cannot be null or reassigned to another piece of memory
    int a = 5;
    int &b = a;
    b = 7;
    cout << a << endl; // prints 7

    // pointer arithmetic
    int *ptr = new int[2];
    ptr[0] = 0;
    ptr[1] = 1;
    // ptr first points to 0
    ptr++; // this will make ptr skip ahead by sizeof(int) bytes (64 for my machine) 
    cout << *ptr << endl;  // so then this will print out 1

    // using the template
    ShiftedList<int> intlist(10);
    intlist.setAt(17, 0);
    cout << intlist.getAt(0) << endl; // prints 17

    return 0;
}