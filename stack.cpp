#include <stack>
#include <map>
#include <string>
#include "Parse.h"
#include <iostream>
#include "stack.h"
using namespace std;

stack <int> args;
stack <string> ops;

int result = 0;

int binaryMath (string op, int arg1, int arg2) {
    if (op == "+") {return (arg1 + arg2);}
    if (op == "-") {return (arg1 - arg2);}
    if (op == "*") {return (arg1 * arg2);}
    if (op == "/") {return (arg1 / arg2);}
    if (op == "%") {return (arg1 % arg2);}
    else {return -1;}
}

int binaryLogic (string op, int arg1, int arg2) {
    if (op == "&&") {return (arg1 && arg2);}
    if (op == "||") {return (arg1 || arg2);}
    else {return -1;}
}

int compare (string op, int arg1, int arg2) {
    if (op == "<") {return (arg1 < arg2);}
    if (op == ">") {return (arg1 > arg2);}
    if (op == "==") {return (arg1 == arg2);}
    if (op == "!=") {return (arg1 != arg2);}
    if (op == "<=") {return (arg1 <= arg2);}
    if (op == ">=") {return (arg1 >= arg2);}
    else {return -1;}
}

int unary (string op, int arg) {
    if (op == "!") {return (!arg);}
    if (op == "~") {return (-1*arg);}
    else {return -1;}
}

int command (string op, int arg1, int arg2) {
    int result = 0;
    if ((op == "+") || (op == "-") || (op == "*") || (op == "%")) {
        result = binaryMath(op, arg1, arg2);
    }
    else if ((op == "&&") || (op == "||")) {
        result = binaryLogic(op, arg1, arg2);
    }
    else if ((op == "<") || (op == ">") || (op == "==") || (op == "!=") || (op == "<=") || (op == ">=")) {
        result = compare(op, arg1, arg2);
    }
    else if ((op == "!") || (op == "~")) {
        result = unary(op, arg1);
    }
    return result;
}

bool isUnary(string input) {
    return (input == "!") || (input == "~");
}

void singleStackInteraction() {
    int arg = args.top();
    args.pop();
    string op = ops.top();
    ops.pop();
    result = command(op, arg, 0);
    args.push(result);
}

void stackInteractions() {
    int arg2 = args.top();
    args.pop();
    int arg1 = args.top();
    args.pop();
    string op = ops.top();
    ops.pop();
    result = command(op, arg1, arg2);
    args.push(result);
}

int cleanStack() {
    int parsedValue = args.top();
    args.pop();
    return parsedValue;
}

int evaluatePolishNotation() {
    read_next_token();
    string holder = next_token();
    while (next_token_type != END) {
        if (isUnary(ops.top())) {
            singleStackInteraction();
        }
        if (args.size() == 2) {
            stackInteractions();
        }
        else if (next_token_type == SYMBOL) {
            ops.push(holder);
        }
        else if (next_token_type == NUMBER) {
            args.push(token_number_value);
        }
        evaluatePolishNotation();
    }
    if (args.empty() && ops.empty()) {
        return cleanStack();
    }
    else {
        stackInteractions();
        return cleanStack();
    }
};



