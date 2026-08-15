class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //string p = "abc";
    //     vector<int>ans;
    //     int n= s.size();
    //     int len= p.size();

    //   sort(p.begin(), p.end());

    //   do {
    //     for(int i=0; i<=n-len; i++){
    //         if(s.substr(i,len)==p) ans.push_back(i);
    //     }
          
    //    } while (next_permutation(p.begin(), p.end()));
    //    return ans;
      int s_len= s.size();
      int p_len= p.size();
      if(p_len> s_len) return {};
      vector<int>window(26,0);
      vector<int>freq(26,0);
      vector<int>ans;
      for(int i=0; i<p_len; i++){
        window[s[i]- 'a']++;
        freq[p[i]- 'a']++;
      }
      if(window== freq) ans.push_back(0);

      for(int i= p_len; i<s_len; i++){
        window[s[i- p_len]- 'a']--;
        window[s[i] - 'a']++;

        if(window== freq) ans.push_back(i-p_len+1);
      }

      return ans;
    }
};
