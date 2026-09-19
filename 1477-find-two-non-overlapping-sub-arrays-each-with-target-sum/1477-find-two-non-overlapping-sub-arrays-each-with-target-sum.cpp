// class Solution {
// public:
//     int minSumOfLengths(vector<int>& arr, int target) {
//         int n = arr.size();
//         int left = 0;
//         int right = 0;
//         int sum = 0;
//         vector<pair<int, int>> pp;
//         vector<int> ans;

//         while (right < n) {
//             sum += arr[right];

//             while (sum > target) {
//                 sum -= arr[left];
//                 left++;
//             }

//             if (sum == target) {
//                 ans.push_back(right - left + 1);
//                 pp.push_back({left, right});
//             }

//             right++;
//         }

//         int sum1 = accumulate(arr.begin(), arr.end(), 0);
//         if (sum1 < 2 * target) return -1;

//         sort(ans.begin(), ans.end());

//         if (ans.size() < 2) return -1;

//         sort(pp.begin(), pp.end());

//         int size = pp.size();
//         int mn1 = INT_MAX;

//         for (int i = 0; i < size - 1; i++) {
//             int ff = pp[i].first;
//             int ss = pp[i].second;

//             for (int j = i + 1; j < size; j++) {
//                 int f1 = pp[j].first;
//                 int s1 = pp[j].second;

//                 if (ss < f1) {
//                     int len1 = ss - ff + 1;
//                     int len2 = s1 - f1 + 1;

//                     mn1 = min(mn1, len1 + len2);
//                 }
//             }
//         }

//         if (mn1 == INT_MAX) return -1;

//         return mn1;
//     }
// };

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();

        int left = 0;
        int sum = 0;

        int mn1 = INT_MAX;

        vector<int> best(n + 1, INT_MAX);

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            best[right + 1] = best[right];

            if (sum == target) {
                int len = right - left + 1;

                if (best[left] != INT_MAX) {
                    mn1 = min(mn1, len + best[left]);
                }

                best[right + 1] = min(best[right + 1], len);
            }
        }

        if (mn1 == INT_MAX) return -1;

        return mn1;
    }
};