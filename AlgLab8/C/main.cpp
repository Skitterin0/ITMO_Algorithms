#include <fstream>

int main() {
    std::ifstream fin ("input.txt");
    std::ofstream fout ("output.txt");

    int n, m, edgeS, edgeE;
    fin >> n >> m;
    int graph[m][2];

    for (int i = 0; i < m; i++) {
        fin >> edgeS >> edgeE;
        if (edgeE == edgeS) {
            fout << "YES";
            return 0;
        }
        graph[i][0] = edgeS;
        graph[i][1] = edgeE;
        for (int j = i - 1; j >= 0; j--) {
            if (graph[j][0] == graph[i][1] && graph[j][1] == graph[i][0]) {
                fout << "YES";
                return 0;
            }
            else if (graph[j][1] == graph[i][1] && graph[j][0] == graph[i][0]) {
                fout << "YES";
                return 0;
            }
        }
    }

    fout << "NO";
    fin.close();
    fout.close();
    return 0;
}