class Solution {
public:
    long long gcdSum(vector<int>& nums) {
       long long n= nums.size();
       vector<long long>prefixgcd(n);
        long long mx= nums[0];
       for(long long i=0; i<n; i++){
        mx= max(mx, 1LL *nums[i]);
        prefixgcd[i]= __gcd(mx, 1LL *nums[i]);

       }
       sort(prefixgcd.begin(), prefixgcd.end());
       long long i=0; long long  j= n-1;
       long long sum=0;
       while(i<=j){
          if(i==j) break;
          sum+= __gcd(prefixgcd[i], prefixgcd[j]);
          i++;
          j--;
       }
       return sum;

    }
};