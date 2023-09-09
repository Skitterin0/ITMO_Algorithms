#include <iostream>
#include <fstream>
#include <vector>

void LCS(std::vector<std::vector<char>>& lcs, std::string& x, std::string& y) {
    uint32_t m = x.size();
    uint32_t n = y.size();

    for (int i = 1; i < m; ++i) {
        for (int j = 1; i < n; ++i) {
            if (x[i] == y[j]) {
                lcs[i][j] = lcs[i-1][j-1] + 1;
            }
        }
    }
}

int main() {
    std::string s1, s2;

    std::ifstream fin("in.in");
    fin >> s1 >> s2;
//    std::cin >> s1 >> s2;

    std::vector<std::vector<char>> lcs;
    lcs.resize(s1.size());
    for (int i = 0; i < s1.size(); ++i) {
        lcs[i].assign(s2.size(), '0');
    }

    LCS(lcs, s1, s2);

    return 0;
}
