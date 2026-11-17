#include <string>
#include <stack>
#include <cctype>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
        stack<int> countStack;
        stack<string> stringStack;
        string currentString = "";
        int k = 0;

        for (char ch : s) {
            if (isdigit(ch)) {
                // Build multi-digit repeat numbers like 100[a]
                k = k * 10 + (ch - '0');
            } else if (ch == '[') {
                // Save current state before entering nested brackets
                countStack.push(k);
                stringStack.push(currentString);
                currentString = "";
                k = 0;
            } else if (ch == ']') {
                // Repeat current substring and append to previous string
                int repeatTimes = countStack.top();
                countStack.pop();

                string decoded = stringStack.top();
                stringStack.pop();

                while (repeatTimes--) {
                    decoded += currentString;
                }
                currentString = decoded;
            } else {
                // Append regular characters
                currentString += ch;
            }
        }

        return currentString;
    }
};
