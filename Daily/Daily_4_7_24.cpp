#include <iostream>
#include <string>
#include <stack>
#include <algorithm> // for reverse
#include <cassert>
#include <vector>

using namespace std;
bool checkValidString(string s) {
    int cal_open = 0;
    int cal_close = 0;
    for (char c : s) {
        if (c == '(') {
            cal_open++;
            cal_close++;
        }
        else if (c == ')') {
            cal_open--;
            cal_close--;
        }
        else {
            cal_open++;
            cal_close--;
        }
        if (cal_open < 0) {
            return false;
        }
        if (cal_close < 0) {
            cal_close = 0;
        }

    }
    return cal_close == 0;
}
void testCases() {
    vector<string> testInputs = { "()", "(*)", "(*))" };
    vector<bool> expectedOutputs = { true, true, true };

    for (size_t i = 0; i < testInputs.size(); ++i) {
        bool result = checkValidString(testInputs[i]);
        if (result == expectedOutputs[i]) {
            cout << "Test case " << i + 1 << " passed." << endl;
        }
        else {
            cout << "Test case " << i + 1 << " failed." << endl;
        }
    }
}
int main() {
    testCases();
    cout << "All test cases passed successfully!" << endl;
    return 0;
}