// class Solution {
// public:
//     bool validPalindrome(string s) {
//         int l=s.size();
//         int k= l/2;
//         int i=0, j=l-1;
//         while(i<k-1){
//             if(s[i]!=s[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
        
//     }
// };

class Solution {
public:
    // Helper function to check if a substring is palindrome
    bool isPalindrome(string &s, int left, int right) {
        while(left < right) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        while(i < j) {
            if(s[i] != s[j]) {
                // Either skip s[i] or s[j]
                return isPalindrome(s, i + 1, j) || isPalindrome(s, i, j - 1);
            }
            i++;
            j--;
        }
        return true;
    }
};
