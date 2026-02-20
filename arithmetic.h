// src/arithmetic.h

#ifndef ARITHMETIC_H
#define ARITHMETIC_H

#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

#define PI  3.141592653589793
#define E   2.718281828459045

bool isInteger(const string& s);
bool applyOperator(stack<double>& st, const string& op);

string help_msg();

#endif