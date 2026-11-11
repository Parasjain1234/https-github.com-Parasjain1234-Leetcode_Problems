class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 1LL * cost1 * need1 + 1LL * cost2 * need2;

       
        long long t=0;

        if(cost1+ cost2 <= costBoth){
            return ans;
        }
        else {
            long long mn= min(need1, need2);
            t= mn* costBoth*1LL;

            need1-= mn;
            need2-=mn;

            if(need1){
                t+=  need1* 1LL*min(cost1, costBoth);
            }
            else {
                t+= need2* 1LL*min(cost2, costBoth);
            }
        }

        return t;
    }
};