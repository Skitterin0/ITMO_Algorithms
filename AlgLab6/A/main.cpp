#include <fstream>

struct BSTree {
    int key;
    int left;
    int right;

};

int maxHeight;

void Height(BSTree tree[], int pos, int currHeight) {

    if (currHeight > maxHeight) {
        maxHeight = currHeight;
    }

    if (tree[pos].left - 1 > 0) {
        Height(tree, tree[pos].left - 1, currHeight + 1);
    }
    if (tree[pos].right - 1 > 0) {
        Height(tree, tree[pos].right - 1, currHeight + 1);
    }

}

int main() {

    std::ifstream fin("height.in");
    std::ofstream fout("height.out");
    int n;
    fin >> n;
    if (n == 0) {
        fout << 0 << '\n';
        return 0;
    }

    BSTree tree[n];
    maxHeight = 0;

    for (int i = 0; i < n; i++) {
        fin >> tree[i].key >> tree[i].left >> tree[i].right;
    }

    Height(tree, 0, 1);

    fout << maxHeight;

    fin.close();
    fout.close();
    return 0;

}