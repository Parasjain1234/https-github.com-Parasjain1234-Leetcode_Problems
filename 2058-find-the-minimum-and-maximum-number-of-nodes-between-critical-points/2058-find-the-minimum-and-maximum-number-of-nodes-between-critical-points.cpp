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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>arr;
        while(head){
            arr.push_back(head->val);
            head= head->next;
        }

    //     int n= arr.size();
    //     if(n<=2) return {-1,-1};

    //     vector<int>ans;
    //     for(int i=1; i<n-1; i++){
    //         if(arr[i-1]< arr[i] && arr[i]> arr[i+1]) ans.push_back(i);
    //         if(arr[i-1] > arr[i] && arr[i]< arr[i+1]) ans.push_back(i);
            
    //     }

    //     sort(ans.begin(), ans.end());
    //    // return ans;
    //     int m= ans.size();
    //     // int a= ans[1]- ans[0];
    //     // int b= ans[m-1]- ans[0];
    //     //return {b,a};
    //     vector<int>paras;
    //     for(int i=1; i<m; i++){
    //         paras.push_back(ans[i]- ans[i-1]);
    //     }
    //     paras.push_back(ans[m-1]- ans[0]);
    //     sort(paras.begin(), paras.end());
    //     return {paras[0], paras[m-1]};
    int n = arr.size();

if(n < 2) return {-1,-1};

vector<int> ans;

for(int i = 1; i < n-1; i++){


    if(arr[i-1] > arr[i] && arr[i] < arr[i+1])
        ans.push_back(i);


    if(arr[i-1] < arr[i] && arr[i] > arr[i+1])
        ans.push_back(i);
}

sort(ans.begin(), ans.end());

int m = ans.size();

if(m < 2)
    return {-1,-1};

vector<int> paras;

for(int i = 1; i < m; i++){
    paras.push_back(ans[i] - ans[i-1]);
}

paras.push_back(ans[m-1] - ans[0]);

sort(paras.begin(), paras.end());

return {paras[0], paras[m-1]};
    }
};