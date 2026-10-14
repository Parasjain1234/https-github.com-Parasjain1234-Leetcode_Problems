class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if(num*9< sum) return "";
        string ans= "";

        int nine= sum/9;
        int rem= sum%9;
        for(int i=0; i<nine; i++) ans+= '9';
        if(rem)ans+= to_string(rem);

        int l= ans.size();
        int n= num-l;
        if(n)for(int i=0; i<n; i++) ans+= '0';

        return ans;
    }
};