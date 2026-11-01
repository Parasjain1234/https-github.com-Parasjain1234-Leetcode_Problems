// class Solution {
// public:
//     // long long gcd_(long long a, long long b){
//     //     if(b==0) return a;
//     //     return gcd_(b, a%b);
//     // }
//     // long long valueset(long long value){
//     //     for(int i=value+1; i<= 2*value; i++){
//     //         if(gcd_(i, value)>1) return i;
//     //     }
//     //     return -1;
//     // }

//     // long long VALUESET(long long value){
//     //     for(int i=value-1; i>=0; i--){
//     //         if(gcd_(i, value)>1) return i;
//     //     }
//     //     return -1;
//     // }

//     long long minimumMaxValue(int n, int index, int value) {
//         // if(value==1) return -1;

//         // vector<int>arr(n, -1);
//         // arr[index]= value; 

//         // if(value%2==0){
//         //    for(int i= index-1; i>=0; i--) arr[i]= arr[i+1]-2;

//         //    for(int i=index+1; i<n; i++) arr[i]= arr[i-1]+2;

//         // //    return arr[n-1];
//         // }
//         // else {
//         //     if(index+1<n) {
//         //         arr[index+1]= valueset(value);
//         //         if(index-1>=0) arr[index-1]= VALUESET(value);

//         //         int newid= index+1;
//         //         for(int i= newid+1; i<n; i++) arr[i]= arr[i-1]+2;

//         //         int newidx= index-1;

//         //         for(int i= newidx-1; i>=0; i--) arr[i]= arr[i+1]-2;



//         //     }
//         // }

//         // for(int i: arr) if(i<=0) return -1;

//         // return arr[n-1];
          
//     }
// };

class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) return -1;

        long long p = value;

        for (long long i = 2; i * i <= value; i++) {
            if (value % i == 0) {
                p = i;
                break;
            }
        }

        long long left = index;
        long long right = n - 1 - index;

        if (value % 2 == 0) {
            if (value - 2 * left <= 0)
                return -1;

            return value + 2 * right;
        }

        if (left > 0) {
            if (value - p - 2 * (left - 1) <= 0)
                return -1;
        }

        if (right > 0)
            return value + p + 2 * (right - 1);

        return value;
    }
};
