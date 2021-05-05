// Blip Interpreter, Project 8
// EE 312 Spring 2021
// Hannah Mikaela Saquing
// hos252
// Slip days used: <0>

#include <map>
#include <string>
#include <iostream>
#include "blip.h"
#include "stack.h"
using namespace std;

map<string, int> variables;

/*
 * Eliminate comments will skip all lines when a comment is found to ignore that
 */

void eliminateComments() {
    string peek = peek_next_token();
    while (peek == "//") {
        skip_line();
    }
}

/* var statements initialize a new variable.
 * If a var statement specifies a variable that already exists, * then Blip must generate a warning (not an error),
 * with the text, “variable <varName> incorrectly re-initialized”, where <VarName> is the variable’s name.
 * Regardless of whether the warning message is created, the result of a var statement is to ensure that
 * there is a variable in the Blip internal memory with the specified value.  * The variable must be set to
 * the value of a legalBlip expression. The syntax is: “var <varName> <expr>”.
 *
 * The following are examples of legal var expressions
 * var x 42
 * var y + x1
 */

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

/*
 * set statements are just like var statements, except a set statement should be used to re-assign a new value
 * to an existing variable. As such, if a set statement specifies a variable that does not already exist,
 * then Blip must generate a warning (not an error) with the text, “variable <varName> not declared”.
 * Regardless of whether the warning message is created, the result of a set statement is to ensure that there
 * is a variable in the Blip internal memory with the specified value. The following are examples of legal
 * set expressions
 *
 * set x 42
 * set x + x 1
 */

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
    } else {
        map[blippyVar.name] = blippyVar.value;
    }
}

/* Text Function
 * The text message can be either a single word, or a quoted string.
 * Text statements result in a text message being displayed on the screen.
 *
 * text Hello
 * text “Hello World”
 */

void text() {
    read_next_token();
    cout << next_token();
}

/* Output Function
 * Output statements result in a number being displayed on the screen.
 * The number displayed is the result of evaluating any legal Blip expression.
 * For now, Blip only supports integer variables, and so only integer values can be displayed.
 *
 * output 42
 * output + 11
 * output * xx
 * output + * x x * yy
 * */

void output(map<string,int> &map) {
    string peek = peek_next_token();
    int print = (variables.count(peek)) ? variables.at(peek):evaluatePolishNotation(variables);
    cout << print;
}
/*
 * Please write your own‘run()’ function that will read and execute the blip program.
 * Main.cpp should look like this:
 *
 * cout << "Test1" << endl;
 * set_input("test1.blip");
 * run();
 */

void run() {
    read_next_token();
    bool keepGoing = next_token_type != END;
    if (!keepGoing) {
        return;
    }
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
        // check if you should keep going in the loop
        read_next_token();
        keepGoing = (next_token_type != END);
        execute = (next_token_type == NAME) || (next_token_type == SYMBOL);
    }
}
