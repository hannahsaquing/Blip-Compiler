#include <stack>
#include <map>
#include <string>
#include "Parse.h"
#include <iostream>

using namespace std;

map<string, int> variables;

void readInstruction() {
    const char* instruction;
    instruction = next_token();
    /*
     * TO DO: read the char to determine which instruction it needs to use
     */
};

string stringContents() {
    while (peek_next_token() != "//") {
        skip_line();
    }
    read_next_token();
    return next_token();
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

void var() {
    /*
     * initialize new variable
     */
}

void set() {
    /*
     * update existing variable
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
            var();
        }
        if (action == "set") {
            set();
        }
        parseNext();
    }
}

