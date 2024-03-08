typedef struct queueNode{
    bstNode *dataNode;
    struct queueNode *next;
}queueNode;

typedef struct queue{
    struct queueNode *front;
    struct queueNode *rear;
}Queue;

queueNode* create_queue_node(bstNode *val);
void enqueue(Queue *q, bstNode *val);
bool is_queue_empty(Queue *q);
bstNode* dequeue(Queue *q);

