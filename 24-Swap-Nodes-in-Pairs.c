/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    // If the list is empty or has only 1 node, nothing to swap
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Create a dummy node to handle the case where the head itself gets swapped
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    // Set up our three pointers
    struct ListNode* prev = &dummy;
    struct ListNode* first = head;
    struct ListNode* second = head->next;
    
    // Loop as long as we have a pair of nodes to swap
    while (first != NULL && second != NULL) {
        
        // 1. Swap the pointers
        prev->next = second;
        first->next = second->next;
        second->next = first;
        
        // 2. Move pointers forward for the next pair
        prev = first;
        first = first->next;
        
        // Ensure first isn't NULL before trying to access first->next
        if (first != NULL) {
            second = first->next;
        } else {
            second = NULL;
        }
    }
    
    // Return the new head (which is the node that originally came second)
    return dummy.next;
}
