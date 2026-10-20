#include <string.h>
char* reversePrefix(char* s, int k) {
    int len = strlen(s);
    int limit = (k < len) ? k : len;

    int left = 0;
    int right = limit - 1;

    while(left < right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;

    }
    return s;
}