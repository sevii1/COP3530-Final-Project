#pragma once
#include <string>

using namespace std;

class RBT {
public:

    struct TreeNode {
        string NAME;
        int ID;
        int height;


        string title_type;
        string title;
        string original_title;
        int start_year;
        int run_time;
        string genres;
        float average_rating;

        int color; //1 = red, 0 = black

        TreeNode* parent;
        TreeNode* grandparent;
        TreeNode* uncle;

        TreeNode* left;
        TreeNode* right;

        TreeNode(string name, int gatorid, TreeNode* parent) {

            NAME = name;
            ID = gatorid;

            left = nullptr;
            right = nullptr;

            this->parent = parent;

            color = 1; //1 = red, 0 = black
        }
    };
    RBT();

    void insert(string name, string id);
    TreeNode* insertHELPER(TreeNode* node, string nombre, int key, TreeNode* parent, int dir);
    TreeNode* rbtbalancing(TreeNode* node);

    TreeNode* rotateLeft(TreeNode* node);
    TreeNode* rotateRight(TreeNode* node);



    TreeNode* searchID(TreeNode* root, int key);

    void searchNAME(TreeNode* root, string title);
    bool SearchPreOrder(TreeNode* root, string title);

    void printInOrder();
    void inOrder(TreeNode* head, bool& x);

    TreeNode* getRoot() const;

    TreeNode* RBTreeGetGrandparent(TreeNode* node);

    TreeNode* RBTreeGetUnc(TreeNode* node);



private:
    TreeNode* root;

};