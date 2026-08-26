class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n= nums.size();
        int ans=0;
        for(int i=0; i<= n-firstLen; i++){

            int sum=0;
            for(int j=i; j<i+firstLen; j++){
                sum+= nums[j];
            }

            for(int k=0; k<=n- secondLen; k++){
                if(k>= i+firstLen || k+secondLen<=i){
                    int sum2=0;
                    for(int p= k; p< k+secondLen; p++){
                        sum2+= nums[p];

                    }
                    ans= max(ans, sum+sum2);
                }
            }

        }
        return ans;

    }
};