#include <fstream>

int main() {
    std::ifstream fin ("input.txt");
    std::ofstream fout ("output.txt");
    int n;
    fin >> n;

    int matrix [n][n];
    int edge;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++ ){
            fin >> edge;
            matrix [i][j] = edge;
        }
    }

    bool isGraph = true;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if ((i != j && matrix[i][j] != matrix[j][i]) || (i == j && matrix[i][j] == 1)) {
                isGraph = false;
            }
        }
    }

    switch (isGraph) {
        case true:
            fout << "YES";
            break;
        case false:
            fout << "NO";
            break;
    }

    fin.close();
    fout.close();
    return 0;
}
