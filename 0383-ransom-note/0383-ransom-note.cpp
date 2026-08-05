class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int>mp, mp1;

        for(auto i: ransomNote) mp[i]++;

        for(auto it: magazine) mp1[it]++;

        for(auto i: ransomNote){
            int fre= mp[i];

            int ff= mp1[i];

            if(fre>ff) return false;

        }
        return true;
        
    }
};