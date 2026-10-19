class Solution {
public:
    int compress(vector<char>& chars) {
        int n= chars.size();

        string s= "";

        map<char,int>mp;

        for(auto i: chars) mp[i]++;
        int c=1;
        for(int i=1; i<n; i++){
            if(chars[i]== chars[i-1])c++;
            else{
                s+= chars[i-1];
                if(c>1) s+= to_string(c);
                c=1;
            }
        }
        s+= chars[n-1];
        if(c>1) s+= to_string(c); 
       

        int m= s.size();
        for(int i=0; i<m; i++) chars[i]= s[i];

        return s.size();
    }
};