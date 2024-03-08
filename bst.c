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
#include "bst.h"
#include "stack.h"
#include "queue.h"

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

void level_order_trav( bstNode *root){
    Queue q = {.front=NULL, .rear=NULL };
    //queueNode *qNode = create_queue_node(root);
    enqueue(&q, root);
    do{
        bstNode *tempBstNode = dequeue(&q);
        printf("%d ", tempBstNode->data);
        if(tempBstNode->left){
            enqueue(&q, tempBstNode->left);
        } 
        if(tempBstNode->right) {
            enqueue(&q, tempBstNode->right);
        }
    } while(!is_queue_empty(&q));
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
    printf("\nInorder traversal of the tree: ");
    inorder_bst(root);
    printf("\nLevel order traversal of the tree: ");
    level_order_trav(root);
}
