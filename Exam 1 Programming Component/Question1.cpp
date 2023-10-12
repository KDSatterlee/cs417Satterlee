#include <iostream>
#include <vector>
#include <list>

// Class to represent a node in the graph
class Node {
public:
    int data;
    Node() : data(0) {}
    Node(int val) : data(val) {}
};

class AdjListGraph {
private:
    int numNodes;
    std::vector<Node> nodeVector;
    std::vector<std::list<int>> edgeVector;

public:
    AdjListGraph(int numNodes) : numNodes(numNodes), nodeVector(numNodes), edgeVector(numNodes) {}

    // Add an edge from x to y if none exists
    void addEdge(int x, int y) {
        if (x >= 0 && x < numNodes && y >= 0 && y < numNodes) {
            edgeVector[x].push_back(y);
            edgeVector[y].push_back(x); // Add the reverse edge
        }
    }

    // Delete an edge from x to y if one exists
    void deleteEdge(int x, int y) {
        if (x >= 0 && x < numNodes) {
            edgeVector[x].remove(y);
        }
        if (y >= 0 && y < numNodes) {
            edgeVector[y].remove(x); // Remove the reverse edge if it exists
        }
    }

    // Append a new Node to the node list
    void addNode(Node x) {
        nodeVector.push_back(x);
        numNodes++;
        // Add an empty edge list for the new node
        edgeVector.push_back(std::list<int>());
    }

    // Delete a node from the node list, removing any edges that come into this node
    void deleteNode(int x) {
        if (x >= 0 && x < numNodes) {
            nodeVector.erase(nodeVector.begin() + x);
            edgeVector.erase(edgeVector.begin() + x);
            for (auto& edgeList : edgeVector) {
                edgeList.remove(x);
            }
            numNodes--;
        }
    }

    // Print the adjacency list representation of the graph
    void printGraph() {
        for (int i = 0; i < numNodes; ++i) {
            std::cout << "Node " << i << " -> ";
            for (int neighbor : edgeVector[i]) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    AdjListGraph graph(5);

    Node node0(0);
    Node node1(1);
    Node node2(2);
    Node node3(3);

    graph.addNode(node0);
    graph.addNode(node1);
    graph.addNode(node2);
    graph.addNode(node3);

    graph.addEdge(0, 1);
    graph.addEdge(1, 2);
    graph.addEdge(2, 0);
    graph.addEdge(3, 0);

    std::cout << "Original Graph:" << std::endl;
    graph.printGraph();

    graph.deleteNode(2);
    graph.deleteEdge(0, 1);

    std::cout << "\nGraph after deleting Node 2 and Edge (0, 1):" << std::endl;
    graph.printGraph();

    return 0;
}
