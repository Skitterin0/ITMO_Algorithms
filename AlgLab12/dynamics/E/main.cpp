#include <iostream>
#include <vector>
#include <fstream>

using std::cin, std::cout;

void dfs(int v, std::vector<std::vector<int>>& graph, std::vector<std::vector<int>>& quantity) {
    quantity[v][0] = 0;
    quantity[v][1] = 1;

    for (int i : graph[v]) {
        dfs(i, graph, quantity);
        quantity[v][1] += quantity[i][0];
        quantity[v][0] += std::max(quantity[i][0], quantity[i][1]);
    }
}

int main() {
//    std::ifstream cin("in.txt");
//    std::ofstream cout("out.txt");

    int vNum;
    cin >> vNum;

    std::vector<std::vector<int>> graph;
    graph.resize(vNum);

    int root;

    for (int i = 0; i < vNum; ++i) {
        int v;
        cin >> v;

        switch (v) {
            case 0:
                root = i;
                break;
            default:
                graph[v-1].push_back(i);
                break;
        }
    }

    std::vector<std::vector<int>> quantity;
    quantity.assign(vNum, std::vector<int>(2));

    dfs(root, graph, quantity);

    cout << std::max(quantity[root][0], quantity[root][1]);

    return 0;
}
