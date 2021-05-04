#include <stack>
#include <map>
#include <string>
#include "Parse.h"
#include <iostream>
using namespace std;

int symbolChecker (string op, int arg1, int arg2);

int unary (string op, int arg);

void stackInteractions();

int cleanStack();

int evaluatePolishNotation(map<string,int> &map);