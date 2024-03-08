
//typedef struct node bstNode;
typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}bstNode;

void insert_bst(bstNode **root, int val);
bstNode* create_node( int val);
//void level_order_trav(Queue *q, bstNode *root);