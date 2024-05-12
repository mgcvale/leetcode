/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 #include <stdlib.h>

struct node {
    int key;
    int value;
    struct node* next;
};
typedef struct node Node;

Node* put(int key, int value, Node* map) {
    Node* new_node = malloc(sizeof(Node));
    new_node->key = key;
    new_node->value = value;
    new_node->next = map;
    return new_node;
}

int get(int value, Node* map) {
    Node* current = map;
    while (current != NULL) {
        if (current->value == value) {
            return current->key;
        }
        current = current->next;
    }
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2; 
    int* result = malloc(2*sizeof(int));
    Node* past_values = malloc(sizeof(Node));
    past_values->next = NULL;

    for(int i = 0; i<numsSize; i++) {
        int index = get(target - nums[i], past_values);
        if(index != -1) {
            result[0] = i;
            result[1] = index;
            return result;
        }
        past_values = put(i, nums[i], past_values);
    }

    return NULL;
}
