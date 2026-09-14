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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* res = NULL; ListNode* prev = NULL;
        int n = lists.size();
        using pii = pair<int, ListNode*>;
        priority_queue<pii, vector<pii>, greater<pii>> pq;

        for(int i=0;i<lists.size();i++) {

            if(lists[i] == NULL) continue;
            pq.push({lists[i]->val, lists[i]});
        }

        while(!pq.empty()) {

           ListNode* temp = pq.top().second; pq.pop();
           if(res == NULL) {
            res = temp; prev = temp;
           } 
           else{
            prev->next = temp;
            prev = temp;
           }
           if(temp->next != NULL) {
            pq.push({temp->next->val, temp->next});
           }
           temp->next = NULL;
        }

        return res;
    }
};
