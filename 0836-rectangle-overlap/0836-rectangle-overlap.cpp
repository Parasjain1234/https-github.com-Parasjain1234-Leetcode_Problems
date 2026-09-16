class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
        int x1 = rec1[0], y1 = rec1[1];
        int x2 = rec1[2], y2 = rec1[3];

        int l1 = rec2[0], m1 = rec2[1];
        int l2 = rec2[2], m2 = rec2[3];

        if (x1 < l2 && l1 < x2 &&
            y1 < m2 && m1 < y2) {
            return true;
        }

        return false;
    }
};