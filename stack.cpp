#include <stack>
#include <map>
#include <string>
#include "Parse.h"
#include <iostream>
using namespace std;

map<string, int> variables;
stack <int> args;
stack <string> ops;

int stackToken = 0;
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

void stackInteractions() {
    int arg1 = args.top();
    args.pop();
    int arg2 = args.top();
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

int parsePolish() {
    read_next_token();
    string holder = next_token();
    while (next_token_type != END) {
        if (stackToken == 2) {
            stackInteractions();
        }
        else if (next_token_type == SYMBOL) {
            ops.push(holder);
            stackToken = 0;
        }
        else if (next_token_type == NUMBER) {
            args.push(token_number_value);
            stackToken++;
        }
        parsePolish();
    }
    if (args.empty() && ops.empty()) {
        return cleanStack();
    }
    else {
        stackInteractions();
        return cleanStack();
    }
};

void text() {
    read_next_token();
    string print = next_token();
    cout << print;
}

void output() {
    /*
     * use stack to control output
     */
}

void var(map<string,int> &map) {
    while (peek_next_token() != "//") {
        skip_line();
    }
    read_next_token();
    string varName = next_token();
    int varValue = parsePolish();
    // check if it's already in the map
    bool inMap = map.count(varName);
    if (inMap) {
        string str1 = "variable ";
        string str2 = " incorrectly";
        string str3 =  " re-initialized";
        cout << str1 << varName << str2 << str3 << endl;
        // update it anyways
        map[varName] = varValue;
    }
    else {
        map.emplace(varName, varValue);
    }
}

void set(map<string,int> &map) {
    while (peek_next_token() != "//") {
        skip_line();
    }
    read_next_token();
    string varName = next_token();
    int varValue = parsePolish();
    bool inMap = map.count(varName);
    if (!inMap) {
        string str1 = "variable ";
        string str2 = " not declared";
        cout << str1 << varName << str2 << endl;
        // create the variable anyways
        map.emplace(varName, varValue);
    }
    else {
        map[varName] = varValue;
    }
}

void parseNext() {
    read_next_token();
    if (next_token_type == END) {
        return;
    }
    bool execute = (next_token_type == NAME) || (next_token_type == SYMBOL);
    if (execute) {
        string action = next_token();
        if (action == "text") {
            text();
        }
        if (action == "output") {
            output();
        }
        if (action == "var") {
            var(variables);
        }
        if (action == "set") {
            set(variables);
        }
        parseNext();
    }
}

