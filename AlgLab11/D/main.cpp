#include <fstream>
#include <vector>

int main() {
    std::ifstream fin("path.in");
    std::ofstream fout("path.out");

    int vertex, edgeNum, start;
    fin >> vertex >> edgeNum >> start;

    long long inf = 322322322322322322;
    std::vector<long long> graph[vertex];

    for (int i = 0; i < vertex; ++i) {
        graph[i].assign(vertex, inf);
        graph[i][i] = 0;
    }

    for (int i = 0; i < edgeNum; ++i) {
        int eStart, eEnd, weight;
        fin >> eStart >> eEnd >> weight;
        graph[eEnd-1][eStart-1] = weight;
    }

    std::vector<long long> distances[vertex-1];
    for (int i = 0; i < vertex-1; ++i) {
        distances[i].assign(vertex, inf);
        distances[i][start-1] = 0;
    }

    for (int k = 0; k < vertex-1; ++k) {
        for (int v = 0; v < vertex; ++v) {
            for (int u = 0; u < vertex; ++u) {
                distances[k+1][v] = std::min(distances[k+1][v], distances[k][v] + graph[v][u]);
            }
        }
    }

    fin.close();
    fout.close();
    return 0;
}