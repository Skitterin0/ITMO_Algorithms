#include <fstream>
#include <vector>
#include <queue>

int main() {
    std::ifstream fin("spantree3.in");
    std::ofstream fout("spantree3.out");

    int n, m, eStart, eEnd, weight;
    fin >> n >> m;

    std::vector<std::pair<int, int>> graph[n];
    for (int i = 0; i < m; ++i) {
        fin >> eStart >> eEnd >> weight;
        graph[eStart-1].push_back(std::pair<int, int>(weight, eEnd-1));
        graph[eEnd-1].push_back(std::pair<int, int>(weight, eStart-1));
    }

    std::vector<bool> visits;
    visits.assign(n, false);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> vertexQueue;
    vertexQueue.push(std::make_pair(0, 0));

    long long treeWeight = 0;
    while(!vertexQueue.empty()) {
        std::pair<int, int> curr = vertexQueue.top();
        vertexQueue.pop();
        if (visits[curr.second]) {
            continue;
        }
        else {
            visits[curr.second] = true;
            treeWeight += curr.first;
            for (auto j : graph[curr.second]) {
                if (!visits[j.second]) {
                    vertexQueue.push(j);
                }
            }
        }
    }

    fout << treeWeight;
    fin.close();
    fout.close();
    return 0;
}