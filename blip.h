#include <stack>
#include <map>
#include <string>
#include "Parse.h"
#include <iostream>
#include "stack.h"
using namespace std;

map<string, int> variables;

void var(map<string,int> &map);

void set(map<string,int> &map);

void text();

void output();

void run();

