class Solution {
public:
   
    bool isPalindromic(string s) {
      
        //int n= s.size();
        string original= "";
        for(char c: s){
            int number= (int)c;
            string ss="";
            while(number>0){
                int rem= number%2;
                ss+= to_string(rem);
                number= number/2;
            }

            reverse(ss.begin(), ss.end());

             while (ss.size() < 8) {
                     ss = "0" + ss;
              }

              original += ss;

        }

        int size= original.size();

        int i=0, j= size-1;
        while(i<j){
            if(original[i]!= original[j]) return false;
            i++;
            j--;

        }
        return true;

    }
};