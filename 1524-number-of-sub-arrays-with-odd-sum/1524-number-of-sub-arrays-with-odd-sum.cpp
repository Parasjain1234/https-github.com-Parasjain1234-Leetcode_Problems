class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n= arr.size();
        int even=1; int odd=0;
        int prefixsum=0;
        int res=0;
        long long m= 1e9+7;
        for(auto i: arr){
            prefixsum+=i;

            if(prefixsum%2){
                 res+= even;
                 odd++;
            }
            else{
                res+= odd;
                even++;
            }

            res= res%m;
        }

        return res;
        

    }
};