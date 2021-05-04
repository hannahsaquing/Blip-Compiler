#include <stack>
#include <map>
#include <string>
#include "Parse.h"
#include <iostream>
#include "stack.h"
using namespace std;

map<string, int> variables;

void var(map<string,int> &map) {
    while (peek_next_token() != "//") {
        skip_line();
    }
    read_next_token();
    string varName = next_token();
    int varValue = evaluatePolishNotation();
    // check if it's already in the map
    bool inMap = map.count(varName);
    if (inMap) {
        string str1 = "variable ";
        string str2 = " incorrectly re-initialized";
        cout << str1 << varName << str2 << endl;
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
    int varValue = evaluatePolishNotation();
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