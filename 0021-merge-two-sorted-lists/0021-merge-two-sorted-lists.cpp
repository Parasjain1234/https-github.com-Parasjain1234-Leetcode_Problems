/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
//         vector<int>v;
//         int t= list1.size();
//         int t1= list2.size();
//         int l=0,l1=0;
//         while(l<t && l1<t1){
//             if(list1[l]<=list2[l1]){
//                 v.push_back(list1[l]);
//                 l++;
//             }
//             else if(list2[l1]<=list1[l]){
//                 v.push_back(list2[l1]);
//                 l1++;
//             }
//         }
//         while(l<t){
//             v.push_back(list1[l]);
//         }
//         while(l1<t){
//             v.push_back(list2[l1]);
//         }
//         return v;
//     }
// };
#include <iostream>
using namespace std;

// Definition for singly-linked list.
/*struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};*/

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* dummy = new ListNode(-1);
        ListNode* curr = dummy;

        while (list1 && list2){
            if (list1->val <= list2->val) {
                curr->next = list1;
                list1 = list1->next;
            } else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }

        if (list1) curr->next = list1;
        if (list2) curr->next = list2;

        return dummy->next;
    }
};