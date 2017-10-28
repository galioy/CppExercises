#include <iostream>
#include <set>

using namespace std;

set<int> bag_a;
string command;
int input;
char result;

char processInput() {
    cin >> command;
    cin >> input;

    if (command == "add") {
        bag_a.insert(input);
        return processInput();
    } else if (command == "del") {
        bag_a.erase(input);
        return processInput();
    } else if (command == "qry") {
        int is_in;
        is_in = bag_a.count(input);
        if (is_in == 1) {
            return 'T';
        } else {
            return 'F';
        }
    } else if (command == "quit") {
        return 'Q';
    }
}

int main() {
    result = processInput();
    while(result != 'Q'){
        if(result == 'T' || result == 'F'){
            cout << result;
            result = processInput();
        }
    }

    return 0;
}
