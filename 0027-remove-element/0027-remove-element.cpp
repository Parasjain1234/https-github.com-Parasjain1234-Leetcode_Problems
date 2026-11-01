class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int>arr;
        int n=nums.size();
        int j=0;

        for(int i=0; i<n; i++){
            if(nums[i]!=val) nums[j++]=nums[i]; //j++;
           // else arr[j++]=nums[i];
          // nums[i]
        }
        return j;
        
    }
};
/*class Solution {
    public:
        int removeElement(vector<int>& nums, int val) {
                int k = 0;
                        for(int i = 0; i < nums.size(); i++) {
                                    if(nums[i] != val) {
                                                    nums[k] = nums[i];  // nums ke andar hi overwrite karo
                                                                    k++;
                                                                                }
                                                                                        }
                                                                                                return k;  // Number of elements jo val ke equal nahi hain
                                                                                                    }
                                                                                                    };
                                                                                                    }
}*/