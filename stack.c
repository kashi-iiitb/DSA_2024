#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"
#include "stack.h"

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

bstNode* peek(Stack *s) {
    if(is_stack_empty(s)) {
        printf("Stack is Empty, Unable to Pop");
        return NULL;
    }
    return (s->top)->dataNode;
    /*stackNode *tempStNodePtr = s->top;
    s->top = tempStNodePtr->next;
    tempStNodePtr->next = NULL;
    bstNode *tempBstNode = tempStNodePtr->dataNode;
    free(tempStNodePtr);
    return tempBstNode;*/

}