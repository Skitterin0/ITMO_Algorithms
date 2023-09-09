#include <fstream>
#include <vector>

typedef std::pair<std::vector<int>, int> vertice;
typedef std::vector<vertice> graph;

void dfs(int v, graph& tree, std::vector<std::vector<int>>& quantity) {
    quantity[v][0] = 0;
    quantity[v][1] = tree[v].second;

    for (int i : tree[v].first) {
        dfs(i, tree, quantity);
        quantity[v][1] += quantity[i][0];
        quantity[v][0] += std::max(quantity[i][0], quantity[i][1]);
    }
}

int main() {
    std::ifstream fin("selectw.in");
    std::ofstream fout("selectw.out");

    int vNum;
    fin >> vNum;

    graph tree;
    tree.resize(vNum);

    int root;
    for (int i = 0; i < vNum; ++i) {
        int v, num;
        fin >> v >> num;
        switch (v) {
            case 0:
                root = i;
                tree[i].second = num;
                break;
            default:
                tree[v-1].first.push_back(i);
                tree[i].second = num;
                break;
        }
    }

    std::vector<std::vector<int>> quantity;
    quantity.assign(vNum, std::vector<int>(2));

    dfs(root, tree, quantity);
    fout << std::max(quantity[root][0], quantity[root][1]);

    fin.close();
    fout.close();
    return 0;
}
