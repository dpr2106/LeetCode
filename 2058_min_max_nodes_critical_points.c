/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nodesBetweenCriticalPoints(struct ListNode* head, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));
    result[0] = -1;
    result[1] = -1;

   
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
        return result;
    }

    struct ListNode* prev = head;
    struct ListNode* curr = head->next;

    int position = 2;      
    int first_cp = -1;      
    int prev_cp = -1;       
    int min_dist = 1000000; 
    while (curr->next != NULL) {
       
        int is_maxima = (curr->val > prev->val && curr->val > curr->next->val);
        int is_minima = (curr->val < prev->val && curr->val < curr->next->val);

        if (is_maxima || is_minima) {
            if (first_cp == -1) {
            
                first_cp = position;
                prev_cp = position;
            } else {
               
                int dist = position - prev_cp;
                if (dist < min_dist) {
                    min_dist = dist;
                }
                prev_cp = position;
            }
        }

      
        prev = curr;
        curr = curr->next;
        position++;
    }

    if (first_cp != -1 && first_cp != prev_cp) {
        result[0] = min_dist;
        result[1] = prev_cp - first_cp;
    }

    return result;
}