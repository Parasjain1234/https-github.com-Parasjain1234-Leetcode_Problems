// class Solution {
// public:
//     long long maximumValue(int n, int s, int m) {
//         if(n==1) return s;

//         vector<long long>arr(n);
//         arr[0]= s;
//         long long prev= s;
//         long long mx= -1;
//         long long curr= prev;

//         for(long long i=1; i<n; i+=2){
//             if(i%2==0) arr[i]= arr[i-1]-1;
//             else arr[i]= arr[i-1]+ m;

//             //prev= curr;

//             mx= max(mx, arr[i]);

//             if(n>2 && i+1<n){
//                 if((i+1) % 2 ==0) arr[i+1]= arr[i]-1;
//                 else arr[i+1]= arr[i]+m;

//                 mx= max(mx, arr[i+1]);
//             }
//         }
       
//         return mx;
//     }
// };
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        if (n == 1) return s;

        long long t1 = (n - 2) / 2;
        long long ans1 = 1LL * s + m + t1 * (m - 1);

        long long t2 = (n - 1) / 2;
        long long ans2 = 1LL * s + t2 * (m - 1);

        return max(ans1, ans2);
    }
};