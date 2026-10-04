class Solution {
public:
    int minRotations(string s) {
        int n= s.size();
        int sum=0;
       int f= s[0]- '0';
       sum+= min(abs(0-f), 10- f);
        for(int i=1; i<n; i++){
            int initial= s[i-1]-'0';
            int dest= s[i]-'0';
            int diff= abs(initial- dest);

            sum+= min(diff, 10- diff);
        }
        return sum;
    }
};