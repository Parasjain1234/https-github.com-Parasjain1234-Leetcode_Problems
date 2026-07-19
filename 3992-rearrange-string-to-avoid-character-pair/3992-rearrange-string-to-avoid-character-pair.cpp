class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int c=0;
        for(auto i: s) if(i==y) c++;
        string st="";
        for(int i=0; i<c; i++){
            st+= y;
        }
        for(int i=0; i<s.size(); i++){
            if(s[i]== y) continue;
            st+= s[i];
        }
        return st;
    }
};