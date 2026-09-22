/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    // Edge case: if list is empty or k=1, reversing does nothing.
    if (head == NULL || k == 1) {
        return head;
    }

    // 1. Calculate the total number of nodes in the list
    int count = 0;
    struct ListNode* ptr = head;
    while (ptr != NULL) {
        count++;
        ptr = ptr->next;
    }

    // Create a dummy node pointing to the head
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = head;
    
    // prevGroupEnd keeps track of the tail of the PREVIOUS reversed group.
    // Initially, it's the dummy node.
    struct ListNode* prevGroupEnd = &dummy;
    
    // 2. Loop while we have enough nodes for a full k-group
    while (count >= k) {
        // The first node of our current group will become the tail after reversal
        struct ListNode* groupStart = prevGroupEnd->next;
        
        // Standard linked list reversal pointers
        struct ListNode* curr = groupStart;
        struct ListNode* prev = NULL;
        struct ListNode* next = NULL;
        
        // 3. Reverse exactly k nodes
        for (int i = 0; i < k; i++) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        // 4. Re-connect the reversed group back into the main list
        // After the loop above:
        // 'prev' is pointing to the new head of this reversed group.
        // 'curr' is pointing to the first node of the NEXT group (or leftovers).
        
        // Connect the previous part of the list to the new head
        prevGroupEnd->next = prev;
        
        // Connect the new tail of this group to the rest of the list
        groupStart->next = curr;
        
        // Move our prevGroupEnd pointer forward for the next loop iteration
        prevGroupEnd = groupStart;
        
        // We successfully processed k nodes, so subtract from our count
        count -= k;
    }
    
    return dummy.next;
}
