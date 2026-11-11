class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors, vector<int>& groupSize) {
        int n= types.size();
        int m= groupSize.size();

        vector<tuple<int,int,int>>st;

        for(int i=0; i<n; i++){
            int t1= types[i];
            int c1= colors[i];
            int k= groupSize[t1];


            if(!st.empty() && get<0>(st.back())== t1 && get<1>(st.back())==c1){
                get<2>(st.back())++;

                if(get<2>(st.back())==k){
                    st.pop_back();
                }
            }
            else{
                if(k>1)st.push_back({t1, c1, 1});
            }
        }

        return st.empty();


    }
};