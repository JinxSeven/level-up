#include <iostream>
#include <queue>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to invert the binary tree
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        // Recursively invert the left and right subtrees
        invertTree(root->left);
        invertTree(root->right);

        // Swap the left and right children
        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        return root;
    }
};

// Helper function to print the tree (level-order traversal)
void printTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }

    std::queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        std::cout << current->val << " ";

        if (current->left != nullptr) {
            q.push(current->left);
        }
        if (current->right != nullptr) {
            q.push(current->right);
        }
    }
    std::cout << std::endl;
}

// Main function for testing
int main() {
    // Example tree:
    //      4
    //    /   \
    //   2     7
    //  / \   / \
    // 1   3 6   9
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(9);

    std::cout << "Original tree (level-order): ";
    printTree(root);

    // Invert the tree
    Solution solution;
    TreeNode* invertedRoot = solution.invertTree(root);

    std::cout << "Inverted tree (level-order): ";
    printTree(invertedRoot);

    return 0;
}