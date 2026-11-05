class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int n= arr1.size();
        int m= arr2.size();
        int mx= INT_MIN;
        int c=0;
        for(int i=0; i<n; i++){
            int p=0;
            for(int j=0; j<m; j++){
                if(abs(arr1[i]- arr2[j])>d){
                    mx= max(mx, abs(arr1[i]- arr2[j]));
                    p++;
                }
            }
            if(p==m) c++;
        }

        return c;



    }
};