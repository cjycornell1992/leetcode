/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    /*  define linked-list-node data structure  */
    typedef struct ListNode node_t;
    
    /*  variables:
    carry: carry-in bit
    carry_num: 1 or 0 depending on carry_in bit
    n0: current node
    n0_next: next node
    head: the head node of linked list  */
    bool carry = false;
    int carry_num = 0;
    node_t *n0,*head,*n0_next;
    n0 = (node_t*) malloc(sizeof(node_t));
    head = n0;
    
    if(l1 == NULL && l2 == NULL) {
        return NULL;
    }
    
    /* loop until hit the end of one list */
    while(l1 != NULL && l2 != NULL) {
        carry_num = carry ? 1 : 0;
        carry = false;
        /* compute value of current node */
        n0 -> val = (l1 -> val) + (l2 -> val) + carry_num;
        n0_next = (node_t*) malloc(sizeof(node_t));
        n0_next -> next = NULL;
        /* modify if current value produces carry-in */
        if(n0 -> val >= 10) {
            n0 -> val -= 10;
            carry = true;
        }
        /* go to next node of l1 & l2 */
        l1 = l1 -> next;
        l2 = l2 -> next;
        /* if not at the end, link n0 & n0_next */
        if(l1 != NULL  && l2 != NULL) {
            n0 -> next = n0_next;
            n0 = n0 -> next;            
        }
    }
    /* Deal with remainings of l1/l2 */
    node_t *l_togo;
    /* Case when two lists hit the end simultaneously */
    if(l1==NULL && l2==NULL) {
        if(carry) {
            n0_next -> val = 1;
            n0 -> next = n0_next;
        }
    } 
    
    /* General cases */
    else {
        /* Deciding which list remains to go */
        l_togo = (l1 == NULL) ? l2 : l1;
        n0 -> next = n0_next;
        n0 = n0 -> next;
        /* add, loop, modify, until hit the last node */
        while (l_togo != NULL) {
            carry_num = carry ? 1 : 0;
            carry = false;
            
            n0 -> val = (l_togo -> val) + carry_num;
            n0_next = (node_t*) malloc(sizeof(node_t));
            n0_next -> next = NULL;
            
            if(n0 -> val >= 10) {
                n0 -> val -= 10;
                carry = true;
            }
            l_togo = l_togo -> next;
            if(l_togo != NULL) {
                n0 -> next = n0_next;
                n0 = n0 -> next;
            }
        }
        /* carry-in bit links extra node */
        if(carry) {
            n0_next -> val = 1;
            n0 -> next = n0_next;
        }
        
    }
    
    return head;
}