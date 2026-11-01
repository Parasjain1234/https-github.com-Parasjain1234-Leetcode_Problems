#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> stack_;  // Correct stack declaration
        
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            
            if(ch == '(' || ch == '{' || ch == '[') {
                stack_.push(ch);
            } else if(ch == ')' || ch == '}' || ch == ']') {
                if(stack_.empty()) return false; // Check before calling top()
                
                char t = stack_.top();
                if((ch == ')' && t == '(') || (ch == '}' && t == '{') || (ch == ']' && t == '[')) {
                    stack_.pop();
                } else {
                    return false;
                }
            }
        }
        
        return stack_.empty();
    }
};