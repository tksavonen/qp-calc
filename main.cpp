// src/main.cpp
// QP-calc (Quick Postfix calculator)
// COMPILES WITH 'g++ -std=c++11 *.cpp -o qp-calc'

#include <iostream>
#include <sstream> 
#include <stack>
#include <vector>
#include <cmath>
#include "arithmetic.h"

using namespace std;

int main() {
    string exp;
    stack<double> st;

    cout << "QP-calc" << endl << "Type 'help' for commands" << endl << endl;

    while (true) {
        cout << "> ";
        getline(cin >> ws, exp);

        if (exp == "exit")
            break;

        stringstream ss(exp);
        string token;

        while (ss >> token) {
            if (isInteger(token)) {
                st.push(stod(token));
            }
            else {
                if (!applyOperator(st, token)) {
                    cout << "Illegal operation.\n";
                    break;
                }
            }
        }

        if (!st.empty()) {
            cout << "= " << st.top() << endl;
        }

        cout << endl;
    }
}