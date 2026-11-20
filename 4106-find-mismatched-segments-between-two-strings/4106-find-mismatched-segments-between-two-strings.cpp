class Solution {
public:
    vector<vector<string>> findMismatchedSegments(string s1, string s2) {
        vector<vector<string>>ans;
        vector<string>arr;

        int n= s1.size();
        string st="";
        string st2="";
        for(int i=0; i<n; i++){
            if(s1[i]!= s2[i]){
                st+= s1[i];
                st2+= s2[i];
            }
            else{
                if(st.size()>=1){
                arr.push_back(st);
                arr.push_back(st2);

                ans.push_back(arr);
                arr.clear();
                st="";
                st2="";
                }
            }
        }
       if(st.size()>=1){ arr.push_back(st);
        arr.push_back(st2);
        ans.push_back(arr);}

        return ans;

    }
};