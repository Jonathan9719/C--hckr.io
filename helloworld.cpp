#include <iostream>
#include <string>

using namespace std;

// Main task: Simple print Hello world
// Improvement: Ask user for name and ouput "Hello ~"
int main() {

    string name; 
    cout << "Please enter your name: ";
    cin >> name;

    cout << "Hello " << name << endl;

    return 0;
}