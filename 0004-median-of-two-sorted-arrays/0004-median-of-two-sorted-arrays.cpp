class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        long long s1= nums1.size();
        long long s2= nums2.size();
        long long T= s1+s2;
        long long arr[T];
        int i=0;
        int l1=0, l2=0, h1= s1-1,  h2 = s2-1;
        while(l1<=h1 && l2<= h2){
            if(nums1[l1]<=nums2[l2]){
                arr[i++] = nums1[l1];
                l1++;
            }
            else{
                arr[i++] = nums2[l2];
                l2++;
            }
        }
        while(l1<=h1) arr[i++]= nums1[l1++];
        while(l2<=h2) arr[i++]=nums2[l2++];

        if(T%2==1) return arr[T/2];
        else{
            long long id2= T/2.0;
            long long id1= id2-1;
            return (arr[id2] + arr[id1])/2.0;
        }
        return -1;
    }
};