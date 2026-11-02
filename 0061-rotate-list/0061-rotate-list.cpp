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
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        int size=0;
        ListNode* temp2= head;
        while(temp2){
            temp2= temp2->next;
            size++;
        }
        if(size== 1) return head;
        if(k==0) return head;
        if(size==2){
            if(k%2==0) return head;
            ListNode* t= head;
            ListNode* t1= head;
            t= t->next;
            t1->next= NULL;
            t->next= t1;
            head= t;
            return head;



        }
        if(k== size) return head;
        k= k%size;
        k= size-k;
        if(k== size) return head;

        ListNode* temp1= head;
        while(temp1->next!= NULL){
            temp1= temp1->next;

        }
        ListNode* temp= head;
        ListNode* prev= NULL;
        int j=0;
        while(j<k){
            prev= temp;
            temp= temp->next;
            j++;
        }
        prev->next= NULL;
        temp1->next= head;
        head= temp;
        return head;
        
    }
};