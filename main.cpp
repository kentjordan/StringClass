
#include <iostream>
#include "String.h"

using namespace std;

int main() {

    cout << boolalpha;

    String name = "KenT!@#$%123";
    -name; // Make letters to lower

    cout << "String name: " << name.getString() << endl;

    String test = "test, ";
    test *= 3; // Multiply string "test" to 3
    cout << "String test: " << test.getString() << endl; // Print the string test

    String len = "AS12";
    cout << "length: " <<  len.length() << endl; // Get the string length of len

    String kent = test; // Assign kent to 3 "test"
    cout << "String kent: " << kent.getString() << endl;

    String concat = name + test; // Concat "kent!@#$%123" and 3 "test";
    cout << "String concat: " << concat.getString() << endl;

    String x = "KENT";
    String y = "JORDAN";

    // Comparison
    cout << (x == y) << endl;
    cout << (x != y) << endl;
    cout << (x > y) << endl;
    cout << (x < y) << endl;

    String z = x * 3; // Multiply "KENT" string to 3
    cout << z.getString() << endl;

}
