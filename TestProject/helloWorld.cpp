/*
    Hello World program: started in august 2020
    Picked back up 18 Jan 2021

    To run: 
    1) Ctrl+Shift+B to build this file into an exe
    2) type .\programNameHere w/out .cpp to run in terminal
*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    vector<string> msg {"Hello", "C++", "World", "from", "VS Code", "and the C++ extension!"};
    
    for (const string& word : msg)
    {
        cout << word << " ";
    }
    cout << endl;
}