#include <fstream>
#include <vector>

void DFS (std::vector<std::vector<int>>& graph, std::vector<bool>& visit, int pos, std::vector<bool>& win) {
    switch (visit[pos]) {
        case false:
            for (int i : graph[pos]) {
                DFS(graph, visit, i, win);
                if (win[i] == false) {
                    win[pos] = true;
                }
            }
            visit[pos] = true;
            break;
        default:
            break;
    }
}

int main() {
    std::ifstream fin("game.in");
    std::ofstream fout("game.out");


    int n, m, s;
    fin >> n >> m >> s;

    std::vector<bool> visits (n, false);
    std::vector<bool> win (n, false);

    std::vector<std::vector<int>> graph;
    graph.resize(n);
    for (int i = 0; i < m; ++i) {
        int eStart, eEnd;
        fin >> eStart >> eEnd;
        graph[eStart-1].push_back(eEnd-1);
    }

    DFS(graph, visits, s-1, win);

    if (win[s-1]) {
        fout << "First player wins";
    }
    else {
        fout << "Second player wins";
    }

    fin.close();
    fout.close();
    return 0;
}
