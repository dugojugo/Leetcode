#include <iostream>
#include <string>
#include <stack>
#include <algorithm> // for reverse
#include <cassert>

using namespace std;
string minRemoveToMakeValid(string s) {
    int cal_open = 0;
    int cal_close = 0;
    stack<char> d;
    string s_new = "";
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            cal_open++;
        }
        else if (s[i] == ')') {
            cal_close++;
        }
        if (cal_close > cal_open) {
            cal_close--;
            continue;
        }
        else {
            d.push(s[i]);
        }
    }
    while (!d.empty()) {
        char curr = d.top();
        d.pop();
        if (cal_close < cal_open && curr == '(') {
            cal_open--;
            continue;
        }
        else {
            s_new += curr;
        }
    }
    reverse(s_new.begin(), s_new.end());
    return s_new;
}
void testCases() {
    // Test Case 1
    string input1 = "lee(t(c)o)de)";
    string expected1 = "lee(t(c)o)de";
    string result1 = minRemoveToMakeValid(input1);
    assert(result1 == expected1);
    cout << "Test Case 1 Passed" << endl;

    // Test Case 2
    string input2 = "a)b(c)d";
    string expected2 = "ab(c)d";
    string result2 = minRemoveToMakeValid(input2);
    assert(result2 == expected2);
    cout << "Test Case 2 Passed" << endl;

    // Test Case 3
    string input3 = "))(((";
    string expected3 = "";
    string result3 = minRemoveToMakeValid(input3);
    assert(result3 == expected3);
    cout << "Test Case 3 Passed" << endl;
}

int main() {
    testCases();
    cout << "All test cases passed successfully!" << endl;
    return 0;
}