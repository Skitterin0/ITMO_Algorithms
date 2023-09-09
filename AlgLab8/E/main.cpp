#include <fstream>
#include <queue>
#include <vector>

struct Data {
    bool isVisited;
    int distance;
};

int main() {
    std::ifstream fin ("pathbge1.in");
    std::ofstream fout ("pathbge1.out");

    int n, m, edgeS, edgeE;
    fin >> n >> m;

    Data graphEdges[n];
    for (int i = 0; i < n; i++) {
        graphEdges[i] = {false, 0};
    }

    std::vector<int> graph[n];
    for (int i = 0; i < m; i++) {
        fin >> edgeS >> edgeE;
        graph[edgeS-1].push_back(edgeE-1);
        graph[edgeE-1].push_back(edgeS-1);
    }

    std::queue<int> path;
    path.push(0);
    graphEdges[0].distance = 0;
    graphEdges[0].isVisited = true;

    while (!path.empty()) {
        int currRoot = path.front();
        path.pop();

        for (int i = 0; i < graph[currRoot].size(); i++) {
            if (graphEdges[graph[currRoot][i]].isVisited == false) {
                graphEdges[graph[currRoot][i]].isVisited = true;
                graphEdges[graph[currRoot][i]].distance = graphEdges[currRoot].distance + 1;
                path.push(graph[currRoot][i]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        fout << graphEdges[i].distance << ' ';
    }

    fin.close();
    fout.close();
    return 0;
}