#include <fstream>
#include <vector>
#include <stack>

std::stack<int> sort;

void DFS (std::vector<int>* graph, int* visit, int pos) {
    switch (visit[pos]) {
        case 0:
            visit[pos] = 1;
            for (int i = 0; i < graph[pos].size(); i++) {
                DFS(graph, visit, graph[pos][i]);
            }

            visit[pos] = 2;
            sort.push(pos + 1);
            break;
        default:
            break;
    }
}

int main() {
    std::ifstream fin("topsort.in");
    std::ofstream fout("topsort.out");
    int n, m, eStart, eEnd;
    fin >> n >> m;

    int visits[n];
    for (int i = 0; i < n; i++) {
        visits[i] = 0;
    }
    std::vector<int> graph[n];
    for (int i = 0; i < m; i++) {
        fin >> eStart >> eEnd;
        graph[eStart-1].push_back(eEnd-1);
    }

    for (int i = 0; i < n; i++) {
        DFS(graph, visits, i);
    }



    fin.close();
    fout.close();
    return 0;
}
