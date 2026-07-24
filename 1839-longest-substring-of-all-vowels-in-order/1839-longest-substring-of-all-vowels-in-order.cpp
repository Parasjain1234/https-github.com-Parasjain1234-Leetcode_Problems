// class Solution {
// public:
//     int longestBeautifulSubstring(string word) {
//         //string word; cin>>word;
//         int n= word.size();
//        int mx= -1;
//        int c=0;
//         for(int i=0; i<n-1; ){
//            if(word[i]== 'a'){
//             c++;
//               if(word[i+1]== 'a' || word[i+1]== 'e' || word[i+1] == 'i' || word[i+1]=='o' || word[i+1]== 'u'){
//                 c++;
//                 i+=2;
//               }
//               else{
//                 mx= max(mx,c);
//                 c=0;
//                 i++;
//               }
//            }
//            else if(word[i]== 'e'){
//             c++;
//               if( word[i+1]== 'e' || word[i+1] == 'i' || word[i+1]=='o' || word[i+1]== 'u'){
//                 c++;
//                 i+=2;
//               }
//               else{
//                 mx= max(mx,c);
//                 c=0;
//                 i++;
//               }
//            }
//            else if(word[i]== 'i'){
//             c++;
//               if(word[i+1] == 'i' || word[i+1]=='o' || word[i+1]== 'u'){
//                 c++;
//                 i+=2;
//               }
//               else{
//                 mx= max(mx,c);
//                 c=0;
//                 i++;
//               }
//            }
//            else if(word[i]== 'o'){
//             c++;
//               if( word[i+1]=='o' || word[i+1]== 'u'){
//                 c++;
//                 i+=2;
//               }
//               else{
//                 mx= max(mx,c);
//                 c=0;
//                 i++;
//               }
//            }
//            else if(word[i]== 'u'){
//             c++;
//               if(word[i+1]== 'u'){
//                 c++;
//                 i+=2;
//               }
//               else{
//                 mx= max(mx,c);
//                 c=0;
//                 i++;
//               }
//            }



//         }
//         //cout<<mx<<endl;
//         return mx;


        
//     }
// };
class Solution {
public:
    int longestBeautifulSubstring(string word) {

        int n = word.size();

        int cnt = 1;      // current substring length
        int type = 1;     // distinct vowels seen
        int ans = 0;

        for (int i = 1; i < n; i++) {

            if (word[i] == word[i - 1]) {
                cnt++;
            }
            else if (word[i] > word[i - 1]) {
                cnt++;
                type++;
            }
            else {
                cnt = 1;
                type = 1;
            }

            if (type == 5)
                ans = max(ans, cnt);
        }

        return ans;
    }
};