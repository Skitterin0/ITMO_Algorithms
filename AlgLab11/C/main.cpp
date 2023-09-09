#include <fstream>
#include <vector>
#include <queue>

int main() {
    std::ifstream fin("pathbgep.in");
    std::ofstream fout("pathbgep.out");

    int vertex, edgeNum;
    fin >> vertex >> edgeNum;

    std::vector<std::pair<int, int>> graph[vertex];

    for (int i = 0; i < edgeNum; ++i) {
        int eStart, eEnd, weight;
        fin >> eStart >> eEnd >> weight;
        graph[eStart-1].emplace_back(weight, eEnd-1);
        graph[eEnd-1].emplace_back(weight, eStart-1);
    }

    int inf = 777777777;
    std::vector<int> distance;
    distance.assign(vertex, inf);
    distance[0] = 0;

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> vertexQueue;
    vertexQueue.push(std::make_pair(0,0));

    while(!vertexQueue.empty()) {
        std::pair<int, int> curr = vertexQueue.top();
        vertexQueue.pop();

        if (curr.first > distance[curr.second]) {
            continue;
        }

        for (auto i : graph[curr.second]) {
            if (distance[i.second] > distance[curr.second] + i.first) {
                distance[i.second] = distance[curr.second] + i.first;
                vertexQueue.push(std::make_pair(distance[i.second], i.second));
            }
        }
    }

    for (int i : distance) {
        fout << i << ' ';
    }

    fin.close();
    fout.close();
    return 0;
}