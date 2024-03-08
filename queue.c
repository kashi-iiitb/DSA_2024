#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "bst.h"
#include "queue.h"

queueNode* create_queue_node(bstNode *val) {
    queueNode *tempQNode = malloc(sizeof(queueNode));
    if(!tempQNode){
        printf("unable to allocate memory\n");
        return NULL;
    }
    tempQNode->dataNode = val;
    tempQNode->next = NULL;
    return tempQNode;
}

void enqueue(Queue *q, bstNode *val) {
    queueNode *tempQNode = create_queue_node(val);

    if(is_queue_empty(q)){
        q->front = q->rear = tempQNode;
        return;
    }
    q->rear->next = tempQNode;
    q->rear = tempQNode;
}

bool is_queue_empty(Queue *q){
    if(q->rear == NULL)
        return true;
    else
        return false;
}

bstNode* dequeue(Queue *q) {
    if(is_queue_empty(q)) {
        printf("queue is Empty, Unable to dequeue");
        return NULL;
    }


    queueNode *tempQNodePtr = q->front;
    if(q->front == q->rear){ //there is only one element in the queue
        q->front = q->rear = NULL;
    } else {
        q->front = q->front->next;
    }    
    tempQNodePtr->next = NULL;
    bstNode *tempBstNode = tempQNodePtr->dataNode;
    free(tempQNodePtr);
    return tempBstNode;
}