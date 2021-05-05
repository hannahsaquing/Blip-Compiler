// Blip Interpreter, Project 8
// EE 312 Spring 2021
// Hannah Mikaela Saquing
// hos252
// Slip days used: <0>

#include <map>
#include <string>
#include "Parse.h"
#include <iostream>
using namespace std;

int symbolChecker (string op, int arg1, int arg2);

bool isUnary(string input);

int evaluatePolishNotation(map<string,int> &map);
