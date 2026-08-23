class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<vector<int>> arr;
    set<int> st;

    for (int x : nums) {
        if (x >= lower && x <= upper) {
            st.insert(x);
        }
    }

    int i = lower;

    while (i <= upper) {
        if (st.count(i)) {
            i++;
            continue;
        }

        int start = i;

        while (i <= upper && !st.count(i)) {
            i++;
        }

        int end = i - 1;

        arr.push_back({start, end});
    }
    return arr;
    }
};