#include "BinarySearchTree.hpp"

// Implementation of NoteCard constructor
template <typename K, typename C>
NoteCard<K, C>::NoteCard(K key, C text) : keywords(key), content(text) {}

// Implementation of TreeNode constructor
template <typename K, typename C>
TreeNode<K, C>::TreeNode(K key, C text) : data(key, text), left(nullptr), right(nullptr) {}

// Implementation of BinarySearchTree constructor
template <typename K, typename C>
BinarySearchTree<K, C>::BinarySearchTree() : root(nullptr) {}

// Implementation of private recursive function for inserting a node
template <typename K, typename C>
TreeNode<K, C>* BinarySearchTree<K, C>::insert(TreeNode<K, C>* current, K key, C text) {
    if (current == nullptr) {
        return new TreeNode<K, C>(key, text);
    }

    if (key < current->data.keywords) {
        current->left = insert(current->left, key, text);
    } else if (key > current->data.keywords) {
        current->right = insert(current->right, key, text);
    }

    return current;
}

// Implementation of public function to insert a note card into the tree
template <typename K, typename C>
void BinarySearchTree<K, C>::insert(K key, C text) {
    root = insert(root, key, text);
}

// Implementation of private recursive function for searching a node
template <typename K, typename C>
TreeNode<K, C>* BinarySearchTree<K, C>::search(TreeNode<K, C>* current, K key) {
    if (current == nullptr || current->data.keywords == key) {
        return current;
    }

    if (key < current->data.keywords) {
        return search(current->left, key);
    }

    return search(current->right, key);
}

// Implementation of public function to search for a note card by keywords
template <typename K, typename C>
bool BinarySearchTree<K, C>::search(K key) {
    TreeNode<K, C>* result = search(root, key);
    return (result != nullptr);
}

// Implementation of private recursive function for in-order traversal
template <typename K, typename C>
void BinarySearchTree<K, C>::inorderTraversal(TreeNode<K, C>* current) {
    if (current != nullptr) {
        inorderTraversal(current->left);
        std::cout << "Keywords: " << current->data.keywords << ", Content: " << current->data.content << std::endl;
        inorderTraversal(current->right);
    }
}
