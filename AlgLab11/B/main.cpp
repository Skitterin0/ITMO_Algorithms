#include <iostream>
#include <fstream>
#include <vector>

int main() {
    std::ifstream fin("pathsg.in");
    std::ofstream fout("pathsg.out");

    int vertex, edge;
    const int inf = 999999999;
    fin >> vertex >> edge;

    std::vector<std::vector<int>> graph;
    graph.assign(vertex, std::vector<int>(vertex, inf));

    for (int i = 0; i < edge; ++i) {
        int eStart, eEnd, weight;
        fin >> eStart >> eEnd >> weight;
        graph[eStart-1][eEnd-1] = weight;
    }

    for (int i = 0; i < vertex; ++i) {
        for (int u = 0; u < vertex; ++u) {
            for (int v = 0; v < vertex; ++v) {
                graph[u][v] = std::min(graph[u][v], graph[u][i] + graph[i][v]);
            }
        }
    }

    for (int i = 0; i < vertex; ++i) {
        for (int j = 0; j < vertex; ++j) {
            if (i == j) {
                fout << 0 << ' ';
            }
            else {
                fout << graph[i][j] << ' ';
            }
        }
        fout << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}