class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n= s.size();
        unordered_map<char,int> mp;
        int left = 0, mx = 0;

        for(int i = 0; i < n; i++) {
            mp[s[i]]++;

            while(mp[s[i]] > 2) {
                mp[s[left]]--;
                left++;
            }

            mx = max(mx, i - left + 1);
        }

        return mx;

    }
};