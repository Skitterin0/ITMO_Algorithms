#include <fstream>
#include <vector>

struct SRoot {
    int component;
    bool isVisited;
    std::vector<int> edges;
};

void ComponentCounter (std::vector<SRoot>& tmpGraph, int compNumber, int pos) {
    if (tmpGraph[pos].isVisited == false) {
        tmpGraph[pos].isVisited = true;
        tmpGraph[pos].component = compNumber;
        int edgeCount = tmpGraph[pos].edges.size();
        int currEdge = 0;
        while (edgeCount-- > 0) {
            ComponentCounter(tmpGraph, compNumber, tmpGraph[pos].edges[currEdge++]);
        }
        return;
    }
    else {
        return;
    }
}

int main() {
    std::ifstream fin ("components.in");
    std::ofstream fout ("components.out");

    int n, m, edgeStart, edgeEnd;
    fin >> n >> m;

    std::vector<SRoot> graph;

    for (int i = 0; i < n; i++) {
        SRoot tmp = {0, false};
        graph.push_back(tmp);
    }

    for (int i = 0; i < m; i++) {
        fin >> edgeStart >> edgeEnd;
        graph[edgeStart-1].edges.push_back(edgeEnd-1);
        graph[edgeEnd-1].edges.push_back(edgeStart-1);
    }

    int component = 0;
    for (int i = 0; i < n; i++) {
        if (graph[i].isVisited == false) {
            component++;
        }
        ComponentCounter(graph, component, i);
    }
    fout << component << '\n';
    for (int i = 0; i < n; i++) {
        fout << graph[i].component << ' ';
    }

    fin.close();
    fout.close();
    return 0;
}
