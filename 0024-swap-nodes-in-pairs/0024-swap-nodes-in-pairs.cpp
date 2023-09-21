class Solution {
public:
    ListNode* swapPairs(ListNode* head)
    {
        if(head== NULL)
        {
            return NULL;
        }
        if(head->next==NULL)
        {
            return head;
        }
        // ListNode* temp ;
        ListNode* prev = head;
        ListNode* temp = head;
        ListNode* curr = prev->next->next ;
        head= head->next;
        head->next=prev;
        while(curr!=NULL && curr->next!=NULL)
        {
            temp = curr->next->next;
            prev->next = curr->next;;
            prev = curr;
            curr->next->next = curr;
            curr = temp;
        }
        prev->next = curr;
        return head;

        
    }
};