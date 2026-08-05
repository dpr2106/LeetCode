class Solution(object):
    def isPowerOfThree(self, n):
        # Powers of three must be strictly positive
        if n <= 0:
            return False
            
        # Continuously divide by 3 if there is no remainder
        while n % 3 == 0:
            n //= 3
            
        # If the final remaining number is 1, it was a power of three
        return n == 1