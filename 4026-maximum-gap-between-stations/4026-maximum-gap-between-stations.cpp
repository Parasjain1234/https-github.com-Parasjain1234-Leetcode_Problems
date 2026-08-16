class Solution {
public:
    int maximumGap(string skill, string station) {
        int n= skill.size();
        int m= station.size();

        // vector<int>ans;
        // int i= n-1;
        // int j= m-1;
        // while(i>=0 && j>=0 ){
        //     if(skill[i]== station[j]){
        //         ans.push_back(j);
        //         i--;
        //         j--;
        //     }
        //     else j--;
        // }

        // sort(ans.begin(), ans.end());
        // int p= ans.size();
        // int mx=0;
        // for(int i=1; i<p; i++ ){
        //     mx= max(mx, ans[i]- ans[i-1]);
        // }
        // return mx;

        vector<int>left(n), right(n);

        int pos=0;
        for(int i=0; i<n; i++){
            while(pos<m && skill[i]!= station[pos]) pos++;

            left[i]= pos;
            pos++;
        }

        pos= m-1;
        for(int i= n-1; i>=0; i--){
            while(pos>=0 && skill[i]!= station[pos]) pos--;

            right[i]= pos;
            pos--;
        }

        int mx=0;
        for(int i=1; i<n; i++){
            mx= max(mx, right[i]- left[i-1]);
        }
        return mx;
    }
};