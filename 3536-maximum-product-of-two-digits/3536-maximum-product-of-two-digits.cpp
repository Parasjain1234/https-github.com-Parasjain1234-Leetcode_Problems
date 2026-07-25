// class Solution {
// public:
//     int maxProduct(int n) {
//         string s= to_string(n);
//         int size= s.size();
//         if(size==1) return n;
//         if(size==2) return (n%10)*(n%100);

//         int sum=1;
//         int pro=1;
//         int first= n%10;
//         int second= n%100;
//         n= n/100;
//         int mx=0;
//         while(n>0){
//             if(!first){
//                 first= n%10;
//                 pro= first*second;
//                 mx= max(mx, pro);
//                 n= n/10;
                
//             }
//             else if(!second){
//                 second= n%10;
//                 pro= first*second;
//                 mx= max(mx, pro);
//                 n= n/10;
//             }
//             else{
//                 mx= max(mx, first*second);
//                 n=n/10;
//             }
            

           
//         }
//         return mx;
//     }
// };
class Solution {
public:
    int maxProduct(int n) {
        int first = 0, second = 0;

        while (n > 0) {
            int d = n % 10;

            if (d >= first) {
                second = first;
                first = d;
            } else if (d > second) {
                second = d;
            }

            n /= 10;
        }

        return first * second;
    }
};