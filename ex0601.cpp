#include <iostream>
#include <vector>

using namespace std;

struct actionElems {
    int first_num;
    int first_denum;
    string action;
    int second_num;
    int second_denum;
};

void reduce(int &numerator, int &denominator) {
    int num = numerator;
    int den = denominator;

    if (numerator == denominator) {
        int temp = numerator;
        numerator /= denominator;
        denominator /= temp;
    } else {
        int gcd;
        int lcm;

        for (;;) {
            if (num == 0) {
                gcd = den;
                break;
            }
            den %= num;

            if (den == 0) {
                gcd = num;
                break;
            }
            num %= den;
        }

        numerator /= gcd;
        denominator /= gcd;
    }
}

class fraction {
private:
    // Internal representation of a fraction as two integers
    int numerator;
    int denominator;
public:
    // Class constructor
    fraction(int n, int d) {
        numerator = n;
        denominator = d;
    }

    // Methods to update the fraction
    void add(fraction f) {
        numerator = (numerator * f.denominator) + (f.numerator * denominator);
        denominator = (denominator * f.denominator);
    }

    void mult(fraction f) {
        numerator = numerator * f.numerator;
        denominator = denominator * f.denominator;
    }

    void div(fraction f) {
        numerator = numerator * f.denominator;
        denominator = f.numerator * denominator;
    }

    // Display method
    void display() {
        reduce(numerator, denominator);
        cout << numerator << " / " << denominator << endl;
    }
};

bool isWhiteSpace(char c) {
    return c != '/' && c != '+' && c != '*' && c != 'd' && c != 'i' && c != 'v';
}


void calculate(actionElems fractionElems, fraction fraction_a, fraction fraction_b) {
    if (fractionElems.action == "+") {
        fraction_a.add(fraction_b);
    }
    if (fractionElems.action == "*") {
        fraction_a.mult(fraction_b);
    }
    if (fractionElems.action == "d") {
        fraction_a.div(fraction_b);
    }

    fraction_a.display();
}

void parseExpression(string expression) {
    int idx = 0;
    char current_char;
    actionElems fractionElems;
    fractionElems.first_num = 0;
    fractionElems.first_denum = 0;
    fractionElems.action = "";
    fractionElems.second_num = 0;
    fractionElems.second_denum = 0;

    while (idx < expression.length()) {
        current_char = expression[idx];
        if (isdigit(current_char)) {
            string current;
            current.push_back(current_char);
            if (!fractionElems.first_num) {
                fractionElems.first_num = stoi(current);
                idx++;
                continue;
            }
            if (!fractionElems.first_denum) {
                fractionElems.first_denum = stoi(current);
                idx++;
                continue;
            }
            if (!fractionElems.second_num) {
                fractionElems.second_num = stoi(current);
                idx++;
                continue;
            }
            if (!fractionElems.second_denum) {
                fractionElems.second_denum = stoi(current);
                idx++;
                continue;
            }
            idx++;
        }
        if (!isWhiteSpace(current_char) && current_char != '/' && fractionElems.action == "") {
            string current;
            current.push_back(current_char);
            fractionElems.action = current;
            idx++;
            continue;
        }
        idx++;
    }

    fraction fraction_a = fraction(fractionElems.first_num, fractionElems.first_denum);
    fraction fraction_b = fraction(fractionElems.second_num, fractionElems.second_denum);

    calculate(fractionElems, fraction_a, fraction_b);
}

int main() {
    vector<string> expressions;
    string expression;

    while (cin) {
        getline(cin, expression);
        if (expression == "") {
            break;
        }
        parseExpression(expression);
    }

    return 0;
}
