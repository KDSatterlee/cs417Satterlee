#include <iostream>
#include <memory>
#include <string>

class Rope {
private:
    struct Node {
        std::string data;
        int weight;
        std::shared_ptr<Node> left;
        std::shared_ptr<Node> right;

        Node(const std::string& str) : data(str), weight(str.length()), left(nullptr), right(nullptr) {}
    };

    std::shared_ptr<Node> root;

    // Private constructor used for creating Rope from a Node
    Rope(std::shared_ptr<Node> rootNode) : root(rootNode) {}

public:
    Rope() : root(nullptr) {}

    char index(int i) {
        return index(root, i);
    }

    char index(std::shared_ptr<Node> node, int i) {
        if (!node || i < 0 || i >= node->weight) {
            throw std::out_of_range("Index out of range");
        }

        if (node->weight == 1) {
            return node->data[i];
        }

        if (node->left && i < node->left->weight) {
            return index(node->left, i);
        } else if (node->right) {
            return index(node->right, i - (node->left ? node->left->weight : 0));
        } else {
            throw std::out_of_range("Index out of range");
        }
    }


    void concat(const Rope& s2) {
        std::shared_ptr<Node> newRoot = std::make_shared<Node>("");
        newRoot->left = root;
        newRoot->right = s2.root;
        newRoot->weight = (root ? root->weight : 0) + (s2.root ? s2.root->weight : 0);
        root = newRoot;
    }

    std::pair<Rope, Rope> split(int i) {
        if (i < 0 || i > (root ? root->weight : 0)) {
            throw std::out_of_range("Split index out of range");
        }

        if (!root) {
            return std::make_pair(Rope(), Rope());
        }

        if (i == 0) {
            return std::make_pair(Rope(), *this);
        }

        if (i == root->weight) {
            return std::make_pair(*this, Rope());
        }

        return split(root, i);
    }

    std::pair<Rope, Rope> split(std::shared_ptr<Node> node, int i) {
        if (!node) {
            throw std::out_of_range("Node is null");
        }

        if (i < 0 || i > node->weight) {
            throw std::out_of_range("Split index out of range");
        }

        if (i == 0) {
            return std::make_pair(Rope(), Rope(node));
        }

        if (i == node->weight) {
            return std::make_pair(Rope(node), Rope());
        }

        if (i < node->left->weight) {
            auto splitResult = split(node->left, i);
            node->left = splitResult.second.root;
            node->weight -= splitResult.second.root ? splitResult.second.root->weight : 0;
            return std::make_pair(splitResult.first, Rope(node));
        } else {
            auto splitResult = split(node->right, i - node->left->weight);
            node->right = splitResult.first.root;
            node->weight -= splitResult.first.root ? splitResult.first.root->weight : 0;
            return std::make_pair(Rope(node), splitResult.second);
        }
    }

    void print() {
        print(root);
    }

    void print(std::shared_ptr<Node> node) {
        if (!node) return;
        print(node->left);
        std::cout << node->data;
        print(node->right);
    }

    // Conversion operator for string literals
    Rope(const char* str) : root(std::make_shared<Node>(str)) {}
};

int main() {
    try {
        Rope rope1;
        rope1.concat(Rope("Hello, "));
        rope1.concat(Rope("world!"));

        const char* str = " This is a test.";
        Rope rope2(str);

        rope1.concat(rope2);
        rope1.print();  // Should print "Hello, world! This is a test."

        char charAtIndex = rope1.index(7);  // Should return 'w'
        std::cout << "\nCharacter at index 7: " << charAtIndex << std::endl;

        auto splitRopes = rope1.split(12);
        std::cout << "\nSplit result:" << std::endl;
        splitRopes.first.print();  // Should print "Hello, world!"
        splitRopes.second.print(); // Should print " This is a test."
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
