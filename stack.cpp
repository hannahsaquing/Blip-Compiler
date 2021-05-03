#include <stack>
#include <map>
#include <string>
#include "Parse.h"
#include <iostream>

using namespace std;

map<string, int> variables;

string stringContents() {
    while (peek_next_token() != "//") {
        skip_line();
    }
    read_next_token();
    return next_token();
}

int calculate() {
    /*
     * implement stack to decipher value of expressions
     */
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
    int value = calculate;
    // check if it's already in the map
    bool inMap = map.count(varName);
    if (inMap) {
        string str1 = "variable ";
        string str2 = " incorrectly";
        string str3 =  " re-initialized";
        cout << str1 << varName << str2 << str3 << endl;
        // update it anyways
        map[varName] = value;
    }
    else {
        map.emplace(varName, value);
    }
}

void set() {
    while (peek_next_token() != "//") {
        skip_line();
    }
    read_next_token();
    string varName = next_token();
    int value
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
            set();
        }
        parseNext();
    }
}

