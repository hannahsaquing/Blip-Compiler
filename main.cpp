#include <iostream>
#include <stack>
#include <map>
#include <string>
#include "Parse.h"
#include "stack.h"
#include "blip.h"

int main() {
    cout << "Start of Test 1" << endl;
    set_input("test1.blip");
    run();
    cout << endl << "----------- end of Test 1 -----------" << endl;

    cout << "Start of Test 2" << endl;
    set_input("test2.blip");
    run();
    cout << endl << "----------- end of Test 2 -----------" << endl;

    cout << "Start of Test 3" << endl;
    set_input("test3.blip");
    run();
    cout << endl << "----------- end of Test 3 -----------" << endl;

    cout << "Start of Test 4" << endl;
    set_input("test4.blip");
    run();
    cout << endl << "----------- end of Test 4 -----------" << endl;

}
