#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int distance(string sA, string sB, int len_a, int len_b) {
    if (len_a == 0 && len_b == 0) {
        return 0;
    }
    if (len_a == 0) {
        return len_b;
    }
    if (len_b == 0) {
        return len_a;
    }

    int a = distance(sA, sB, len_a - 1, len_b - 1) + (sA[len_a - 1] != sB[len_b - 1]);
    int b = distance(sA, sB, len_a - 1, len_b) + 1;
    int c = distance(sA, sB, len_a, len_b - 1) + 1;

    return min(min(a, b), c);
}

int main() {
    string a;
    string b;

    cin >> a;
    cin >> b;

    cout << distance(a, b, a.size(), b.size());

    return 0;
}
