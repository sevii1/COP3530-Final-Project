#include <iostream>
#include "redblacktree.h"

using namespace std;

int main() {
    RBT tree;

 
    tree.insert("13", "13");
    tree.insert("8", "8");
    tree.insert("7", "7");
    tree.insert("1", "1");
    tree.insert("123", "123");
    tree.insert("4", "4");
    tree.insert("300", "300");

    tree.printInOrder();
   
    int id = 123;

    TreeNode* node = tree.searchID(tree.getRoot(), id);
    if (node != nullptr) {
        cout << "Node with ID " << id << ": " << node->NAME << endl;
    }else {
        cout << "Node with ID " << id << " not found." << endl;
    }

    string name = "Alice";
    cout << "Node with name- "<< name << ": ";
    tree.searchNAME(tree.getRoot(), nameToSearch);

    return 0;
}
