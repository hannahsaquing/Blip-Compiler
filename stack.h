#include <stack>
#include <map>
#include <string>
#include "Parse.h"
#include <iostream>
using namespace std;

int binaryMath (string op, int arg1, int arg2);

int binaryLogic (string op, int arg1, int arg2);

int compare (string op, int arg1, int arg2);

int unary (string op, int arg);

int command (string op, int arg1, int arg2);

void stackInteractions();

int cleanStack();

int evaluatePolishNotation();