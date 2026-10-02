class Solution {
public:
   void solve(int n, int openingBracket, int closingBracket, vector<string>&result, string current){
    if(openingBracket == n && closingBracket==n) {
        result.push_back(current);
        return;
    }

    if(openingBracket >n || closingBracket > n) return;

    //opening chaye haam loghh jitni chaye pahele bada sakte haii

    if(openingBracket> closingBracket){
        solve(n, openingBracket+1, closingBracket, result, current+ '(');
        solve(n, openingBracket, closingBracket+1, result, current+ ')');
    }
    else{
        solve(n, openingBracket+1, closingBracket, result, current+ '(');
    }
   }
    vector<string> generateParenthesis(int n) {
        vector<string>result;
        solve(n,0,0, result, "");
        return result;
    }
};