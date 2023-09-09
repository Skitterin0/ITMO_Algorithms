#include <fstream>
#include <vector>
#include <queue>

using std::vector;

bool bfs(int source, int sink, int vNum, vector<vector<int>>& graph, vector<int>& parent) {
    vector<bool> visited;
    visited.assign(vNum, false);

    std::queue<int> vertexQueue;
    vertexQueue.push(source);
    visited[source] = true;
    parent[source] = -1;

    while (!vertexQueue.empty()) {
        int curr = vertexQueue.front();
        vertexQueue.pop();

        for (int eEnd = 0; eEnd < vNum; ++eEnd) {
            if (!visited[eEnd] && graph[curr][eEnd] > 0) {
                if (eEnd == sink) {
                    parent[eEnd] = curr;
                    return true;
                }

                vertexQueue.push(eEnd);
                parent[eEnd] = curr;
                visited[eEnd] = true;
            }
        }
    }

    return false;
}

int fordFulkerson(int source, int sink, int vNum, vector<vector<int>>& graph) {
    int eStart, eEnd;

    vector<int> parent (vNum);
    int maxFlow = 0;

    while(bfs(source, sink, vNum, graph, parent)) {
        int currFlow = INT_MAX;

        for (eEnd = sink; eEnd != source ; eEnd = parent[eEnd]) {
            eStart = parent[eEnd];
            currFlow = std::min(currFlow, graph[eStart][eEnd]);
        }

        for (eEnd = sink; eEnd != source ; eEnd = parent[eEnd]) {
            eStart = parent[eEnd];
            graph[eStart][eEnd] -= currFlow;
            graph[eEnd][eStart] += currFlow;
        }

        maxFlow += currFlow;
    }

    return maxFlow;
}

int main() {
    std::ifstream fin("maxflow.in");
    std::ofstream fout("maxflow.out");

    int vNum, eNum;
    fin >> vNum >> eNum;

    vector<vector<int>> graph;
    graph.assign(vNum, vector<int>(vNum, 0));

    for (int i = 0; i < eNum; ++i) {
        int eStart, eEnd, flow;
        fin >> eStart >> eEnd >> flow;
        graph[eStart-1][eEnd-1] = flow;
    }

    int maxFlow = fordFulkerson(0, vNum-1, vNum, graph);

    fout << maxFlow;

    fin.close();
    fout.close();
    return 0;
}
