class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n= s.size();

        string newstr= "";
        int mn=INT_MAX;
        for(int i=0; i<n; i++){
            string st="";
            int c=0;
            for(int j=i; j<n; j++){
                st+= s[j];
                if(s[j]== '1') c++;
                
                if(c == k){
    
                    if(j-i+1 < mn){
                        mn = j-i+1;
                        newstr = st;
                    }
    
                    else if(j-i+1 == mn && st < newstr){
                          newstr = st;
                    }
                }
                
            }
        }
        return newstr;
    }
};