typedef struct stackNode{
    bstNode *dataNode;
    struct stackNode *next;
}stackNode;

typedef struct stack{
    struct stackNode *top;
}Stack;

stackNode* create_stack_node(bstNode *val);
void push(Stack *s, bstNode *val);
bool is_stack_empty(Stack *s);
bstNode* pop(Stack *s);
bstNode* peek(Stack *s);

