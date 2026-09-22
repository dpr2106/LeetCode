/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// We reuse the exact same helper function from the previous problem!
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    struct ListNode dummy;
    dummy.val = 0;
    dummy.next = NULL;
    struct ListNode* tail = &dummy;
    
    while (list1 != NULL && list2 != NULL) {
        if (list1->val <= list2->val) {
            tail->next = list1;
            list1 = list1->next;
        } else {
            tail->next = list2;
            list2 = list2->next;
        }
        tail = tail->next;
    }
    
    if (list1 != NULL) {
        tail->next = list1;
    } else if (list2 != NULL) {
        tail->next = list2;
    }
    
    return dummy.next;
}

// The main function to merge K lists
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    // Edge case: empty array of lists
    if (listsSize == 0) {
        return NULL;
    }
    
    // Step size determines which lists are being merged
    int step = 1;
    
    while (step < listsSize) {
        // Merge lists in pairs
        for (int i = 0; i + step < listsSize; i += step * 2) {
            lists[i] = mergeTwoLists(lists[i], lists[i + step]);
        }
        // Double the step size for the next round of merging
        step *= 2;
    }
    
    // The final fully merged list will end up in index 0
    return lists[0];
}
