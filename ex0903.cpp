#include <iostream>
#include <vector>

using namespace std;

string palindrome(int start, int end, vector<int> numbers) {
    if (start >= end) {
        return "yes";
    }
    if (numbers[start] != numbers[end]) {
        return "no";
    }
    return palindrome(++start, --end, numbers);
}

int main() {
    int n;
    vector<int> numbers;

//    cin >> n;
//    while(cin) {
//        numbers.push_back(n);
//        cin >> n;
//    }

    numbers.push_back(13);
    numbers.push_back(22);
    numbers.push_back(33);
    numbers.push_back(22);
    numbers.push_back(13);

    cout << palindrome(0, numbers.size() - 1, numbers);

    return 0;
}
