#include <stack>
#include <map>
#include <string>
#include <iostream>
#include "Parse.h"
#include "stack.h"
using namespace std;

void var(map<string,int> &map);

void set(map<string,int> &map);

void text();

void output();

void run();

struct variable {
    int value;
    string name;
} ;

