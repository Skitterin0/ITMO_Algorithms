#include <fstream>
#include <vector>
#include <queue>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");

    int n, s, man, friends;
    fin >> n >> s;
    std::vector<std::vector<int>> matrix;
    std::vector<bool> visit(n);
    matrix.resize(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int man;
            fin >> man;
            if (man) {
                matrix[i].push_back(j);
            }
        }
    }

    std::queue<int> Q;
    friends = 0;
    Q.push(s);
    while(!Q.empty()) {
        man = Q.front();
        Q.pop();
        if (!visit[man]) {
            friends++;
            visit[man] = true;
            for (int i = 0; i < matrix[man].size(); ++i) {
                Q.push(matrix[man][i]);
            }
        }
    }

    fout << friends-1;

    fin.close();
    fout.close();
    return 0;
}
