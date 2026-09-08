class Solution {
public:
    int countCommas(int n) {
        string s= to_string(n);
        int len= s.size();
        if(len<=3) return 0;

        if(len==4){
            string s1= s.substr(0, 4);
            int number= stoi(s1);
           
            return number- 1000+1;
        }
        else if(len==5){
            string s1= s.substr(0, 5);
            int number= stoi(s1);
           
            return number - 1000+1;
           
        }

        return n- 1000+1;
    }
};