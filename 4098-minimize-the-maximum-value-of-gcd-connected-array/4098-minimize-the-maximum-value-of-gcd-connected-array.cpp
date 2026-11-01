class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) return -1;

        long long p = value;

        for (long long i = 2; i * i <= value; i++) {
            if (value % i == 0) {
                p = i;
                break;
            }
        }

        long long left = index;
        long long right = n - 1 - index;

        if (value % 2 == 0) {
            if (value - 2 * left <= 0)
                return -1;

            return value + 2 * right;
        }

        if (left > 0) {
            if (value - p - 2 * (left - 1) <= 0)
                return -1;
        }

        if (right > 0)
            return value + p + 2 * (right - 1);

        return value;
    }
};