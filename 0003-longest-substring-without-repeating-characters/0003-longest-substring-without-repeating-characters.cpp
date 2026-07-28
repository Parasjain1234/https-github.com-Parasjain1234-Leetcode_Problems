class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int mx= -1;
        int n= s.size();
        unordered_set<char>st;
        for(int j=0; j<n; j++){
          
        for(int i=j; i<n; i++){
            char t= s[i];
            if(!st.count(t)){
                st.insert(t);
            }
            else{
                mx= max(mx, (int)st.size());
                break;

                
            }

        }
        mx= max(mx, (int)st.size());
        st.clear();
        }
        mx= max(mx, (int)st.size());
        return mx;
    }
};