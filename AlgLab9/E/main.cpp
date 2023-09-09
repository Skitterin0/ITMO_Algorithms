#include <fstream>
#include <vector>

std::vector<int> sort;

void DFS (std::vector<int>* graph, int* visit, int pos) {
    switch (visit[pos]) {
        case 0:
            visit[pos] = 1;
            for (int i = 0; i < graph[pos].size(); i++) {
                DFS(graph, visit, graph[pos][i]);
            }

            visit[pos] = 2;
            sort.push_back(pos);
            break;
        default:
            break;
    }
}

int main() {
    std::ifstream fin("hamiltonian.in");
    std::ofstream fout("hamiltonian.out");
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

    bool isHamilton = true;
    for (int i = sort.size()-1; i > 0; --i) {
        bool edge = false;
        for (int j : graph[sort[i]]) {
            if (sort[i-1] == j) {
                edge = true;
                break;
            }
        }
        isHamilton = edge;
        if (!isHamilton) {
            break;
        }
    }

    switch (isHamilton) {
        case 0:
            fout << "NO";
            break;
        case 1:
            fout << "YES";
            break;
    }

    fin.close();
    fout.close();
    return 0;
}
