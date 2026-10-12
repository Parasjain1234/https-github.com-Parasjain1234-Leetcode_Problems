class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n= people.size();
        int left=0; int right= n-1;
        int c=0;
        sort(people.begin(), people.end());
        while(left< right && right<n){
            if(people[left]+ people[right] <= limit){
                left++; right--;
                c++;
            }
            else if(people[right]<= limit){
                right--; c++;
            }
            else if(people[left]<= limit){
                left++; c++;
            }
            else break;
        }

        return c+ right-left+1;
    }
};