class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int n= nums.size();
        vector<int>st;
        for(int i=0; i<n; i+=2){
            int a= nums[i];
            int b= nums[i+1];

            string s="";
            s+= to_string(a);
            s+= to_string(b);
            st.push_back(stoi(s));


        }

        return *min_element(st.begin(), st.end());


    }
};