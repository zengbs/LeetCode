/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

typedef struct ListNode ListNode;

ListNode *merge (ListNode *first, ListNode *second){

    ListNode *new;

    if(first->val < second->val){
        new = first;
        first = first->next;
    }else{
        new = second;
        second = second->next;
    }

    ListNode *head = new;

    while(first || second){
        if (first && second){
            if(first->val < second->val){
                new->next = first;
                first = first->next;
            }else{
                new->next = second;
                second = second->next;
            }
        }else{
            if (first){
                new->next = first;
                first = first->next;
            }
            if (second){
                new->next = second;
                second = second->next;
            }
        }

        new= new->next;

    }
    return head;
}

ListNode *mergesort(struct ListNode* head){
    if (!head || !head->next) return head;

    ListNode *slow = head;
    ListNode *fast = head->next;

    while(fast){
        fast = fast->next;

        if(fast){
            fast = fast->next;
            slow = slow->next;
        }else{
            break;
        }
    }

    ListNode *split = slow->next;
    slow->next = NULL;

    ListNode *n1 = mergesort(head);
    ListNode *n2 = mergesort(split);

    return merge(n1, n2);
}

struct ListNode* sortList(struct ListNode* head){

    return mergesort(head);
}
