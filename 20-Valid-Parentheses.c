bool isValid(char* s) {
    int len = strlen(s);
    if (len % 2 != 0) return false;

    // Allocate stack on heap (or char stack[len] on stack)
    char* stack = (char*)malloc(len * sizeof(char));
    int top = -1;

    for (int i = 0; i < len; i++) {
        char c = s[i];

        // Push expected closing bracket onto the stack
        if (c == '(') {
            stack[++top] = ')';
        } else if (c == '{') {
            stack[++top] = '}';
        } else if (c == '[') {
            stack[++top] = ']';
        } 
        // If it's a closing bracket:
        // Must have matching bracket on top of stack
        else {
            if (top == -1 || stack[top--] != c) {
                free(stack);
                return false;
            }
        }
    }

    bool valid = (top == -1);
    free(stack);
    return valid;
}
