#include <stdio.h>
#include <stdlib.h>

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

int minDepth(struct TreeNode* root){
    if (root == NULL) {
        return 0; // A profundidade mínima de uma árvore vazia é 0
    } else 
        if (root->left == NULL && root->right == NULL) {
            return 1; // Se for uma folha, a profundidade mínima é 1
    } else 
        if (root->left == NULL) {
            return 1 + minDepth(root->right); // A profundidade mínima é 1 mais a profundidade da subárvore direita
    } else 
        if (root->right == NULL) {
            return 1 + minDepth(root->left); // A profundidade mínima é 1 mais a profundidade da subárvore esquerda
    } else {
    // A profundidade mínima é 1 mais o mínimo entre as profundidades das subárvores esquerda e direita
        int leftDepth = minDepth(root->left);
        int rightDepth = minDepth(root->right);
        if (leftDepth < rightDepth) {
            return 1 + leftDepth;
        } else {
            return 1 + rightDepth;
        }
    }  
}

int main() {
    int minDepthValue;
    struct TreeNode* root1 = createNode(3);
    root1->left = createNode(9);
    root1->right = createNode(20);
    root1->right->left = createNode(15);
    root1->right->right = createNode(7);

    // Exemplo da árvore 1:
    //        3
    //       / \
    //      9   20
    //         / \
    //       15   7


    minDepthValue = minDepth(root1);
    printf("A profundidade mínima da árvore 1 é: %d\n", minDepthValue);

    free(root1->right->right);
    free(root1->right->left);
    free(root1->right);
    free(root1->left);
    free(root1);

    struct TreeNode* root2 = createNode(2);
    root2->left = createNode(3);
    root2->left->left = createNode(4);
    root2->left->left->left = createNode(5);
    root2->left->left->left->left = createNode(6);

    // Exemplo da árvore 2:
    //        2
    //         \
    //          3
    //           \
    //            4
    //             \
    //              5
    //               \
    //                6
    
    minDepthValue = minDepth(root2);
    printf("A profundidade mínima da árvore 1 é: %d\n", minDepthValue);

    free(root2->left->left->left->left);
    free(root2->left->left->left);
    free(root2->left->left);
    free(root2->left);
    free(root2);
    return 0;
}