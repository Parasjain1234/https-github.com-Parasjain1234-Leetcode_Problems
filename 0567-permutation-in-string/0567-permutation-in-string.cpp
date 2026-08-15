class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n= s1.size();
        int m= s2.size();

        if(m<n)return false;

        vector<int>freq(26,0), window(26,0);

        for(int i=0; i<n; i++){
            freq[s1[i]- 'a']++;
            window[s2[i]- 'a']++;

        }
        if(freq== window) return true;

        for(int i=n; i<m; i++){
            window[s2[i-n] - 'a']--;
            window[s2[i]- 'a']++;

            if(window== freq) return true;
        }
        return false;
    }
};