#include <fstream>
#include <vector>
#include <queue>

int cycleStart;

bool DFS (std::vector<int>* graph, int* visit, int pos) {
    bool isCycle;
    switch (visit[pos]) {
        case 0:
            visit[pos] = 1;
            isCycle = false;
            for (int i = 0; i < graph[pos].size(); ++i) {
                isCycle = DFS(graph, visit, graph[pos][i]);
                if (isCycle) {
                    return isCycle;
                }
            }

            visit[pos] = 2;
            break;
        case 1:
            isCycle = true;
            cycleStart = pos;
            break;
        case 2:
            isCycle = false;
            break;
    }
    return isCycle;
}

void Cycle(std::vector<int>* graph, int* visit, int pos, std::queue<int>& path) {
    switch (visit[pos]) {
        case 1:
            path.push(pos+1);
            visit[pos] = 2;
            for (int i = 0; i < graph[pos].size(); ++i) {
                Cycle(graph, visit, graph[pos][i], path);
            }
            break;
        default:
            break;
    }
    return;
}

int main() {
    std::ifstream fin("cycle.in");
    std::ofstream fout("cycle.out");
    int n, m, eStart, eEnd;
    fin >> n >> m;

    std::vector<int> graph[n];
    int visits[n];
    for (int i = 0; i < n; ++i) {
        visits[i] = 0;
    }

    for (int i = 0; i < m; ++i) {
        fin >> eStart >> eEnd;
        if (eStart == eEnd) {
            fout << "YES\n" << eStart << ' ' << eStart;
            return 0;
        }
        else {
            graph[eStart - 1].push_back(eEnd - 1);
        }
    }

    for (int i = 0; i < n; ++i) {
        if (DFS(graph, visits, i)) {
            fout << "YES\n";
            std::queue<int> pathCycle;
            Cycle(graph, visits, cycleStart, pathCycle);
            int size = pathCycle.size();
            for (int i = 0; i < size; ++i) {
                fout << pathCycle.front() << ' ';
                pathCycle.pop();
            }
            return 0;
        }
    }

    fout << "NO";

    fin.close();
    fout.close();
    return 0;
}
