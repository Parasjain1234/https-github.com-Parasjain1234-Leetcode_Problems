class Solution {
public:
    int trap(vector<int>& height) {
        int n= height.size();
        vector<int>Prefix_max(n);
        vector<int>Suffix_max(n);
        int mx =-1;
        for(int i=0; i<n; i++){
            mx= max(mx, height[i]);
            Prefix_max[i]= mx;
        }
        reverse(height.begin(), height.end());
        int mx1=-1;
        for(int i=0; i<n; i++){
            mx1= max(mx1, height[i]);
            Suffix_max[i]= mx1;
        }
        reverse(Suffix_max.begin(), Suffix_max.end());
        reverse(height.begin(), height.end());
        int total=0;
        int mn=-1;
        for(int i=0; i<n; i++){
            int left_max= Prefix_max[i];
            int right_max= Suffix_max[i];
            if(height[i]<left_max && height[i]<right_max){
                total+=  min(left_max, right_max)- height[i];
            }
        }

    
       return total;
    }
    
};