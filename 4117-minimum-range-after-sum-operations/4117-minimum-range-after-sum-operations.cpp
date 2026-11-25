class Solution {
public:
    int minRange(int a, int b, int c) {
        map<int,int>fre;
        fre[a]++; fre[b]++;
        fre[c]++;

        int mn1= min(a,min(b,c));
        int mn2= INT_MAX;
        if(mn1== a) { mn2= min(b,c);}
        else if(mn1==b){mn2= min(a,c);}
        else mn2= min(a,b);

        int mx= max(a, max(b,c));

        int sum= mn1+mn2;
        while(sum<mx){
            mx= mn1+mn2;
        }

        int mini= min(mn1, min(mn2, mx));
        int maxi= max(mn1, max(mn2, mx));

        return abs(maxi-mini);
        
        
    }
};