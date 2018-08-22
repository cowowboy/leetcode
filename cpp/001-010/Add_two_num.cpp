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
    int count = 0;
    ListNode* res ;
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //Travel_list(Reverse(l1),Reverse(l2));
        ListNode* x = Reverse(l1);
        ListNode* y = Reverse(l2);
        //Single_test(Travel_list(Reverse(l1),Reverse(l2)));
        return Travel_list(x,y);
    }
    ListNode* Travel_list(ListNode* l1, ListNode* l2){
        ListNode* x;
        while(l1 != NULL && l2 != NULL)
        {
            acc = l1->val + l2->val + count;
            count = 0;
            if (acc >= 10)
            {
                count = 1;
                acc = acc - 10;
                
            }
            if (x == 0){
                x = new ListNode(acc);
            }
            else{
                x->next = new ListNode(acc);
                x = x->next;
            }
        //cout << acc <<endl;
        Single_test(x);
        //cout << res->val << endl;
        
        l1 = l1->next;
        l2 = l2->next;
        
        }
        
        return x;
    }
    void Single_test(ListNode* x){
        if (x==0){
            return;
        }
        ListNode* current = x;
        
        while(current != NULL){
        cout << current->val << endl;
        
        current = current->next;
        
        }        
    }
    // 2->4->3
    // c  p
    // NULL <- 2 4->3->NULL
    // pre     c p
    // NULL<-2 4->3->NULL
    // --  pre c  p
    // NULL<-2<-4 3->NULL
    // --   pre c p
    // NULL<-2<-4 3->NULL
    // --     pre c  p
    ListNode* Reverse(ListNode* x){
        if(x == 0 || x->next ==0){
            return x;
        }
        ListNode* previous = 0,
                * current = x,
                * preceding = x->next;
        
        while(preceding != 0){
            current->next = previous;
            previous = current;
            current = preceding;
            preceding = preceding->next;
        }
        current->next = previous;
        
        x = current;
        return x;
    }
    ListNode* Push_back(int x, ListNode* y){
        //ListNode* newNode = new ListNode(x);
        if (y==0){
            //res = newNode;
            y = new ListNode(x);
            //cout << res->val << endl;
            return y;
        }
        y->next = new ListNode(x);
        y = y->next;
        //cout << res->val << endl;            

        //cout << newNode->val << endl;
        //res->next = newNode;
    return y;
    }
};
