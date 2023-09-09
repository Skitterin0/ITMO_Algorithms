#include <fstream>
#include <cmath>
#include <vector>
#include <iomanip>

double distance(const std::vector<std::pair<int,int>>& points, int p1, int p2) {
    return sqrt(pow(points[p2].first - points[p1].first, 2) +
                pow(points[p2].second - points[p1].second, 2));
}


int main() {
    std::ifstream fin("spantree.in");
    std::ofstream fout("spantree.out");

    int n, x, y;
    fin >> n;

    std::vector<std::pair<int,int>> points;
    std::vector<std::vector<double>> graph;

    for (int i = 0; i < n; ++i) {
        fin >> x >> y;
        points.push_back(std::pair<int,int>(x,y));
    }

    graph.assign(n, std::vector<double>(n));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            graph[i][j] = distance(points, i, j);
        }
    }

    std::vector<bool> visits (n, false);
    std::vector<double> distance;
    distance.resize(n, 7777777777777777777);

    distance[0] = 0;
    for (int i = 0; i < n; ++i) {
        int pos = -1;
        for (int j = 0; j < n; ++j) {
            if (!visits[j] && (pos == -1 || distance[j] < distance[pos])) {
                pos = j;
            }
        }
        visits[pos] = true;
        for (int j = 0; j < n; ++j) {
            if (!visits[j] && distance[j] > graph[pos][j] && pos != j) {
                distance[j] = graph[pos][j];
            }
        }
    }

    double weight = 0;
    for (int i = 0; i < n; ++i) {
        weight += distance[i];
    }

    fout << std::setprecision(10) << weight;

    fin.close();
    fout.close();
    return 0;
}