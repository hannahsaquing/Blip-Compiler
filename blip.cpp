#include <map>
#include <string>
#include <iostream>
#include "blip.h"
#include "stack.h"
using namespace std;

map<string, int> variables;

void eliminateComments() {
    string peek = peek_next_token();
    while (peek == "//") {
        skip_line();
    }
}

void var(map<string,int> &map) {
    eliminateComments(); // skip whitespace until token is found
    read_next_token();
    variable blippyVar;
    blippyVar.name = next_token();
    blippyVar.value = evaluatePolishNotation(variables);

    // check if it's already in the map
    bool inMap = map.count(blippyVar.name);
    if (inMap) {
        string str1 = "variable ";
        string str2 = " incorrectly re-initialized";
        cout << str1 << blippyVar.name << str2 << endl;

        // update it anyways
        map[blippyVar.name] = blippyVar.value;
    }
    else {
        map.emplace(blippyVar.name, blippyVar.value);
    }
}

void set(map<string,int> &map) {
    eliminateComments();
    read_next_token();
    variable blippyVar;
    blippyVar.name = next_token();
    blippyVar.value = evaluatePolishNotation(variables);
    bool inMap = map.count(blippyVar.name);
    if (!inMap) {
        string str1 = "variable ";
        string str2 = " not declared";
        cout << str1 << blippyVar.name << str2 << endl;

        // create the variable anyways
        map.emplace(blippyVar.name, blippyVar.value);
    }
    else {
        map[blippyVar.name] = blippyVar.value;
    }
}

void text() {
    read_next_token();
    cout << next_token();
}

void output(map<string,int> &map) {
    string peek = peek_next_token();
    int print = (variables.count(peek)) ? variables.at(peek):evaluatePolishNotation(variables);
    cout << print;
}

void run() {
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
                output(variables);
            }
        }
        read_next_token();
        keepGoing = (next_token_type != END);
        execute = (next_token_type == NAME) || (next_token_type == SYMBOL);
    }
}
