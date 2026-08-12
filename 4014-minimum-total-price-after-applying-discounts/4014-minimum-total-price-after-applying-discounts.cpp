class Solution {
public:
    double minPrice(vector<int>& prices, vector<int>& discounts) {
        int n= prices.size();
        int m= discounts.size();

        double sum= 0;
        sort(prices.begin(), prices.end(), greater<int>{});
        sort(discounts.begin(), discounts.end(), greater<int>{});

        for(int i=0; i<min(n,m); i++){
            int p= prices[i];
            int d= discounts[i];
            sum+= (double)(p*(100-d))/100;
        }

        for(int i= min(n,m); i<n; i++){
            sum+= prices[i];
        }
        return sum;
    }
};