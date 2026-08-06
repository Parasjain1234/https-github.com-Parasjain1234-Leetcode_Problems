class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n= nums.size();
        int odd_count=0;
        for(int i=0; i<n; i++){
            if(nums[i]%2) odd_count++;

        }
        

        int c=0;
        int ratio= a/b;
        for(int i=0; i<n; i++){
             int odd=0, even=0;
             for(int j=i; j<n; j++){
                if(nums[j]%2==0) even++;
                else odd++;

                //if((odd>0) && (even/odd) <= ratio) c++;
                if(odd > 0 && even * b <= odd * a)
                        c++;


             }
        }

       return c;


    }
};