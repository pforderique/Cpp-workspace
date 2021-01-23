/*
AIRPORT

Airport structure will have several members 
- airport : contains many planes grouped by airline
- plane : contains passengers and crew. There can also be different airlines
- crew : consists of pilot, copilot, flight attendants
- person : a person has a name, occupation
*/
#include <iostream>
using namespace std;

class Person {
    string firstname;
    string lastname;
    string fullname;
    string occupation;

public:
    Person(string firstname, string lastname = "", string occupation = "") 
        : firstname(firstname), lastname(lastname), occupation(occupation) 
    {
        fullname = firstname + " " + lastname;
    }

    string toString() { return fullname + ", " + occupation;}

    // getters and setters
    string getFirstName() { return firstname; }
    string getLastName() { return lastname; }
    string getFullName() { return fullname; }

};

class Pilot {

};

class Plane {

};

// for testing
int main(int argc, char const *argv[])
{
    Person person1("John", "Wick", "Accountant");
    cout << person1.toString() << endl;
    return 0;
}
