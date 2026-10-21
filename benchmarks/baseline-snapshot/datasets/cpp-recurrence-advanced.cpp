#include <bits/stdc++.h>
using namespace std;

int partitionForDataset(vector<int>& values, int low, int high) {
    int pivot = values[high];
    int write = low;
    for (int scan = low; scan < high; ++scan) {
        if (values[scan] < pivot) swap(values[write++], values[scan]);
    }
    swap(values[write], values[high]);
    return write;
}

void partitionRecurrenceWorstCase(vector<int>& values, int low, int high) {
    if (low < high) {
        int pivot = partitionForDataset(values, low, high);
        partitionRecurrenceWorstCase(values, low, pivot - 1);
        partitionRecurrenceWorstCase(values, pivot + 1, high);
    }
}

struct DatasetTreeNode {
    DatasetTreeNode* left = nullptr;
    DatasetTreeNode* right = nullptr;
};

int countDatasetTree(DatasetTreeNode* root) {
    if (!root) return 0;
    return 1 + countDatasetTree(root->left) + countDatasetTree(root->right);
}

bool safeDatasetQueen(vector<int>& board, int row, int col) {
    for (int previous = 0; previous < row; ++previous) {
        if (board[previous] == col) return false;
    }
    return true;
}

void placeDatasetQueens(vector<int>& board, int row, int n, int& count) {
    if (row == n) {
        ++count;
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (safeDatasetQueen(board, row, col)) {
            board[row] = col;
            placeDatasetQueens(board, row + 1, n, count);
        }
    }
}

int mixedRatioDataset(int n) {
    if (n <= 1) return 1;
    return mixedRatioDataset(n / 2) + mixedRatioDataset(n / 3);
}

int opaqueMixedDataset(int n, int step) {
    if (n <= 1) return 1;
    return opaqueMixedDataset(n - step, step) + opaqueMixedDataset(n / 2, step);
}
