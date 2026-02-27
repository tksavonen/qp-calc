// src/arithmetic.cpp

#include <iostream>
#include <iomanip>
#include <stack>
#include <vector>
#include <cmath>
#include "arithmetic.h"

using namespace std;

bool isInteger(const string& s) {
    try {
        size_t pos;
        stod(s, &pos);
        return pos == s.length();
    }
    catch (...) {
        return false;
    }
}

double get_sqrt(double val, double epsilon) {
    if (val <= 0) {
        throw invalid_argument("Negative input");
    }
    double x = val;

    while (true) {
        double next = 0.5 * (x + val / x);

        if (abs(next - x) < epsilon) {
            return next;
        }
        x = next;
    }
}

int factorial(int n) {
        int ans = 1;
        for (int i = 2; i <= n; i++) {
            ans = ans * i;
        }
        return ans;
    }

string help_msg() {
    return "\n================ Stack Calculator Help ================\n"
    "   +       Addition                (a b +)\n"
    "   -       Subtraction             (a b -)\n"
    "   *       Multiplication          (a b *)\n"
    "   /       Division                (a b /)\n"
    "   ^       Power                   (a b ^)\n\n"
    "   sqrt    Square root             (a sqrt)\n"
    "   (Takes sqrt accuracy as argument (a 0.1 sqrt) default is 0.0001\n\n"
    "   sin     Sine (radians)          (a sin)\n"
    "   cos     Cosine (radians)        (a cos)\n"
    "   abs     Absolute value          (a abs)\n"
    "   !       Factorial               (a !)\n\n"
    "   x       Exchange two top values (a b x)\n"
    "   s       Sum all values on stack (a b sum)\n"
    "   a       Average of stack values (a b avg)\n\n"
    "   pi      Push π onto stack\n"
    "   e       Push Euler's number onto stack\n\n"
    "   stack   Display all values currently on stack\n"
    "   depth   Show number of values currently on stack\n"
    "   drop    Remove top value from stack\n"
    "   clear   Clear the stack\n"
    "   exit    Quit the calculator\n\n";
}

bool applyOperator(stack<double>& st, const string& op) {
    if (op == "+" || op == "-" || op == "*" || op == "/" || op == "^") {
        if (st.size() < 2) return false;

        double right = st.top(); st.pop();
        double left = st.top(); st.pop();

        if (op == "+") st.push(left + right);
        else if (op == "-") st.push(left - right);
        else if (op == "*") st.push(left * right);
        else if (op == "/") {
            if (right == 0) return false;
            st.push(left / right);
            }
        else if (op == "^") st.push(pow(left, right));

        return true;
    }

    else if (op == "x") {       // exchange operator
        if (st.size() < 2) return false;

        double a = st.top(); st.pop();
        double b = st.top(); st.pop();

        st.push(a);
        st.push(b);
    }

    else if (op == "sqrt") {    // square root operator
        if (st.empty()) return false;

        if (st.size() == 1) {
            double value = st.top(); st.pop();
            st.push(get_sqrt(value, 0.0001));
        }
        else {
            double epsilon = st.top(); st.pop();
            double value   = st.top(); st.pop();
            st.push(get_sqrt(value, epsilon));
        }

        return true;
    }

    else if (op == "sin") {     // sin
        if (st.empty()) return false;

        double val = st.top(); st.pop();
        st.push(sin(val));
        
        return true;
    }

    else if (op == "cos") {     // cos
        if (st.empty()) return false;

        double val = st.top(); st.pop();
        st.push(cos(val));

        return true;
    }

    else if (op == "s") {     // sum operator
        if (st.empty()) return false;

        double sum{};

        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }

        st.push(sum);
    }

    else if (op == "a") {     // average (mean) operator
    	if (st.empty()) return false;

    	double s = 0.0;
    	int c = 0;

    	while (!st.empty()) {
    		s += st.top();
    		st.pop(); c++;
    	}

    	double avg = s/c;
    	st.push(avg);
    }

    else if (op == "abs") {     // absolute value operator
        if (st.size() < 1) return false;

        double value = st.top(); st.pop();

        st.push(fabs(value));
    }

    else if (op == "!") {       // factorial operator
        if (st.size() < 1) return false;

        double value = st.top(); st.pop();

        st.push(factorial(int(value)));
    }

    else if (op == "pi") {      // pi
        st.push(PI); return true;
    }

    else if (op == "e") {       // euler's number
        st.push(E); return true;
    }

    else if (op == "help") {    // help message
        cout << help_msg();
    }

    else if (op == "stack") {   // show stack values
        if (st.empty()) {
            cout << "Stack is empty!\n";
            return true;
        }

        stack<double> temp = st;
        cout << "Stack (top -> bottom): ";
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }

        cout << endl;
        return true;
    }

    else if (op == "depth") {   // show stack size
        cout << "Stack depth: " << st.size() << endl;
        return true;
    }

    else if (op == "drop") {    // drop stack's top value
        if (st.empty()) {
            cout << "Stack is empty!\n";
            return true;
        }

        st.pop();
        return true;
    }

    else if (op == "clear") {   // clear stack
        st = stack<double>();  
        return true;
    }

    else {
        return false;           // unknown operator
    }

    return true;
}
