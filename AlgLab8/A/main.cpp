#include <fstream>

int main() {
    std::ifstream fin ("input.txt");
    std::ofstream fout ("output.txt");
    int n, m;
    fin >> n >> m;

    int matrix [n][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0;
        }
    }

    int x, y;
    for (int i = 0; i < m; i++) {
        fin >> y >> x;
        matrix[y-1][x-1] = 1;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            fout << matrix[i][j] << ' ';
        }
        fout << '\n';
    }

    fin.close();
    fout.close();
    return 0;
}
