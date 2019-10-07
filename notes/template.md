### Sliding window template:
```java
public class Solution {
    public List<Integer> slidingWindowTemplateByHarryChaoyangHe(String s, String t) {
        //init a collection or int value to save the result according the question.
        List<Integer> result = new LinkedList<>();
        if(t.length() > s.length()) return result;
        
        //create a hashmap to save the Characters of the target substring.
        //(K, V) = (Character, Frequence of the Characters)
        Map<Character, Integer> map = new HashMap<>();
        for(char c : t.toCharArray()){
            map.put(c, map.getOrDefault(c, 0) + 1);
        }
        //maintain a counter to check whether match the target string.
        int counter = map.size();//must be the map size, NOT the string size because the char may be duplicate.
        
        //Two Pointers: begin - left pointer of the window; end - right pointer of the window
        int begin = 0, end = 0;
        
        //the length of the substring which match the target string.
        int len = Integer.MAX_VALUE; 
        
        //loop at the begining of the source string
        while(end < s.length()){
            
            char c = s.charAt(end);//get a character
            
            if( map.containsKey(c) ){
                map.put(c, map.get(c)-1);// plus or minus one
                if(map.get(c) == 0) counter--;//modify the counter according the requirement(different condition).
            }
            end++;
            
            //increase begin pointer to make it invalid/valid again
            while(counter == 0 /* counter condition. different question may have different condition */){
                
                char tempc = s.charAt(begin);//***be careful here: choose the char at begin pointer, NOT the end pointer
                if(map.containsKey(tempc)){
                    map.put(tempc, map.get(tempc) + 1);//plus or minus one
                    if(map.get(tempc) > 0) counter++;//modify the counter according the requirement(different condition).
                }
                
                /* save / update(min/max) the result if find a target*/
                // result collections or result int value
                
                begin++;
            }
        }
        return result;
    }
}
```

### Quick sort template:
```cpp
int partition(vector<int> nums, int left, int right) {
    int pivot = nums[left];
    int l = left + 1, r = right;
    while (l <= r) {
        if (nums[l] < pivot && nums[r] > pivot) {
            swap(nums[l], nums[r]);
            l ++;
            r --;
        }
        if (nums[l] > pivot) {
            l ++;
        }
        if (nums[r] < pivot) {
            r --;
        }
    }
    swap(nums[left], nums[r]);
    return r;
}
```

### DFS template:
```cpp
void dfs(vector<vector<int>>& board, vector<vector<bool>>& visited, int r, int c) {
    if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || visited[r][c] == true || board[r][c] == 0) {
        return;
    }
    visited[r][c] = true;
    vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    for (auto dir : directions) {
        int row = r + dir.first, col = c + dir.second;
        dfs(board, visited, row, col);
    }
}
```

### BFS template:
```cpp
void bfs(TreeNode* node) {
    queue<TreeNode*> q;
    q.push(node);
    while (!q.empty()) {
        TreeNode* n = q.front();
        q.pop();
        if (n->left) {
            q.push(n->left);
        }
        if (n->right) {
            q.push(n->right);
        }
    }
}
```

### Tree pre/in/post-order traverse template:
```cpp
// recursive
void inorder(TreeNode* node, vector<int>& res) {
    if (!node) return;
    if (node->left) inorder(node->left);
    res.push_back(node->val);
    if (node->right) inorder(node->right);
}

// iterative
void inorder(TreeNode* node, vector<int>& res) {
    if (!root) return {};
    vector<int> res;
    stack<TreeNode*> stk;
    TreeNode* curr = root;
    while (curr || !stk.empty()) {
        while (curr) {
            stk.push(curr);
            curr = curr->left;
        }
        curr = stk.top();
        stk.pop();
        res.push_back(curr->val);
        curr = curr->right;
    }
}
```
### Tree level order traverse template:
```cpp
// dfs
void dfs(vector<vector<int>>& res, int level, TreeNode* root) {
    if (!root) return;
    if (res.size() == level) res.push_back(vector<int>());
    res[level].push_back(root->val);
    dfs(res, level + 1, root->left);
    dfs(res, level + 1, root->right);
}

// bfs
void bfs(TreeNode* node, vector<vector<int>>& res) {
    queue<TreeNode*> q;
    q.push(node);
    while (!q.empty()) {
        vector<int> out;
        int n = q.size();
        for (int i = 0; i < n; ++i) {
            TreeNode* temp = q.front();
            q.pop();
            out.push_back(temp->val);
            if (temp->left) q.push(temp->left);
            if (temp->right) q.push(temp->right);
        }
    }
}
```

### lca template:
```cpp
int deepest = 0;
TreeNode lca;

public TreeNode lcaDeepestLeaves(TreeNode root) {
    helper(root, 0);
    return lca;
}

private int helper(TreeNode node, int depth) {
    deepest = Math.max(deepest, depth);
    if (node == null) {
        return depth;
    }
    int left = helper(node.left, depth + 1);
    int right = helper(node.right, depth + 1);
    if (left == deepest && right == deepest) {
        lca = node;
    }
    return Math.max(left, right);
}
```