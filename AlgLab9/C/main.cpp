#include <fstream>
#include <vector>
#include <queue>

enum Orientation {
    LEFT,
    RIGHT,
    NONE
};

Orientation swapSide (Orientation side) {
    return side == RIGHT ? LEFT : RIGHT;
}

int main() {
    std::ifstream fin("bipartite.in");
    std::ofstream fout("bipartite.out");

    int n, m;
    fin >> n >> m;

    Orientation sides[n];
    for (int i = 0; i < n; ++i) {
        sides[i] = NONE;
    }

    std::queue<int> path;
    std::vector<std::vector<int>> graph;
    graph.resize(n);
    for (int i = 0; i < m; ++i) {
        int eStart, eEnd;
        fin >> eStart >> eEnd;

        graph[eStart-1].push_back(eEnd - 1);
        graph[eEnd-1].push_back(eStart - 1);
    }

    bool bipartite = true;
    for (int i = 0; i < n; ++i) {
        if (sides[i] == NONE) {
            sides[i] = LEFT;
            path.push(i);

            while (!path.empty() && bipartite) {
                int currRoot = path.front();
                path.pop();

                for (int i: graph[currRoot]) {
                    switch (sides[i]) {
                        case NONE:
                            path.push(i);
                            sides[i] = swapSide(sides[currRoot]);
                            break;
                        default:
                            if (sides[currRoot] == sides[i]) {
                                bipartite = false;
                            } else {
                                continue;
                            }
                            break;
                    }
                }
            }
        }
    }

    if (bipartite) {
        fout << "YES";
    }
    else {
        fout << "NO";
    }

    fin.close();
    fout.close();
    return 0;
}
