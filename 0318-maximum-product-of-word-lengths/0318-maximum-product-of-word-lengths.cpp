// class Solution {
// public:
//     int maxProduct(vector<string>& words) {
//         int n= words.size();
//         int mx=0;
//         for(int i=0; i<n-1; i++){
//             string s=words[i];
//             int len= s.size();
//             unordered_set<int>st;
//             for(auto i: s){
//                 st.insert(i);
//             }

//             for(int j=i+1; j<n; j++){
//                 string s1= words[j];
//                 unordered_set<int>st1;
//                 int p=0;
//                 int l= s1.size();
//                 for(auto it: s1){
//                     st1.insert(it);
//                 }

//                 for(auto it: st1){
//                     if(st.count(it)){
//                         p=1;
//                         break;
//                     }
//                 }
//                 if(p==0) mx= max(mx, len*l);
                

//             }
//         }
//         return mx;

            

//     }
// };
class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();

        vector<int> mask(n, 0);

        // pahele create kari bitmask for every word
        for (int i = 0; i < n; i++) {
            for (char c : words[i]) {
                mask[i] |= (1 << (c - 'a'));
            }
        }

        int ans = 0;

        // Compare every pair
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                // No common character
                if ((mask[i] & mask[j]) == 0) {
                    ans = max(ans,
                              (int)words[i].size() * (int)words[j].size());
                }
            }
        }

        return ans;
    }
};