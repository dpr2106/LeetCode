class Solution:
    def weightedSum(self, parent, nums):
        n = len(parent)
        depth = [0] * n

        depth[0] = 1
        ht = 1
        total = 0

        def fn(node):
            if parent[node] == -1:
                return 1

            if depth[node] != 0:
                return depth[node]

            depth[node] = fn(parent[node]) + 1
            return depth[node]

        for i in range(n):
            if depth[i] == 0:
                fn(i)

            ht = max(ht, depth[i])

        for i in range(n):
            total += nums[i] * (ht - depth[i] + 1)

        return total