class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char, int> umap;
        for (char c : text) {
            umap[c] ++;
        }
        return min({umap['b'], umap['a'], umap['l'] / 2, umap['o'] / 2, umap['n']});
    }
};