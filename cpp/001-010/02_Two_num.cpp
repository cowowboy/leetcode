/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    int acc = 0;
    int a,b;
    int count = 0;
    ListNode* head = new ListNode(0);
    ListNode* res = head;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        while(l1 != NULL || l2 != NULL || count != 0)
        {   
            if (l1 == NULL){
                a = 0;
            }else{
                a = l1->val;
            }
            if (l2 == NULL){
                b = 0;
            }else{
                b = l2->val;
            }
            acc = a + b + count;
            if (acc > 9){
                count = 1;
            }else{
                count = 0;
            }
            int v = acc % 10;
            ListNode* x = new ListNode(v);
            head->next = x;
            head = head->next;
            
            if (l1 != NULL){
            l1 = l1->next;    
            }
            if(l2!=NULL){
            l2 = l2->next;    
            }

            }
        
        return res->next;
    }
};
