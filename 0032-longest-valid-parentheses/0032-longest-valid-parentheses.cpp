class Solution {
public:
    int longestValidParentheses(string s) {
    //     int n= s.size();
    //     if(n==0 || n==1) return 0;
    //     stack<char>st;
    //     st.push(s[0]);

    //     int c=0;
    //     int mx= 0;
    //     for(int i=1; i<n; i++){
    //         char h= s[i];
    //         if(!st.empty()) {char top= st.top();
    //         if(top== '(' && h== ')') {
    //             st.pop();
    //             c++;
    //             mx= max(mx, c);
    //         }
    //         else {st.push(h);
    //             c=0;
                       
    //         }

    //         }
    //         else st.push(h);
    //     }

    //     return mx*2;

        // int mx=0;
        // int c=0;
        // for(int i=0; i<= n-2; ){
        //     if(s[i]== '(' && s[i+1]== ')'){
        //         c++;
        //         mx= max(mx, c);
        //         i+=2;
        //     }
        //     else {
        //         mx= max(mx, c);
        //         c=0;
        //         i++;
        //     }
        // }
        // mx= max(mx, c);
        // return 2*mx;
        stack<int> st;
    st.push(-1);

    int mx = 0;

    for (int i = 0; i < s.size(); i++) {

        if (s[i] == '(') {
            st.push(i);
        }
        else {
            st.pop();

            if (st.empty()) {
                st.push(i);
            }
            else {
                mx = max(mx, i - st.top());
            }
        }
    }

    return mx;
    }
};