// class Solution {
// public:
//    bool check(string st){
//     int l = 0;
//     int r = st.size()-1;

//     while(l < r){
//         if(st[l] != st[r]) return false;
//         l++;
//         r--;
//     }
//     return true;
// }
//     string longestPalindrome(string s) {
//         int n= s.size();
//         set<string>st;
//         for(int i=0; i<n; i++){
//             string t= "";
//             for(int j=i; j<n; j++){
//                 t+= s[j];
//                 if(check(t)){
//                     st.insert(t);
//                 }
//             }
//         }
//          string ans = "";

//       for(auto v : st) {
//          if(v.size() > ans.size()) {
//             ans = v;
//          }
//       }
//     return ans;




        
//     }
// };
class Solution {
public:
    // int lcs(string &s, string &st, int i, int j){
    //     if(i<0 || j<0) return 0;
        
    //     if(s[i]== st[j]) return 1+ lcs(s, st, i-1, j-1);
    //     return 0+ max(lcs(s, st, i, j-1), lcs(s, st, i-1, j));
    // }
    bool palindrome(string &st){
        int n= st.size();
        int i=0; int j= n-1;
        while(i<j){
            if(st[i]!= st[j]) return false;
            i++; j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        
        int i=0;
        int len= 0;
        string st1="";
        while(i<n){
            string st="";
            for(int j=i; j<n; j++){
                st+= s[j];
                if(palindrome(st)){
                    if(len<st.size()){
                        st1= st;
                        len= st.size();
                    }
                }
            }
            i++;
        }
        return st1;
    }
};