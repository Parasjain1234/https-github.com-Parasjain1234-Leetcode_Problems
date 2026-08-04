class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        result.push_back(intervals[0]);

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] <= result.back()[1]) {
                // Merge the intervals
                result.back()[1] = max(result.back()[1], intervals[i][1]);
            } else {
                // No overlap
                result.push_back(intervals[i]);
            }
        }

        return result;
    }
};