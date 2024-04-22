#include <iostream>
#include "redblacktree.h"

int main() {
    RBT tree;

    // Insert some nodes into the tree
    tree.insert("13", "13");
    //13, 8, 7, 1, 123, 4, 9, 19
    std::cout << "In-order traversal of the tree: ";
    tree.printInOrder();
    std::cout << std::endl;

    tree.insert("8", "8");

    std::cout << "In-order traversal of the tree: ";
    tree.printInOrder();
    std::cout << std::endl;

    tree.insert("7", "7");

    std::cout << "In-order traversal of the tree: ";
    tree.printInOrder();
    std::cout << std::endl;

    tree.insert("1", "1");

    std::cout << "In-order traversal of the tree: ";
    tree.printInOrder();
    std::cout << std::endl;

    tree.insert("123", "123");

    std::cout << "In-order traversal of the tree: ";
    tree.printInOrder();
    std::cout << std::endl;

    tree.insert("4", "4");

    std::cout << "In-order traversal of the tree: ";
    tree.printInOrder();
    std::cout << std::endl;

    tree.insert("300", "300");

    std::cout << "In-order traversal of the tree: ";
    tree.printInOrder();
    std::cout << std::endl;




    // Print the tree in order
    std::cout << "In-order traversal of the tree: ";
    tree.printInOrder();
    std::cout << std::endl;



    // Search for a node by ID
    int idToSearch = 789;
    RBT::TreeNode* foundNode = tree.searchID(tree.getRoot(), idToSearch);
    if (foundNode != nullptr) {
        std::cout << "Found node with ID " << idToSearch << ": " << foundNode->NAME << std::endl;
    }
    else {
        std::cout << "Node with ID " << idToSearch << " not found." << std::endl;
    }

    // Search for a node by name
    std::string nameToSearch = "Alice";
    std::cout << "Searching for node with name \"" << nameToSearch << "\": ";
    tree.searchNAME(tree.getRoot(), nameToSearch);

    return 0;
}
