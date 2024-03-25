/*****************************************************************************************
AUTHOR:	KASHINATH CHILLAL
DATE:	24th March 2024 
AIM:	Write a program to implement Trie data structure.
DESCRIPTION:
	1. Write a function to insert node in Trie
    2. Implement a function to search if a given word is present in the Trie or not
    3. Write a recursive function to display all the words in the Trie
EXPECTED OUTPUT: 
    List of all the words in the Trie
*****************************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h> //for sleep()
#include <string.h>
#include "Trie.h"

void insert_trie_node(TrieNode **root, char *str);
TrieNode* create_trie_node();
void display_trie(TrieNode *root);
void display_trie_rec(TrieNode *root, char *prefix, unsigned int prefix_len);

TrieNode* create_trie_node() {
    TrieNode *temp = malloc(sizeof(TrieNode));
    if(!temp) {
        return NULL;
    }
    for(int i=0; i<256; i++) {
        temp->char_ptr[i] = NULL;
    }
    return temp;
}

void insert_trie(TrieNode **root, char *str) {
    unsigned int len = strlen(str);
    //TrieNode *temp = create_node();
    if(*root == NULL) {
        *root = create_trie_node();
    }
    TrieNode *trav_ptr = *root;
    for(__uint16_t i=0; i<len; i++) {
        if(trav_ptr->char_ptr[str[i]]){
            trav_ptr = trav_ptr->char_ptr[str[i]];
        } else {
            trav_ptr->char_ptr[str[i]] = create_trie_node();
            trav_ptr = trav_ptr->char_ptr[str[i]];
        }
    }
    trav_ptr->terminal = true;
}

bool search_trie(TrieNode *root, char *str) {
    char str_len = strlen(str);
    TrieNode *trav_ptr = root;
    bool found = false;
    __uint16_t i = 0;
    for(i=0; i<str_len; i++) {
        if(trav_ptr->char_ptr[str[i]]) {
            trav_ptr = trav_ptr->char_ptr[str[i]];
        } else {
            break;
        }
    }
    if((!str[i]) && trav_ptr->terminal) {
        printf("Word %s is present in the Trie\n", str);
        return true;        
    } else {
        printf("Word %s is not present in the Trie\n", str);
        return false;        
    }
}
void display_trie_rec(TrieNode *node, char *prefix, unsigned int prefix_len) {
    TrieNode *trav_ptr = node;
    char new_prefix[prefix_len+2];
    memset(new_prefix, 0, prefix_len+2);
    memcpy(new_prefix, prefix, prefix_len);
    if(node->terminal){
        printf(" %s\n", new_prefix);        
    }
    for(int i=0; i<256; i++){
        if(trav_ptr->char_ptr[i]){
            new_prefix[prefix_len]=i;
            display_trie_rec(trav_ptr->char_ptr[i], new_prefix, prefix_len+1);
        }
    }
}


void display_trie(TrieNode *root) {
    if(root == NULL) {
        printf("\nTrie is empty\n");
        return;
    }
    TrieNode *trav_ptr = root;
    display_trie_rec(trav_ptr, NULL, 0);
    /*for(int i=0; i<256; i++){
        if(trav_ptr->char_ptr[i])
    }*/
}

int main() {
    TrieNode *root = NULL;

    insert_trie(&root, "kashi");
    insert_trie(&root, "kashinath");
    insert_trie(&root, "cat");
    insert_trie(&root, "catch");

    printf("\nThe contents of the Trie:\n");
    display_trie(root);
    search_trie(root, "Hello");
    search_trie(root, "cisco");
    search_trie(root, "catchy");
    search_trie(root, "cat");
    search_trie(root, "kashinath");

}
