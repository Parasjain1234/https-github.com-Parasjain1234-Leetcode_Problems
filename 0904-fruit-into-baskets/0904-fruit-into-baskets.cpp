class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n= fruits.size();
       
        int left=0, right=0;
        set<int>st;
        int mx=0;
        map<int,int>mp;
        while(right<n ){
           int ele= fruits[right];
           st.insert(ele);
           mp[ele]++;
           if(mp.size()<=2){
            
            mx= max(mx, right-left+1);
           }
           else{
            while(mp.size()>2){
                mp[fruits[left]]--;

                if(mp[fruits[left]]==0) mp.erase(fruits[left]);

                left++;
            }
           
            
               
            }
            
           
           
           right++;
        }

        return mx;

        
    }
};