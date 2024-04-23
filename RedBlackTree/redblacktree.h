#pragma once
#include <string>
#include "C:\Users\1upjl\OneDrive\Documents\DSA Project 3\untitled\movie.h"

using namespace std;

class RBT {
public:

    struct TreeNode {
        int ID;
        int height;

        Movie MOVIE;

        int color; //1 = red, 0 = black

        TreeNode* parent;
        TreeNode* grandparent;
        TreeNode* uncle;

        TreeNode* left;
        TreeNode* right;

        TreeNode(Movie movie, int gatorid, TreeNode* parent) {

            MOVIE  = movie;
            ID = gatorid;

            left = nullptr;
            right = nullptr;

            this->parent = parent;

            color = 1; //1 = red, 0 = black
        }
    };
    RBT();

    void insert(Movie movie, string id);
    TreeNode* insertHELPER(TreeNode* node, Movie mov, int key, TreeNode* parent, int dir);
    TreeNode* rbtbalancing(TreeNode* node);

    TreeNode* rotateLeft(TreeNode* node);
    TreeNode* rotateRight(TreeNode* node);

    bool validMovie(TreeNode* node, int dec, int minRuntime, int maxRuntime, string genre, double minRating, double maxRating);

    vector<Movie> traverseInOrder(int dec, int minRuntime, int maxRuntime, string genre, double minRating, double maxRating);
    void inOrder(TreeNode* head, int dec, int minRuntime, int maxRuntime, string genre, double minRating, double maxRating, vector<Movie> &movList);

    TreeNode* getRoot() const;

    TreeNode* RBTreeGetGrandparent(TreeNode* node);

    TreeNode* RBTreeGetUnc(TreeNode* node);



private:
    TreeNode* root;

};
