class Solution {
public:
    int minRotations(int n, string s) {
        

    int sum = 0;

    int f = s[0] - '0';
    sum += min(abs(0 - f), 10 - f);

// Original string ka cost
for(int i = 1; i < n; i++) {
    int initial = s[i-1] - '0';
    int dest = s[i] - '0';

    int diff = abs(initial - dest);

    sum += min(diff, 10 - diff);
}

int ans = sum;

// k = 0  poori string reverse
int last = s[n-1] - '0';
ans = min(ans, sum - min(abs(0-f), 10-f)
                  + min(abs(0-last), 10-last));

// k > 0  suffix reverse kiya hain mene 
for(int k = 1; k < n; k++) {

    int prev = s[k-1] - '0';
    int curr = s[k] - '0';
    int last = s[n-1] - '0';

    int oldCost = min(abs(prev-curr), 10-abs(prev-curr));

    int newCost = min(abs(prev-last), 10-abs(prev-last));

    ans = min(ans, sum - oldCost + newCost);
}

return ans;
    }
};