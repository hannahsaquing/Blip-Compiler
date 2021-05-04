#include <stack>
#include <string>
#include "Parse.h"
#include "stack.h"
using namespace std;

int symbolChecker (string op, int arg1, int arg2) {
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
/*
int unary (string op, int arg) {
    if (op == "!") {return (!arg);}
    if (op == "~") {return (-1*arg);}
    else {return -1;}
}*/

/*int command (string op, int arg1, int arg2) {
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
*/
bool isUnary(string input) {
    return (input == "!") || (input == "~");
}
/*
void singleStackInteraction() {
    int arg = args.top();
    args.pop();
    string op = ops.top();
    ops.pop();
    result = command(op, arg, 0);
    args.push(result);
}

void stackInteractions() {
    if (args.size() == 2) {
        int arg2 = args.top();
        args.pop();
        int arg1 = args.top();
        args.pop();
        string op = ops.top();
        ops.pop();
        result = command(op, arg1, arg2);
        args.push(result);
    }
    else if (args.size() == 1) {
        int arg1 = args.top();
        args.pop();
        string op = ops.top();
        ops.pop();
        result = command(op, arg1, 0);
        args.push(result);
    }
}

int cleanStack() {
    if (!args.empty()) {
        int parsedValue = args.top();
        args.pop();
        return parsedValue;
    }
    return 0;
}*/

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
        string thingy = next_token(); // when i stuck next_token under, it didn't work. now it works..
        if (thingy == "!") {
            return (!evaluatePolishNotation(variables));
        }
        if (thingy == "~") {
            return (-1 * evaluatePolishNotation(variables));
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
/*int evaluatePolishNotation(variables) {
    read_next_token();
    string blipText = next_token();
    if (next_token_type == NUMBER) {
        return token_number_value;
    }
    ops.push(blipText);
    while (!ops.empty()) {
        read_next_token();

        // put values onto the stack
        if (next_token_type == SYMBOL) {
            ops.push(blipText);
        }
        else if (next_token_type == NUMBER) {
            args.push(token_number_value);
        }

        // check if i need to do operations
        string checkOperator = ops.top();
        if (isUnary(checkOperator) && args.size() >= 1) {
            singleStackInteraction();
        }

    }*/

    /*while (next_token_type != END && next_token_type != NAME) {
        if (next_token_type == SYMBOL) {
            ops.push(blipText);
        }
        else if (next_token_type == NUMBER) {
            args.push(token_number_value);
        }
        if (!(ops.empty())) {
            if (isUnary(ops.top())) {
                singleStackInteraction();
            }
        }
        else if (args.size() == 2) {
            stackInteractions();
        }
        evaluatePolishNotation(variables);
    }
    if (args.empty() && ops.empty()) {
        return cleanStack();
    }
    else {
        stackInteractions();
        return cleanStack();
    }
};*/



