class Solution {
public:
    vector<int>primefactor(int n){
         vector<int> fact;

    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            fact.push_back(i);

            // Same prime factor ko baar-baar skip karo
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    // Agar last me n > 1 bacha hai
      if (n > 1) {
        fact.push_back(n);
       }

       return fact;
    }
    int longestSubarray(vector<int>& nums, int k) {
        int n= nums.size();

        vector<vector<int>>factors(n);
        for(int i=0; i<n; i++){
            factors[i]= primefactor(nums[i]);
        }
        int left=0;
        int ans=0;
        map<int,int>mp;
       for(int i=0; i<n; i++){
            //int p= nums[i];
            
            for(auto p: factors[i]){
                mp[p]++;
            }
                while(mp.size()>k){
                    for(auto j: factors[left]){
                        mp[j]--;

                        if(mp[j]==0){
                            mp.erase(j);
                        }
                    }
                    left++;
                }

                
                
            
            ans= max(ans, i-left+1);

        }
        return ans;
    }
};