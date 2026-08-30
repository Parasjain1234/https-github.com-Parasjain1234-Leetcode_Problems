class Solution {
public:
    int sumDecoded(vector<long long>& nums) {
        long long n= nums.size();
        long long sum=0;
        long long mod= 1e9+7;

       for(int i=0; i<n; i++){
          long long wd= nums[i]%10;
         long long d= nums[i]/10;
          string s="";
          long long m=d;

          while(m>0){
            int rem= m%10;
            s+= to_string(rem);
            m= m/10;
          }
          reverse(s.begin(), s.end());
          string x="", y= "";

          for(int i=0; i<wd; i++) x+= s[i];
          for(int i= wd; i<s.size(); i++) y+= s[i];
          long long x1= stoll(x);

          long long y1= stoll(y);


            long long a= x1, b= y1;
             long long ans = 1;

            while (b > 0) {
                 if (b & 1) {        
                    ans = (ans * a)%mod;
                  }

                 a = (a * a)%mod;
                b = b >> 1;         
            }

             sum= (sum+ans)%mod;

       }
        return sum;

    }
};