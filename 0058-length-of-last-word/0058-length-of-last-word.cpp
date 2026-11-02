class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.size();
        string t = "";

        int i = n - 1;

        // trailing spaces skip
        while (i >= 0 && s[i] == ' ') i--;

        // last word build kar rhe he 
        while (i >= 0 && s[i] != ' ') {
            t += s[i];
            i--;
        }

        return t.size();
    }
};