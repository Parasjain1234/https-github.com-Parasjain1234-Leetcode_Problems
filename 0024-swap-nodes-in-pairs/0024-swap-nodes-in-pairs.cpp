// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode* temp = head;
//         while(temp && temp->next){
//             ListNode* curr= temp;
//             temp= temp->next;
//             temp->next= curr;

//             temp=temp->next;
//         }
//         return head;
        
//     }
// };
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;  // edge case: 0 or 1 node

        ListNode* newHead = head->next;  // after first swap, this will be the new head
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr && curr->next) {
            ListNode* nextPair = curr->next->next;
            ListNode* second = curr->next;

            // Swap
            second->next = curr;
            curr->next = nextPair;

            if (prev) {
                prev->next = second;
            }

            // Move pointers forward
            prev = curr;
            curr = nextPair;
        }

        return newHead;
    }
};