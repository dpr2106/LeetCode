/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// 1. The "Constructor" Helper
// We write this above our main answer to keep the memory allocation clean.
struct ListNode* createNode(int value) {
    struct ListNode* newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// 2. The Core LeetCode Function
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    // A dummy node on the stack to act as the starting anchor
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    
    struct ListNode* current = &dummy;
    int carry = 0;
    
    // Loop until both lists are empty AND the carry is 0
    while (l1 != NULL || l2 != NULL || carry != 0) {
        
        // Grab the values (use 0 if a list has run out of nodes)
        int val1 = (l1 != NULL) ? l1->val : 0;
        int val2 = (l2 != NULL) ? l2->val : 0;
        
        // Add them up
        int total = val1 + val2 + carry;
        carry = total / 10;
        
        // Use our helper function to make the new node
        current->next = createNode(total % 10);
        
        // Move our pointer forward
        current = current->next;
        
        // Move the input pointers forward
        if (l1 != NULL) l1 = l1->next;
        if (l2 != NULL) l2 = l2->next;
    }
    
    // Return the actual first digit (skipping the dummy anchor) .
    return dummy.next;
}