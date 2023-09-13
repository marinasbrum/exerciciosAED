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

void flatten(struct TreeNode* root) {
    struct TreeNode* prev = NULL;

    while (root != NULL) {
        if (root->left != NULL) {
            struct TreeNode* pright = root->left;
            while (pright->right != NULL) {
                pright = pright->right;
            }
            pright->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
        root = root->right;
    }
}

void print(struct TreeNode* head) {
    struct TreeNode* current = head;
    while (current != NULL) {
        printf("%d -> ", current->val);
        current = current->right;
    }
    printf("NULL\n");
}

struct TreeNode* NullNode() {
    return NULL;
}

int main() {
    struct TreeNode* root1 = createNode(1);
    root1->left = createNode(2);
    root1->right = createNode(5);
    root1->left->left = createNode(3);
    root1->left->right = createNode(4);
    root1->right->right = createNode(6);

    // Exemplo árvore 1:
    //     1
    //    / \
    //   2   5
    //  / \  \
    // 3   4  6

    flatten(root1);
    printf("Lista encadeada pré-ordem: ");
    print(root1);
    
    free(root1->right->right);
    free(root1->left->right);
    free(root1->left->left);
    free(root1->right);
    free(root1->left);
    free(root1);

    struct TreeNode* root2 = NullNode();
    
    // Exemplo árvore 2:
    //     
    //    / \
    //
    
    flatten(root2);
    printf("Lista encadeada 2: ");
    print(root2);

    free(root2);
        
    struct TreeNode* root3 = createNode(0);
    
    // ExemplO árvore 3:
    //     0
    //    / \
    //
    
    flatten(root3);
    printf("Lista encadeada 3: ");
    print(root3);
    free(root3);    
    return 0;
}