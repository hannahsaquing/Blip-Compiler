#include <stack>
#include <map>
#include <string>
#include "Parse.h"
#include <iostream>
using namespace std;

int symbolChecker (string op, int arg1, int arg2);

bool isUnary(string input);

int evaluatePolishNotation(map<string,int> &map);