class Solution {
public:
    long long reverse(long long x) {
        long long rev=0;
        long long t=x;
        if(x>=0){
        while(x>0){
            rev= rev* 10 + x %10;
            x/= 10;
        }
        if(rev>INT_MAX || rev<INT_MIN) return 0;
        return rev;
        }
        else{
            x=x*-1;
            while(x>0){
                rev= rev* 10 + x %10;
                x/= 10;
                }
                                               
            if(rev>INT_MAX|| rev<INT_MIN) return 0;
            return -rev;

        }

     

        


      
    }
};