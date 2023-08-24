#include "BinarySearchTree.hpp"


int main() {
    BinarySearchTree<std::string, std::string> bst;

    // Create and insert note cards
    bst.insert("Topic A", "This is the content for Topic A.");
    bst.insert("Topic B", "Content for Topic B.");
    bst.insert("Topic C", "Here's the content for Topic C.");

    // Search for a note card by keywords
    std::string searchKeywords = "Topic B";
    if (bst.search(searchKeywords)) {
        std::cout << "Note card with keywords '" << searchKeywords << "' found." << std::endl;
    } else {
        std::cout << "Note card with keywords '" << searchKeywords << "' not found." << std::endl;
    }

    // Perform an in-order traversal to access all note cards
    std::cout << "All note cards:" << std::endl;
    bst.inorderTraversal();

    return 0;
}
