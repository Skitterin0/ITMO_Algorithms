#include <fstream>
#include <vector>

int main() {
    std::ifstream fin("pathmgep.in");
    std::ofstream fout("pathmgep.out");

    int n, s, f;
    fin >> n >> s >> f;
    --s;
    --f;
    std::vector<std::pair<int, int>> graph[n];

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int weight;
            fin >> weight;
            if (i == j) {
                continue;
            }
            switch (weight) {
                case -1:
                    break;
                default:
                    graph[i].push_back(std::make_pair(weight, j));
                    break;
            }
        }
    }

    const long long inf = 7777777777777777777;
    std::vector<long long> distance;
    distance.assign(n, inf);
    std::vector<bool> visits;
    visits.assign(n, false);


    distance[s] = 0;

    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j) {
            if (!visits[j] && (v == -1 || distance[j] < distance[v])) {
                v = j;
            }
        }
        if (distance[v] == inf) {
            break;
        }
        visits[v] = true;
        for (auto j : graph[v]) {
            if (distance[v] + j.first < distance[j.second]) {
                distance[j.second] = distance[v] + j.first;
            }
        }
    }

    switch (distance[f]) {
        case inf:
            fout << -1;
            break;
        default:
            fout << distance[f];
    }

    fin.close();
    fout.close();
    return 0;
}