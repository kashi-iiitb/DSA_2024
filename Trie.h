

typedef struct TrieNode {
    struct TrieNode *char_ptr[256];
    bool terminal;
}TrieNode;

void insert_trie(TrieNode **root, char *str);
TrieNode* create_trie_node();
bool search_trie(TrieNode *root, char *str);
void display_trie(TrieNode *root);
void display_trie_rec(TrieNode *root, char *prefix, unsigned int prefix_len);