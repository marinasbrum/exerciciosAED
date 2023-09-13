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

// Função para inverter uma árvore binária
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }

    struct TreeNode* temp = root->left;
    root->left = invertTree(root->right);
    root->right = invertTree(temp);

    return root;
}

void print(struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val); 
    print(root->left); 
    print(root->right);
}

struct TreeNode* NullNode() {
    return NULL;
}

int main() {
    struct TreeNode* root1 = createNode(4);
    root1->left = createNode(2);
    root1->right = createNode(7);
    root1->left->left = createNode(1);
    root1->left->right = createNode(3);
    root1->right->left = createNode(6);
    root1->right->right = createNode(9);

    // Exemplo da árvore 1 original:
    //        4
    //       / \
    //      2   7
    //     / \ / \
    //    1  3 6  9

    printf("Árvore 1 em ordem: ");
    print(root1);
    printf("\n");
    root1 = invertTree(root1);

    // Exemplo da árvore 1 invertida:
    //        4
    //       / \
    //      7   2
    //     / \ / \
    //    9  6 3  1

    printf("Árvore 1 invertida: ");
    print(root1);
    printf("\n");
    
    free(root1->right->right);
    free(root1->right->left);
    free(root1->right);
    free(root1->left->right);
    free(root1->left->left);
    free(root1->left);
    free(root1);

    struct TreeNode* root2 = createNode(2);
    root2->left = createNode(1);
    root2->right = createNode(3);

    // Exemplo da árvore 2 invertida:
    //        2
    //       / \
    //      1   3

    printf("\nÁrvore 2 em ordem: ");
    print(root2);
    printf("\n");
    root2 = invertTree(root2);

    // Exemplo da árvore 2 invertida:
    //        2
    //       / \
    //      3   1

    printf("Árvore 1 invertida: ");
    print(root2);
    printf("\n");

    free(root2->right);
    free(root2->left);
    free(root2);

    struct TreeNode* root3 = NullNode();
    printf("\nÁrvore 3 em ordem: ");
    print(root3);
    printf("\n");
    root3 = invertTree(root3);

    printf("Árvore 3 invertida: ");
    print(root3);
    printf("\n");
    free(root3);

    return 0;
}
