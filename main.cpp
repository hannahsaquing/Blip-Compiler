#include <iostream>
#include <stack>
#include <map>
#include <string>
#include "Parse.h"
#include "stack.h"
#include "blip.h"

int main() {
    cout << "Test1" << endl;
    set_input("test1.blip");
    run();

    cout   <<   endl   <<   endl   << "Test2"<<   endl;
    set_input("test2.blip");
    run();
}
