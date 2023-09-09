#include <fstream>
#include <vector>
#include <stack>

std::stack<int> sort;

//void DFS (std::vector<int>* graph, bool* visit, std::vector<int> path, int pos) {
//    if (!visit[pos]) {
//        visit[pos] = true;
//        for (int i = 0; i < graph[pos].size(); ++i) {
//            if (!visit[graph[pos][i]] && cycle) {
//                DFS(graph, visit, path, graph[pos][i]);
//            }
//            else {
//                for (int j = 0; j < path.size(); ++j) {
//                    if (graph[pos][i] == path[j]) {
//                        cycle = false;
//                        return;
//                    }
//                }
//            }
//        }
//
//        sort.push(pos + 1);
//        path.push_back(pos);
//        return;
//    }
//    else {
//        return;
//    }
//}

int main() {
    std::ifstream fin("topsort.in");
    std::ofstream fout("topsort.out");
    int n, m, eStart, eEnd;
    fin >> n >> m;

    std::vector<int> graph[n];
    bool visits[n];
    for (int i = 0; i < n; ++i) {
        visits[i] = false;
    }

    for (int i = 0; i < m; ++i) {
        fin >> eStart >> eEnd;
        graph[eStart-1].push_back(eEnd-1);
    }

    bool cycle = true;
    std::stack<int> path;
    for (int i = 0; i < n; ++i) {
        std::vector<int> currPath;
        path.push(i);
        while (!path.empty()) {
            int pos = path.top();
            if (!visits[pos]) {
                visits[pos] = true;
                for (int j = 0; j < graph[pos].size(); ++j) {
                    if (!visits[graph[pos][j]] && cycle) {
                        path.push(graph[pos][j]);
                    } else {
                        for (int k = 0; k < currPath.size(); ++k) {
                            if (graph[i][j] == currPath[k]) {
                                cycle = false;
                                break;
                            }
                        }
                    }
                }
                path.pop();
                sort.push(i + 1);
                currPath.push_back(i);
            } else {
                path.pop();
                continue;
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        fout << sort.top() << ' ';
        sort.pop();
    }

    fin.close();
    fout.close();
    return 0;
}
