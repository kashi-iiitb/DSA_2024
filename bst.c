/*****************************************************************************************
AUTHOR:	KASHINATH CHILLAL
DATE:	28th Feb 2024 
AIM:	Write a function to do inorder traversal of a BST in non-recursive way.
DESCRIPTION:
	1. Write a function to insert node in BST
    2. Implement a Stack to store the nodes of BST during inorder traversal
    3. Write a inorder traversal function using Stack
EXPECTED OUTPUT: 
    Numbers in Sorted format
*****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//typedef struct node bstNode;
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}bstNode;

typedef struct stackNode{
    bstNode *dataNode;
    struct stackNode *next;
}stackNode;

typedef struct stack{
    struct stackNode *top;
}Stack;

stackNode* create_stack_node(bstNode *val) {
    stackNode *tempStNode = malloc(sizeof(stackNode));
    if(!tempStNode){
        printf("unable to allocate memory\n");
        return NULL;
    }
    tempStNode->dataNode = val;
    tempStNode->next = NULL;
    return tempStNode;
}
void push(Stack *s, bstNode *val) {
    stackNode *tempStNode = create_stack_node(val);
    if(s->top == NULL){
        s->top = tempStNode;
        return;
    }
    tempStNode->next = s->top;
    s->top = tempStNode;
}

bool is_stack_empty(Stack *s){
    if(!s->top)
        return true;
    else
        return false;
}

bstNode* pop(Stack *s) {
    if(is_stack_empty(s)) {
        printf("Stack is Empty, Unable to Pop");
        return NULL;
    }
    stackNode *tempStNodePtr = s->top;
    s->top = tempStNodePtr->next;
    tempStNodePtr->next = NULL;
    bstNode *tempBstNode = tempStNodePtr->dataNode;
    free(tempStNodePtr);
    return tempBstNode;
}

void insert_bst(bstNode **root, int val);
bstNode* create_node( int val);


bstNode* create_node( int val) {
    bstNode *temp = malloc(sizeof(bstNode));
    if(!temp) {
        return NULL;
    }
    temp->data = val;
    temp->left = temp->right = NULL;
    return temp;
}

void insert_bst(bstNode **root, int val) {
    bstNode *temp = create_node(val);
    if(*root == NULL) {
        *root = temp;
        return;
    }
    bstNode *prev = NULL, *cur = *root;
    while(cur) {
        prev = cur;
        if(val < cur->data){
            cur = cur->left;
        } else {
            cur = cur->right;
        }
    }
    if(val < prev->data) {
        prev->left = temp;
    } else {
        prev->right = temp;
    }
}


//Display inorder requires stack. Implement a stack as well.
void inorder_bst(bstNode *root) {
    if(root == NULL) {
        printf("Binary search tree is empty\n");
        return;
    }
    bstNode *temp = root;
    Stack s = {.top = NULL};
    
    do {
        //bool done_left = false;
        while(temp){  //go to the last left node pushing nodes onto stack
            push(&s, temp);
            temp = temp->left;
        }
        // //printf(" %d",temp->data);
        // if(temp->right){ //right child is not null
        //     temp = temp->right;
        // } else {
        if(!is_stack_empty(&s)){
            temp = pop(&s);
            printf(" %d",temp->data);
            temp = temp->right;
        }
    } while(!is_stack_empty(&s) || temp!=NULL);
    // push(&s, root);
    // bstNode *tempBstNode = pop(&s);
    // printf("Popped data is %d\n", tempBstNode->data);
    // pop(&s);


}

int main() {
    bstNode *root = NULL;

    insert_bst(&root, 10);
    insert_bst(&root, 15);
    insert_bst(&root, 5);
    insert_bst(&root, 8);
    insert_bst(&root, 13);
    insert_bst(&root, 3);
    insert_bst(&root, 30);
    insert_bst(&root, 22);
    insert_bst(&root, 2);
    inorder_bst(root);
}
