class NumMatrix {
private:
    int m, n;
    vector<vector<int>> data, tree;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) return;
        m = matrix.size(), n = matrix[0].size();
        myResize(data, m, n);
        myResize(tree, m + 1, n + 1);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                update(i, j, matrix[i][j]);
            }
        }
    }

    void myResize(vector<vector<int>>& v, int r, int c) {
        v.resize(r);
        for (int i = 0; i < r; ++i) {
            v[i].resize(c);
        }
    }
    
    void update(int row, int col, int val) {
        int delta = val - data[row][col];
        data[row][col] = val;
        for (int i = row + 1; i <= m; i += i & (-i)) {
            for (int j = col + 1; j <= n; j += j & (-j)) {
                tree[i][j] += delta;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (m == 0 || n == 0) return 0;
        return sum(row2 + 1, col2 + 1) + sum(row1, col1) - sum(row1, col2+1) - sum(row2+1, col1);
    }

    int sum(int row, int col) {
        int cnt = 0;
        for (int i = row; i > 0; i -= i & (-i)) {
            for (int j = col; j > 0; j -= j & (-j)) {
                cnt += tree[i][j];
            }
        }
        return cnt;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * obj->update(row,col,val);
 * int param_2 = obj->sumRegion(row1,col1,row2,col2);
 */