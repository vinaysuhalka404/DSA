// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* ptr = (struct Node*) malloc(sizeof(struct Node));
    if(ptr == NULL){
        printf("Memory cannot be allocate");
    }
    ptr->data = data;
    ptr->left = ptr->right = NULL;
    return ptr;
}

struct Node* insert(struct Node* root, int data){
    if(root == NULL){
        return newNode(data);
    }
    else if(root->data > data){
        root->left = insert(root->left, data);
    }else if(root->data < data){
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* getSuccessor(struct Node* root){
    struct Node* curr = root->right;
    while(curr->left != NULL){
        curr = curr->left;
    }
    return curr;
}

struct Node* delNode(struct Node* root, int data){
    if(root == NULL){
        return NULL;
    }
    if(root->data > data){
        root->left = delNode(root->left, data);
    }
    else if(root->data < data){
        root->right = delNode(root->right, data);
    }
    else{
        if(root->left == NULL && root->right == NULL){
            free(root);
            printf("Delete : %d", data);
            return NULL;
        }
        else if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            printf("Delete : %d", data);
            return temp;
        }
        else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            printf("Delete : %d", data);
            return temp;
        }else{
            struct Node* temp = getSuccessor(root);
            root->data = temp->data;
            root->right = delNode(root->right, data);
        }
    }
    return root;
}

void inorder(struct Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d\n", root->data);
    inorder(root->right);
}

void preorder(struct Node* root){
    if(root == NULL){
        return;
    }
    printf("%d\n", root->data);
    inorder(root->left);
    inorder(root->right);
}

void postorder(struct Node* root){
    if(root == NULL){
        return;
    }
    inorder(root->left);
    inorder(root->right);
    printf("%d\n", root->data);
}

int main() {
    struct Node* root = newNode(5);
    insert(root, 8);
    insert(root, 3);
    insert(root, 4);
    insert(root, 6);
    
    printf("Inorder :-\n");
    inorder(root);
    delNode(root, 3);
    printf("Pre-order :-\n");
    preorder(root);
    printf("Post-order :-\n");
    postorder(root);
    return 0;
}