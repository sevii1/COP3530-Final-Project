#pragma once
#include <string>

using namespace std;

class RBT {
public:

    struct TreeNode {
        int ID;

        string title_type;
        string title;
        string original_title;
        int start_year;
        int run_time;
        string genres;
        float average_rating;

        

        int color; //1 = red, 0 = black

        TreeNode* parent;

        TreeNode* left;
        TreeNode* right;

        TreeNode(int ID, string title_type, string title, string original_title, int start_year, int run_time, string genres, float average_rating, TreeNode* parent) {

            this-> ID = ID;
            this->title_type = title_type;
            this->title = title;
            this->original_title = original_title;
            this->start_year = start_year;
            this->run_time = run_time;
            this->genres = genres;
            this->average_rating = average_rating;

            this->parent = parent;

            left = nullptr;
            right = nullptr;

            color = 1; //1 = red, 0 = black
        }
    };

    RBT();

    void insert(string name, string id);
    TreeNode* insertHELPER(TreeNode* node, string nombre, int key, TreeNode* parent, int dir);
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