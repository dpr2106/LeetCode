/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    // Edge cases: empty list, single node list, or 0 rotations
    if (head == NULL || head->next == NULL || k == 0) {
        return head;
    }

    // 1. Find the length of the list and locate the tail node
    int length = 1;
    struct ListNode* tail = head;
    while (tail->next != NULL) {
        length++;
        tail = tail->next;
    }

    // 2. Connect the tail to the head to make it a circular linked list
    tail->next = head;

    // 3. Find the effective number of rotations
    k = k % length;
    
    // 4. Find the new tail.
    // If length is 5 and k is 2, the new tail is at position 5 - 2 = 3.
    // To get to the 3rd node from the head, we take (3 - 1) = 2 steps.
    int stepsToNewTail = length - k - 1;
    struct ListNode* newTail = head;
    for (int i = 0; i < stepsToNewTail; i++) {
        newTail = newTail->next;
    }

    // 5. The new head is the node immediately after the new tail
    struct ListNode* newHead = newTail->next;

    // 6. Break the circle so it's a normal linked list again
    newTail->next = NULL;

    return newHead;
}
