class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int left = 0;
        int right = m * n - 1;
        while (left <= right)
        {
            int middle = left + (right - left) / 2;
            int row = middle / n;
            int column = middle % n;
            if (target == matrix[row][column])
            {
                return true;
            }
            if (target > matrix[row][column])
            {
                left = middle + 1;
            }
            else
            {
                right = middle - 1;
            }
        }
        return false;
    }
};

