class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
       int st= start[0]+start[1];
       int en= target[0]+target[1];
       if((st%2==0 && en%2==0) || ( st%2 && en%2) ) return true;
        return false;
    }
};