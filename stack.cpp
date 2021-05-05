// Blip Interpreter, Project 8
// EE 312 Spring 2021
// Hannah Mikaela Saquing
// hos252
// Slip days used: <0>

#include <string>
#include "Parse.h"
#include "stack.h"
using namespace std;

int symbolChecker(string op, int arg1, int arg2) {
    if (op == "+") {return (arg1 + arg2);}
    if (op == "-") {return (arg1 - arg2);}
    if (op == "*") {return (arg1 * arg2);}
    if (op == "/") {return (arg1 / arg2);}
    if (op == "%") {return (arg1 % arg2);}
    if (op == "&&") {return (arg1 && arg2);}
    if (op == "||") {return (arg1 || arg2);}
    if (op == "<") {return (arg1 < arg2);}
    if (op == ">") {return (arg1 > arg2);}
    if (op == "==") {return (arg1 == arg2);}
    if (op == "!=") {return (arg1 != arg2);}
    if (op == "<=") {return (arg1 <= arg2);}
    if (op == ">=") {return (arg1 >= arg2);}
    else {return -1;}
}
bool isUnary(string input) {
    return (input == "!") || (input == "~");
}

int evaluatePolishNotation(map<string, int> &variables) {
    read_next_token();
    // add functionality for grabbing a variable from the map
    if (next_token_type == NUMBER) {
        return token_number_value;
    }
    string varName = next_token();
    if (variables.count(varName)) {
        return variables.at(varName);
    }
    if (isUnary(next_token())) {
        string thingy = next_token();
        if (thingy == "!") {
            return (!evaluatePolishNotation(variables));
        }
        if (thingy == "~") {
            return (-1* evaluatePolishNotation(variables));
        }
    }
    if (next_token_type == SYMBOL) {
        string op = next_token();
        int op1 = evaluatePolishNotation(variables);
        int op2 = evaluatePolishNotation(variables);
        return symbolChecker(op, op1, op2);
    }
    return 0;
}



