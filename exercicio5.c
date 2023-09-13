#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct TreeNode{
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* createNode(int val){
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

bool hasPathSum(struct TreeNode* root, int targetSum){
    if (root == NULL) {
        return false;
    }
    if (root->left == NULL && root->right == NULL) {
        return root->val == targetSum;
    }
    int sum = targetSum - root->val;
    return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
}

struct TreeNode* NullNode() {
    return NULL;
}

int main() {
    int targetSum;
    bool path;
    struct TreeNode* root1 = createNode(5);
    root1->left = createNode(4);
    root1->right = createNode(8);
    root1->left->left = createNode(11);
    root1->right->left = createNode(13);
    root1->right->right = createNode(4);
    root1->left->left->left = createNode(7);
    root1->left->left->right = createNode(2);
    root1->right->right->right = createNode(1);

    // Exemplo da árvore 1:
    //        5
    //       / \
    //      4   8
    //     /   / \
    //    11  13  4
    //   /  \      \
    //  7    2      1

    targetSum = 22;
    path = hasPathSum(root1, targetSum);
    
    if (path) {
        printf("Existe um caminho com a soma do target.\n");
    } else {
        printf("Não existe um caminho com a soma do target.\n");
    }

    free(root1->left->left->right);
    free(root1->left->left->left);
    free(root1->right->right->right);
    free(root1->right->right);
    free(root1->right->left);
    free(root1->left->left);
    free(root1->right);
    free(root1->left);
    free(root1);

    struct TreeNode* root2 = createNode(1);
    root2->left = createNode(2);
    root2->right = createNode(3);

    // Exemplo da árvore 2:
    //        5
    //       / \
    //      4   8

    targetSum = 5;
    path = hasPathSum(root2, targetSum);
    if (path) {
        printf("Existe um caminho com a soma do target.\n");
    } else {
        printf("Não existe um caminho com a soma do target.\n");
    }

    free(root2->right);
    free(root2->left);
    free(root2);

    struct TreeNode* root3 = NullNode();

    // Exemplo da árvore 3:
    //     
    //    / \

    targetSum = 0;
    path = hasPathSum(root3, targetSum);
    if (path) {
        printf("Existe um caminho com a soma do target.\n");
    } else {
        printf("Não existe um caminho com a soma do target.\n");
    }

    free(root3);
    return 0;
}