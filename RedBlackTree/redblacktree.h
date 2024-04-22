#pragma once
#include <string>
#include "C:\Users\1upjl\OneDrive\Documents\DSA Project 3\untitled\movie.h"

using namespace std;

class RBT {
public:

    struct TreeNode {
        int ID;
        int height;

        Movie movie;

        

        int color; //1 = red, 0 = black

        TreeNode* parent;

        TreeNode* left;
        TreeNode* right;


        TreeNode(Movie movie, int ID, TreeNode* parent) {

            this->movie = movie;
            ID = ID;
            this->parent = parent;

            left = nullptr;
            right = nullptr;

            color = 1; //1 = red, 0 = black
        }
    };

    RBT();

    void insert(Movie movie, string id);
    TreeNode* insertHELPER(TreeNode* node, Movie mov, int key, TreeNode* parent, int dir);
    TreeNode* rbtbalancing(TreeNode* node);

    TreeNode* rotateLeft(TreeNode* node);
    TreeNode* rotateRight(TreeNode* node);

    TreeNode* RBTreeGetGrandparent(TreeNode* node);
    TreeNode* RBTreeGetUnc(TreeNode* node);

    TreeNode* searchID(TreeNode* root, int key);

    void searchNAME(TreeNode* root, string title);
    bool SearchPreOrder(TreeNode* root, string title);

    void printInOrder();
    void inOrder(TreeNode* head, bool& x);

    TreeNode* getRoot() const;

private:

    TreeNode* root;

};
