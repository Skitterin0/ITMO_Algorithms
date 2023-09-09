#include <fstream>
#include <vector>

int main() {
    std::ifstream fin("input.txt");
    std::ofstream fout("output.txt");
    int n, m;
    fin >> n >> m;

    std::vector<int> list (n);
    int eStart, eEnd;

    for (int i = 0; i < m; ++i) {
        fin >> eStart >> eEnd;
        list[eStart-1]++;
        list[eEnd-1]++;
    }

    for (int i = 0; i < n; ++i) {
        fout << list[i] << ' ';
    }

    fin.close();
    fout.close();
    return 0;
}
