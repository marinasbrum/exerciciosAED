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

bool AuxiliarBST(struct TreeNode* root, struct TreeNode* minNode, struct TreeNode* maxNode) {
    if (root == NULL) {
        return true; // Uma árvore vazia é uma BST
    }

    // Testa regra 1 e 2
    //1. A subárvore esquerda de um nó contém apenas nós com chaves menores que a chave do nó.
    //2. A subárvore direita de um nó contém apenas nós com chaves maiores que a chave do nó.
    if ((minNode != NULL && root->val <= minNode->val) || (maxNode != NULL && root->val >= maxNode->val)) {
        return false;
    }

    // 3. As subárvores esquerda e direita também devem ser árvores de pesquisa binária.
    return AuxiliarBST(root->left, minNode, root) && AuxiliarBST(root->right, root, maxNode);
}

bool isValidBST(struct TreeNode* root) {
    return AuxiliarBST(root, NULL, NULL);
}

int main() {
    struct TreeNode* root1 = createNode(2);
    root1->left = createNode(1);
    root1->right = createNode(3);

    // Exemplo da árvore 1:
    //    2
    //   / \
    //  1   3

    bool isValid1 = isValidBST(root1);
    printf("É uma BST? ");
    if (isValid1) {
        printf("Sim\n");
    } else {
        printf("Não\n");
    }    

    free(root1->left);
    free(root1->right);
    free(root1);

    struct TreeNode* root2 = createNode(5);
    root2->left = createNode(1);
    root2->right = createNode(4);
    root2->right->left = createNode(3);
    root2->right->right = createNode(6);
    
    // Exemplo da árvore 2:
    //    5
    //   / \
    //  1   4
    //     / \
    //    3   6
    
    bool isValid2 = isValidBST(root2);
    printf("É uma BST? ");
    if (isValid2) {
        printf("Sim\n");
    } else {
        printf("Não\n");
    }    
    free(root2->left);
    free(root2->right->left);
    free(root2->right->right);
    free(root2->right);
    free(root2);

    return 0;
    
}