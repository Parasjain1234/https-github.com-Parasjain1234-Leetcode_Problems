class Solution {
public:
    int minOperations(string s) {
       
        int n= s.size();
       
        string st="";
        for(auto i: s) st+= i;
        sort(st.begin(), st.end());
       
        if(s== st) return 0;
        if(n==2) return -1;
        int mn= *min_element(s.begin(), s.end());
        int mx= *max_element(s.begin(), s.end());
        if(mn== s[0] ||  mx== s[n-1]) return 1;
        for(int i=1; i<n-1; i++){
            if(s[i]== mn ||  s[i]==mx) return 2;
           
        }
        

       // if(ans==0) return -1;
        return 3;
    }
};