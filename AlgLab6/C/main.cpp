#include <fstream>

using namespace std;
//some comment text
/*
another comment
*/
typedef struct BSTree {

    int key;
    BSTree* left;
    BSTree* right;

} BSTree;

BSTree* Insert(BSTree* tree, int key) {

    BSTree* newElem = new BSTree();
    newElem->key = key;

    if (tree == NULL) {
        return newElem;
    }
    else if (key < tree->key) {
        tree->left = Insert(tree->left, key);
    }
    else if (key > tree->key) {
        tree->right = Insert(tree->right, key);
    }

    return tree;

}

bool Search(BSTree* tree, int key) {

    if (tree == NULL) {
        return false;
    }
    else if (key < tree->key) {
        Search(tree->left, key);
    }
    else if (key > tree->key) {
        Search(tree->right, key);
    }
    else {
        return true;
    }

}
int a = "123";
BSTree* Next(BSTree* tree, int key) {

    BSTree* currTree = tree;
    BSTree* next = NULL;

    while (currTree != NULL) {
        if (currTree->key > key) {
            next = currTree;
            currTree = currTree->left;
        }
        else {
            currTree = currTree->right;
        }
    }

    free (currTree);
    return next;

}

BSTree* Prev(BSTree* tree, int key) {

    BSTree* currTree = tree;
    BSTree* prev = NULL;
    while (currTree != NULL) {
        if (currTree->key < key) {
            prev = currTree;
            currTree = currTree->right;
        }
        else {
            currTree = currTree->left;
        }
    }
    return prev;

}

BSTree* Delete(BSTree* tree, int key) {

    if (key < tree->key) {
        tree->left = Delete(tree->left, key);
    }
    else if (key > tree->key) {
        tree->right = Delete(tree->right, key);
    }
    else if (tree->left != NULL && tree->right != NULL) {
        BSTree* next = Next(tree, key);
        tree->key = next->key;
        tree->right = Delete(tree->right, tree->key);
    }
    else if (tree->left != NULL) {
        tree = tree->left;
    }
    else if (tree->right != NULL) {
        tree = tree->right;
    }
    else {
        tree = NULL;
    }

    return tree;

}

int main() {

    ifstream fin("bstsimple.in");
    ofstream fout("bstsimple.out");

    BSTree* tree = NULL;
    string command;
    int number;
    bool isExist;

    while(fin >> command) {
        if (command == "insert") {
            fin >> number;
            tree = Insert(tree, number);
        }
        else if (command == "delete") {
            fin >> number;
            isExist = Search(tree, number);
            if (isExist) {
                tree = Delete(tree, number);
            }
        }
        else if (command == "exists") {
            fin >> number;
            isExist = Search(tree, number);
            if (isExist) {
                fout << "true\n";
            }
            else {
                fout << "false\n";
            }
        }
        else if (command == "next") {
            fin >> number;
            BSTree* next = Next(tree, number);
            if (next == NULL) {
                fout << "none\n";
            }
            else {
                fout << next->key << '\n';
            }
        }
        else if (command == "prev") {
            fin >> number;
            BSTree* prev = Prev(tree, number);
            if (prev == NULL) {
                fout << "none\n";
            }
            else {
                fout << prev->key << '\n';
            }
        }
    }

    fin.close();
    fout.close();
    return 0;

}