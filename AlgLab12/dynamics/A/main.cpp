#include <iostream>
#include <fstream>
#include <vector>

int len;

int binSearch (std::vector<int>& d, int elem) {
    int l = 0;
    int r = d.size()-1;
    while (d[r] >= elem && l < r-1) {
        int m = (l + r)/2;
        if (d[m] < elem) {
            l = m;
        }
        else {
            r = m;
        }
    }
    return r;
}

std::vector<int> findLIS (std::vector<int>& array) {
    int n = array.size();
    int pos[n];
    std::vector<int> d(n+1, 1000010000);
    int prev[n];
    len = 0;

    pos[0] = -1;
    prev[0] = -1;
    d[0] = -1000010000;

    for (int i = 0; i < n; ++i) {
        int j = binSearch(d, array[i]);
        if (d[j-1] < array[i] && array[i] < d[j]) {
            d[j] = array[i];
            pos[j] = i;
            prev[i] = pos[j-1];
            len = std::max(len, j);
        }
    }

    std::vector<int> ans;
    int p = pos[len];
    while (p != -1) {
        ans.push_back(array[p]);
        p = prev[p];
    }

    return ans;
}

int main() {
    int n;
//    std::ifstream fin ("in.in");
//    fin >> n;
    std::cin >> n;

    std::vector<int> sequence (n);
    for (int i = 0; i < n; ++i) {
//        fin >> sequence[i];
        std::cin >> sequence[i];
    }

    std::vector<int> ans = findLIS (sequence);

    std::cout << len << '\n';
    for (int i = ans.size() - 1; i >= 0; --i) {
        std::cout << ans[i] << ' ';
    }

    return 0;
}