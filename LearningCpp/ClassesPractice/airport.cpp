/*
AIRPORT

Airport structure will have several members 
- airport : contains many planes grouped by airline
- plane : contains passengers and crew. There can also be different airlines
- crew : consists of pilot, copilot, flight attendants
- person : a person has a name, occupation
*/
#include <iostream>
#include <vector>
using namespace std;

class Person {
protected:
    string firstname;
    string lastname;
    string fullname;
    string occupation;

public:
    Person(string occupation, string firstname = "", string lastname = "") 
        : firstname(firstname), lastname(lastname), occupation(occupation) 
    {
        fullname = firstname + " " + lastname;
    }

    string toString() { return occupation + " " + fullname;}

    // getters and setters
    string getFirstName() { return firstname; }
    string getLastName() { return lastname; }
    string getFullName() { return fullname; }

};

class Passenger {

};

// class Pilot : public Person{
//     Plane plane;
//     int id;

// public:
//     Pilot(Plane plane, string firstname="", string lastname="")
//         : Person("pilot", firstname, lastname), plane(plane)
//     {}
// };

// class CoPilot {

// };

// class FlightAttendant {

// };

// class Crew {
//     Pilot pilot;
//     CoPilot copilot;
//     vector<FlightAttendant> attendants;
// public:
//     Crew(Pilot pilot, CoPilot copilot, vector<FlightAttendant> attendants) {

//     }
// };

// class Plane {
// protected:
//     Crew crew;
//     vector<Passenger> passengers;
// public:
//     Plane() {

//     }
// };

// class DeltaPlane {

// };

// class SpiritPlane {

// };

// class AAPlane {

// };

// for testing
int main(int argc, char const *argv[])
{
    Person person1("Accountant", "John", "Wick");
    // Plane plane1("707");
    // Pilot pilot1(plane1, "Henry");
    // cout << pilot1.toString() << endl;

    return 0;
}
