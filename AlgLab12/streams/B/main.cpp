#include <fstream>
#include <vector>

using std::vector;

bool kuhn (int pos, vector<bool>& used, const vector<vector<int>>& graph, vector<int>& matching) {
    if (used[pos]) {
        return false;
    }
    used[pos] = true;

    for (int i = 0; i < graph[pos].size(); ++i) {
        int eEnd = graph[pos][i];
        if (matching[eEnd] == -1 || kuhn(matching[eEnd], used, graph, matching)) {
            matching[eEnd] = pos;
            return true;
        }
    }

    return false;
}

int main() {
    std::ifstream fin("matching.in");
    std::ofstream fout("matching.out");

    int vNumFirst, vNumSec, edgeNum;

    fin >> vNumFirst >> vNumSec >> edgeNum;

    vector<vector<int>> graph;

    graph.resize(vNumFirst);

    for (int i = 0; i < edgeNum; ++i) {
        int eStart, eEnd;

        fin >> eStart >> eEnd;

        graph[eStart-1].push_back(eEnd-1);
    }

    vector<int> matching;
    vector<bool> used;
    vector<bool> visited (vNumFirst);
    matching.resize(vNumSec, -1);

    for (int i = 0; i < vNumFirst; ++i) {
        for (int j : graph[i]) {
            if (matching[j] == -1) {
                matching[j] = i;
                visited[i] = true;
                break;
            }
        }
    }

    for (int i = 0; i < vNumFirst; ++i) {
        if (visited[i]) {
            continue;
        }
        used.assign(vNumFirst, false);
        kuhn(i, used, graph, matching);
    }

    int count = 0;
    for (int i : matching) {
        if (i != -1) {
            ++count;
        }
    }

    fout << count;

    fin.close();
    fout.close();
    return 0;
}
