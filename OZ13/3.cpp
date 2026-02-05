#include <iostream>
#include <string>
using namespace std;

int main() {
    string s, res;
    getline(cin, s);
    int depth = 0;
    for (char c : s) {
        if (depth == 0) {
            if (c == '(') {
                depth++;
                res += ' ';
            }
            else res += c;
        }
        else if (c == ')') depth--;
    }
    cout << res;
}