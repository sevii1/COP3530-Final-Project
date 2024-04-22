#include <string>
#include <iostream>
#include "redblacktree.h"
using namespace std;

RBT::RBT() {
    root = nullptr;
}

void RBT::insert(Movie movie, string id) {

    if (root == nullptr) {
        root = new TreeNode(movie, stoi(id), nullptr);
        root->color = 0;
    }
    else {

        insertHELPER(root, movie, stoi(id), nullptr, 0);


    }

}
RBT::TreeNode* RBT::insertHELPER(TreeNode* node, Movie mov, int key, TreeNode* parent, int dir) { //first node is root


    if (node == nullptr) {
        //cout << "new node blue blood" << endl;
        TreeNode* NewNode = new TreeNode(mov, key, parent);
        NewNode->parent = parent;
        if (dir == 1) {
            parent->left = NewNode;
        }
        else if (dir == 2) {
            parent->right = NewNode;
        }
        rbtbalancing(NewNode);
        return NewNode;
    }

    if (key < node->ID) {

        insertHELPER(node->left, mov, key, node, 1);


    }
    else {

        insertHELPER(node->right, mov, key, node, 2);

    }

    return node;
}

RBT::TreeNode* RBT::rbtbalancing(TreeNode* node) { //first node is root

    if (node->parent == nullptr) {

        node->color = 0;
        return node;
    }

    if (node->parent->color == 0) {

        return node;
    }
    TreeNode* parent = node->parent;
    TreeNode* grandparent = RBTreeGetGrandparent(node);
    TreeNode* uncle = RBTreeGetUnc(node);

    if (uncle != nullptr && uncle->color == 1) { // if uncle is red, flip colors


        parent->color = 0;
        uncle->color = 0;
        grandparent->color = 1;
        rbtbalancing(grandparent);
        return node;
    }
    if (node == parent->right && parent == grandparent->left) {


        rotateLeft(parent);
        node = parent;
        parent = node->parent;
    }
    else if (node == parent->left && parent == grandparent->right) {


        rotateRight(parent);
        node = parent;
        parent = node->parent;
    }
    parent->color = 0;
    grandparent->color = 1;
    //cout <<grandparent->NAME << endl;
    if (node == parent->left) {


        TreeNode* temp = rotateRight(grandparent);

        return temp;
    }
    else {


        return rotateLeft(grandparent);
    }

}

RBT::TreeNode* RBT::RBTreeGetGrandparent(TreeNode* node) {
    if (node != nullptr && node->parent != nullptr) {
        return node->parent->parent;
    }
    return nullptr;
}
RBT::TreeNode* RBT::RBTreeGetUnc(TreeNode* node) {
    TreeNode* grandparent = RBTreeGetGrandparent(node);
    if (grandparent != nullptr) {
        if (node->parent == grandparent->left) {
            return grandparent->right;
        }
        else {
            return grandparent->left;
        }
    }
    return nullptr;
}





RBT::TreeNode* RBT::rotateLeft(TreeNode* node) {
    TreeNode* newParent = node->right;
    TreeNode* grandchild = newParent->left;
    newParent->left = node;
    node->right = grandchild;

    if (grandchild != nullptr) {
        grandchild->parent = node;
    }
    newParent->parent = node->parent;

    if (node->parent == nullptr) {
        root = newParent;
        root->color = 0;
    }
    else if (node == node->parent->left) {
        node->parent->left = newParent;
        newParent->color = node->parent->color;
    }
    else {
        node->parent->right = newParent;
        newParent->color = node->parent->color;
    }
    node->parent = newParent;

    node->color = 1;

    return newParent;
}



RBT::TreeNode* RBT::rotateRight(TreeNode* node) {
    TreeNode* newParent = node->left;
    TreeNode* grandchild = newParent->right;
    newParent->right = node;
    node->left = grandchild;


    if (grandchild != nullptr) {
        grandchild->parent = node;
    }
    newParent->parent = node->parent;

    if (node->parent == nullptr) {
        root = newParent;
        root->color = 0;
    }
    else if (node == node->parent->right) {
        node->parent->right = newParent;
        newParent->color = node->parent->color;
    }
    else {
        node->parent->left = newParent;
        newParent->color = node->parent->color;
    }
    node->parent = newParent;

    node->color = 1;

    return newParent;
}






RBT::TreeNode* RBT::searchID(TreeNode* root, int key) {
    if (root == nullptr) {
        return nullptr;
    }
    if (root->ID == key) {

        return root;
    }
    if (key < root->ID) {
        return searchID(root->left, key);
    }
    else {
        return searchID(root->right, key);
    }
    return root;
}

void RBT::searchNAME(TreeNode* root, string title) {
    if (!SearchPreOrder(root, title)) {
        cout << "unsuccessful" << endl;
    }
}
bool RBT::SearchPreOrder(TreeNode* node, string title) {
    if (node == nullptr) {
        return false;
    }
    if (node->NAME == title) {
        cout << node->ID << endl;
        return true | SearchPreOrder(node->left, title) | SearchPreOrder(node->right, title);
    }
    return SearchPreOrder(node->left, title) | SearchPreOrder(node->right, title);
}


void RBT::printInOrder() {
    bool first = true;

    inOrder(root, first);
    cout << endl;
}
void RBT::inOrder(TreeNode* head, bool& isFirst) {
    if (head == nullptr) {
        return;
    }

    inOrder(head->left, isFirst);

    if (isFirst) {

        cout << head->NAME << ": ";
        if (head->color == 0) {
            cout << "Black";
        }
        else if (head->color == 1) {
            cout << "Red";
        }
        isFirst = false;
    }
    else {
        cout << ",      " << head->NAME << ": ";
        if (head->color == 0) {
            cout << "Black";
        }
        else if (head->color == 1) {
            cout << "Red";
        }
    }

    inOrder(head->right, isFirst);
}

RBT::TreeNode* RBT::getRoot() const {
    return root;
}
