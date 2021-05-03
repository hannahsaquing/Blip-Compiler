#include <stack>
#include <map>
#include <string>
#include "Parse.h"

using namespace std;

void readInstruction() {
    const char* instruction;
    instruction = next_token();
    /*
     * TO DO: read the char to determine which instruction it needs to use
     */
};

void text() {
    /*
     * print text
     */
}

void output() {
    /*
     * calculate output
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

void tokenParser() {
    read_next_token();
    if (next_token_type == NAME) {
        readInstruction();
    }
    else if (next_token_type == NUMBER) {

    }
}

