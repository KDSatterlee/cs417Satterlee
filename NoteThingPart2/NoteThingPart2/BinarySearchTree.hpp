#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>

template <typename K, typename C>
class NoteCard {
public:
    K keywords;   // Keywords associated with the note card
    C content;    // Content of the note card

    // Constructor to initialize keywords and content
    NoteCard(K key, C text);
};

template <typename K, typename C>
class TreeNode {
public:
    NoteCard<K, C> data;  // Data (a NoteCard) stored in the node
    TreeNode* left;      // Pointer to the left child node
    TreeNode* right;     // Pointer to the right child node

    // Constructor to initialize data and child pointers
    TreeNode(K key, C text);
};

template <typename K, typename C>
class BinarySearchTree {
private:
    TreeNode<K, C>* root;  // Pointer to the root node

    // Private recursive function for inserting a node
    TreeNode<K, C>* insert(TreeNode<K, C>* current, K key, C text);

    // Private recursive function for searching a node
    TreeNode<K, C>* search(TreeNode<K, C>* current, K key);

    // Private recursive function for in-order traversal
    void inorderTraversal(TreeNode<K, C>* current);

public:
    // Constructor to initialize the tree
    BinarySearchTree();

    // Public function to insert a note card into the tree
    void insert(K key, C text);

    // Public function to search for a note card by keywords
    bool search(K key);

    // Public function to perform in-order traversal of the tree
    void inorderTraversal();
};

#endif
