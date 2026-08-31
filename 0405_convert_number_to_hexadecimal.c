#include <stdlib.h>
#include <string.h>

char* toHex(int num) {
    if (num == 0) {
        char* res = (char*)malloc(2 * sizeof(char));
        res[0] = '0';
        res[1] = '\0';
        return res;
    }

    char hex_chars[] = "0123456789abcdef";
    char* result = (char*)malloc(9 * sizeof(char));
    char temp[9];
    int len = 0;

    unsigned int n = (unsigned int)num;

    while (n > 0) {
        int remainder = n & 15;
        temp[len] = hex_chars[remainder];
        len++;
        n = n >> 4;
    }

    for (int i = 0; i < len; i++) {
        result[i] = temp[len - 1 - i];
    }
    result[len] = '\0';

    return result;
}
