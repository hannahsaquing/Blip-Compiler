#include <stack>
#include <map>
#include <string>
#include <iostream>
#include "blip.h"
#include "Parse.h"
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
    int print = evaluatePolishNotation();
    cout << print;
}


void run() {
    // doesn't run all the way
    read_next_token();
    if (next_token_type == END) {
        return;
    }
    bool keepGoing = next_token_type != END;
    bool execute = (next_token_type == NAME) || (next_token_type == SYMBOL);
    while (keepGoing) {
        if (execute) {
            string action = next_token();
            if (action == "//") {
                skip_line();
            }
            else if (action == "var") {
                var(variables);
            }
            else if (action == "set") {
                set(variables);
            }
            else if (action == "text") {
                text();
            }
            else if (action == "output") {
                output();
            }
        }
        read_next_token();
        keepGoing = (next_token_type != END);
        execute = (next_token_type == NAME) || (next_token_type == SYMBOL);
    }
}
