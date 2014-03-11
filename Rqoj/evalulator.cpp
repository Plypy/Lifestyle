#include <iostream>
#include <cstdlib>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <climits>
#include <stack>
#include <cctype>
using namespace std;

int weight[CHAR_MAX];
void init() {
	weight['#'] = 0;
	weight['-'] = weight['+'] = 1;
	weight['*'] = weight['/'] = 2;
	weight['^'] = 3;
}

double operate(double a, double b, char otr) {
	switch (otr) {
	case '+':
		return a+b;
	case '-':
		return a-b;
	case '*':
		return a*b;
	case '/':
		return a/b;
	case '^':
		return pow(a,b);
	default:
		return 0.0;
	}
}
double cal(string expr) {
	istringstream stin(expr+"#");
	stack<double> nst;
	stack<char> opst;
	while (true) {
		char tchar = stin.get();
		if (!stin)
			break;
		if (' ' == tchar)
			continue;
		if (isdigit(tchar) || '.' == tchar) {
			stin.putback(tchar);
			double tval;
			stin >> tval;
			nst.push(tval);
		} else if ('(' == tchar) {
			opst.push('(');
		} else if (')' == tchar) {
			while ('(' != opst.top()) {
				double b = nst.top();
				nst.pop();

				double a = nst.top();
				nst.pop();

				char otr = opst.top();
				opst.pop();
				nst.push(operate(a,b,otr));
			}
			opst.pop();
		} else {
			while (!opst.empty() && weight[tchar] <= weight[opst.top()]) {
				double b = nst.top();
				nst.pop();

				double a = nst.top();
				nst.pop();

				char otr = opst.top();
				opst.pop();
				nst.push(operate(a,b,otr));
			}
			opst.push(tchar);
		}
	}

	return nst.top();
}

int main() {
	init();
	while (true) {
		string expr;
		getline(cin,expr);
		if ("quit" == expr)
			break;
		cout << cal(expr) << endl;
	}
	cout << "Bye bye!" << endl;
}