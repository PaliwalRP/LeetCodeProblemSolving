class NumMatrix {
public:
    NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            return;
        }

        const auto m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i <= m; ++i) {
            sums_.emplace_back(n + 1, 0);
        }
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                sums_[i][j] = sums_[i][j - 1] + sums_[i - 1][j] -
                              sums_[i - 1][j - 1] + matrix[i - 1][j - 1];
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums_[row2 + 1][col2 + 1] - sums_[row2 + 1][col1] - 
               sums_[row1][col2 + 1] + sums_[row1][col1];   
    }

private:
    vector<vector<int>> sums_;
};