class Solution {
public:
    vector<vector<int>> original, updated;
    vector<int> newParent, ans;
    int last[26];

    void dfs1(int u, string &s) {
        int c = s[u] - 'a';

        int previous = last[c];
        last[c] = u;

        for (int v : original[u]) {
            if (last[s[v] - 'a'] != -1)
                newParent[v] = last[s[v] - 'a'];
            else
                newParent[v] = u;

            dfs1(v, s);
        }

        last[c] = previous;
    }

    int dfs2(int u) {
        int size = 1;

        for (int v : updated[u]) {
            size += dfs2(v);
        }

        ans[u] = size;
        return size;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();

        original.resize(n);
        updated.resize(n);
        newParent.resize(n);
        ans.resize(n);

        fill(last, last + 26, -1);

        // Build original tree
        for (int i = 1; i < n; i++) {
            original[parent[i]].push_back(i);
        }

        newParent[0] = -1;

        // Find new parents using original tree
        dfs1(0, s);

        // Build modified tree
        for (int i = 1; i < n; i++) {
            updated[newParent[i]].push_back(i);
        }

        // Calculate subtree sizes
        dfs2(0);

        return ans;
    }
};