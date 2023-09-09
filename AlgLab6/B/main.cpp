#include <fstream>

struct BSTree {
    int key;
    int left;
    int right;

};

bool IsBinaryTree(BSTree tree[], int pos, int min, int max) {

    bool isTree = true;
    if (tree[pos].key <= min || tree[pos].key >= max) {
        return false;
    }

    if (tree[pos].left > 0 && isTree) {
        isTree = IsBinaryTree(tree, tree[pos].left - 1, min, tree[pos].key);
    }
    if (tree[pos].right > 0 && isTree) {
        isTree = IsBinaryTree(tree, tree[pos].right - 1, tree[pos].key, max);
    }

    return isTree;

}

int main() {

    std::ifstream fin("check.in");
    std::ofstream fout("check.out");
    int n;
    fin >> n;
    if (n == 0) {
        fout << "YES\n";
        return 0;
    }

    BSTree tree[n];

    for (int i = 0; i < n; i++) {
        fin >> tree[i].key >> tree[i].left >> tree[i].right;
    }

    bool isTree = IsBinaryTree(tree, 0, -1000000001, 1000000001);
    if (isTree) {
        fout << "YES\n";
    } else {
        fout << "NO\n";
    }

    fin.close();
    fout.close();
    return 0;

}