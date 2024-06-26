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
    int pairSum(ListNode* head) {
        int maxi=INT_MIN;
        ListNode *slow=head;
        ListNode *fast=head;
        if(head->next->next==NULL){
            return head->val+head->next->val;
        }
        while(fast && fast->next){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode *prev=NULL;
        ListNode *temp=NULL;
        while(slow && slow->next){
            temp=slow->next;
            slow->next=prev;
            prev=slow;
            slow=temp;
        }
          if(slow != NULL){
            slow->next = prev;
        }
        temp=head;
        while(temp && slow){
            int every=temp->val +slow->val;
            maxi=max(maxi,every);
            temp=temp->next;
            slow=slow->next;
        }
        return maxi;
    }
};