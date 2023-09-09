#include <fstream>
#include <vector>

void DFS1 (const std::vector<std::vector<int>>& graph, std::vector<bool>& visit, std::vector<int>& sort, int pos) {
    visit[pos] = true;
    for (int i : graph[pos]) {
        if (!visit[i]) {
            DFS1(graph, visit, sort, i);
        }
    }
    sort.push_back(pos);
}

void DFS2 (const std::vector<std::vector<int>>& graph, std::vector<bool>& visit, int pos, int component, std::vector<int>& result) {
    visit[pos] = true;
    result[pos] = component;
    for (int i : graph[pos]) {
        if (!visit[i]) {
            DFS2(graph, visit, i, component, result);
        }
    }
}

int main() {
    std::ifstream fin("cond.in");
    std::ofstream fout("cond.out");

    int n,m;
    fin >> n >> m;
    std::vector<bool> visits (n, false);

    std::vector<std::vector<int>> graph, graphT;
    graph.resize(n);
    graphT.resize(n);
    for (int i = 0; i < m; ++i) {
        int eStart, eEnd;
        fin >> eStart >> eEnd;
        graph[eStart-1].push_back(eEnd-1);
        graphT[eEnd-1].push_back(eStart-1);
    }

    std::vector<int> topSort;
    for (int i = 0; i < n; ++i) {
        if (!visits[i]) {
            DFS1(graph, visits, topSort, i);
        }
    }

    visits.assign(n, false);
    std::vector<int> components;
    components.resize(n);
    int component = 1;
    for (int i = n-1; i >= 0; --i) {
        int pos = topSort[i];
        if (!visits[pos]) {
            DFS2(graphT, visits, pos, component, components);
            ++component;
        }
    }

    fout << component-1 << '\n';
    for (int i : components) {
        fout << i << ' ';
    }

    fin.close();
    fout.close();
    return 0;
}
