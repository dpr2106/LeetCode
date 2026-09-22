/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    // Create a dummy node to handle edge cases (like removing the head node)
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    struct ListNode* fast = &dummy;
    struct ListNode* slow = &dummy;
    
    // Move fast pointer n + 1 steps ahead
    for (int i = 0; i <= n; i++) {
        fast = fast->next;
    }
    
    // Move both pointers until fast reaches the end
    while (fast != NULL) {
        fast = fast->next;
        slow = slow->next;
    }
    
    // slow is now pointing to the node right before the one we want to delete.
    // Skip the nth node from the end.
    struct ListNode* nodeToDelete = slow->next;
    slow->next = slow->next->next;
    
    // Optional (but good practice in C): free the memory of the deleted node
    // free(nodeToDelete); 
    
    return dummy.next;
}
