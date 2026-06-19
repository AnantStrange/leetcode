#include <iostream>
#include <ostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
  public:
    bool isValid(string s){
        stack<char> stack; 
        unordered_map<char, char> open_pair = { {')','('}, {'}','{'}, {']','['} };
        for(char ch : s){
            if(ch == '(' or ch == '{' or ch == '['){
                stack.push(ch);
                continue;
            }
            if(stack.empty() or open_pair[ch] != stack.top()){
                return false;
            }
            stack.pop();
        }
        return stack.empty();
    }
};

int main(){
    Solution sol;
    string s1 = "()[]{}";
    string s2 = "([])";
    string s3 = "([)]";
    cout<<sol.isValid(s1)<<endl;
    cout<<sol.isValid(s2)<<endl;
    cout<<sol.isValid(s3)<<endl;
}
