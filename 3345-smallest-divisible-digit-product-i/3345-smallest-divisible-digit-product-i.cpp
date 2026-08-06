class Solution {
public:
   int product(int n){
    int ans=1;
    while(n>0){
        ans *= (n%10);
        n= n/10;
    }
    return ans;

   }
    int smallestNumber(int n, int t) {
       
        int p=0;
        for(int i=n; i<= 10*n; i++){
            int pro= product(i);
            if(pro%t==0){
                p=i;
                break;
            }
        }
        return p;
    }
};