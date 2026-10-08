class Solution {
public:
    int characterReplacement(string s, int k) {
        int n= s.size();
        int mxlen=0;
        int left=0, right=0;
        int maxf=0;
        vector<int>freq(26,0);
        while(right<n){
           freq[s[right]- 'A']++;
           maxf= max(maxf, freq[s[right]- 'A']);

           int len= right-left+1;
           int changes= len- maxf;

           while(changes>k){
            freq[s[left]- 'A']--;
            maxf=0;
            for(int i=0; i<26; i++){
                maxf= max(maxf, freq[i]);
            }
            left++;
            len= right-left+1;

            changes= len-maxf;
           }

           if(changes<=k){
            mxlen= max(mxlen, len);
            right++;
           }
        }
        return mxlen;
    }
};