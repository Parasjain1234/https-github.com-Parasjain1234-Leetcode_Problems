class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n= nums.size();

        vector<int>arr(n);
        for(int i=0; i<n; i++){
            if(nums[i]<0) arr[i]= -nums[i];
            else arr[i]= nums[i];
        }

        sort(arr.begin(), arr.end());

        long long add = 0LL;
        long long odd= 0LL;

        int i=0; int j= n-1;

        while(i<=j){

            if(i==j){
                add+= (arr[j]*arr[j])*1LL;
                break;
            }
            add+= (arr[j]* arr[j])*1LL;
            odd+= (arr[i]* arr[i])*1LL;

            j--; i++;


        }

        return add-odd;




    }
};