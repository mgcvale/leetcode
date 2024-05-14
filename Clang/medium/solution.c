/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#include <stdlib.h>

inline struct ListNode* create_node(int val) {
    struct ListNode* node = malloc(sizeof(struct ListNode));
    node->val = val;
    node->next = NULL;
    return node;
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    //we will create a head so that we can return the head of the list, but insert to its tail (current_node);
    struct ListNode head;
    struct ListNode* current_node = &head;
    short carry = 0;
    short sum;

    while(l1 != NULL || l2 != NULL || carry) {
        sum = carry;
        if(l1 != NULL) {
            sum += l1->val;
            l1 = l1->next;
        }
        if(l2 != NULL) {
            sum += l2->val;
            l2 = l2->next;
        }

        carry = sum/10;
        sum = sum%10;

        current_node->next = create_node(sum);
        current_node = current_node->next;
    }

    return head.next;
}
