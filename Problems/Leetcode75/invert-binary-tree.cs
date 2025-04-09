using System;
using System.Collections.Generic;

// Definition for a binary tree node.
public class TreeNode {
    public int val;
    public TreeNode left;
    public TreeNode right;
    public TreeNode(int x) { val = x; }
}

// Class to invert the binary tree
public class Solution {
    public TreeNode InvertTree(TreeNode root) {
        if (root == null) {
            return null;
        }

        // Recursively invert the left and right subtrees
        InvertTree(root.left);
        InvertTree(root.right);

        // Swap the left and right children
        TreeNode temp = root.left;
        root.left = root.right;
        root.right = temp;

        return root;
    }
}

// Helper class to print the tree (level-order traversal)
public static class TreePrinter {
    public static void PrintTree(TreeNode root) {
        if (root == null) {
            return;
        }

        Queue<TreeNode> queue = new Queue<TreeNode>();
        queue.Enqueue(root);

        while (queue.Count > 0) {
            TreeNode current = queue.Dequeue();
            Console.Write(current.val + " ");

            if (current.left != null) {
                queue.Enqueue(current.left);
            }
            if (current.right != null) {
                queue.Enqueue(current.right);
            }
        }
        Console.WriteLine();
    }
}

// Main class for testing
public class Program {
    public static void Main(string[] args) {
        // Example tree:
        //      4
        //    /   \
        //   2     7
        //  / \   / \
        // 1   3 6   9
        TreeNode root = new TreeNode(4);
        root.left = new TreeNode(2);
        root.right = new TreeNode(7);
        root.left.left = new TreeNode(1);
        root.left.right = new TreeNode(3);
        root.right.left = new TreeNode(6);
        root.right.right = new TreeNode(9);

        Console.Write("Original tree (level-order): ");
        TreePrinter.PrintTree(root);

        // Invert the tree
        Solution solution = new Solution();
        TreeNode invertedRoot = solution.InvertTree(root);

        Console.Write("Inverted tree (level-order): ");
        TreePrinter.PrintTree(invertedRoot);
    }
}