class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
       
         int n = nums.size();

vector<int> arr;

int mn = *min_element(nums.begin(), nums.end());
int mx = *max_element(nums.begin(), nums.end());

for (int i = 0; i < n; i++) {
    if (nums[i] == mn) arr.push_back(i + 1);
    if (nums[i] == mx) arr.push_back(i + 1);
}

int mx1 = max(arr[0], arr[1]);
int mn1 = min(arr[0], arr[1]);

int mx2 = max(n - arr[0] + 1, n - arr[1] + 1);
int mn2 = min(n - arr[0] + 1, n - arr[1] + 1);

int c = mn1 + n - mx1 + 1;
int c1 = mn2 + n - mx2 + 1;

int ans = min(mx1, min(mx2, min(c, c1)));

return ans;
    }
};