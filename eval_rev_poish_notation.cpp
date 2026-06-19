#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

class Solution {
    stack<int> st;

  public:
    int evalRPN(vector<string> &tokens) { // ← Must be vector<string>&
        for (const string &token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int b = st.top();
                st.pop();
                int a = st.top();
                st.pop();

                if (token == "+")
                    st.push(a + b);
                else if (token == "-")
                    st.push(a - b);
                else if (token == "*")
                    st.push(a * b);
                else
                    st.push(a / b);
            } else {
                st.push(stoi(token));
            }
        }
        return st.top();
    }
};

int main() {
    Solution sol;
    vector<string> vec1 = {"2", "1", "+", "3", "*"};
    vector<string> vec2 = {"4", "13", "5", "/", "+"};
    vector<string> vec3 = {"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"};
    cout << sol.evalRPN(vec1) << endl;
    cout << sol.evalRPN(vec2) << endl;
    cout << sol.evalRPN(vec3) << endl;
}
