/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    // Create a dummy node to easily build the new list
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    
    // Tail pointer to keep track of the last node in our merged list
    struct ListNode* tail = &dummy;
    
    // Traverse both lists as long as they both have nodes
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        // Move tail forward to the newly added node
        tail = tail->next;
    }
    
    // If one of the lists is empty, attach the remaining nodes of the other list
    if (list1 != NULL) {
        tail->next = list1;
    } else if (list2 != NULL) {
        tail->next = list2;
    }
    
    // Return the actual head of the merged list (skipping the dummy node)
    return dummy.next;
}
