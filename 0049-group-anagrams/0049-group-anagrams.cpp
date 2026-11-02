class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>>mp;
        set<string>st;
        for(auto word: strs){
            string w= word;
            sort(w.begin(), w.end());
            st.insert(w);
            mp[w].push_back(word);


        }
        vector<vector<string>>groups;
        for(auto i: st){
            groups.push_back(mp[i]);
        }
        return groups;
        
    }
};