#include <fstream>
#include <vector>

void upd(int x, int y, std::vector<std::vector<int>>& board) {
    board[x][y] += board[x-2][y-1] + board[x-2][y+1] + board[x-1][y-2] + board[x+1][y-2];
}

int main() {
    std::ifstream fin("knight2.in");
    std::ofstream fout("knight2.out");

    int n, m;
    fin >> n >> m;

    n += 2;
    m += 2;

    std::vector<std::vector<int>> board;
    board.assign(n+1, std::vector<int>(m+1, 0));
    board[2][2] = 1;
    int i = 2;
    int j = 2;

    while (i != n-1 || j != m-1) {
        int x = i;
        int y = j;

        while (x >= 2 && y < m) {
            upd(x--, y++, board);
        }

        i == n-1 ? j++ : i++;
    }

    upd(n-1, m-1, board);

    fout << board[n-1][m-1];

    fin.close();
    fout.close();
    return 0;
}
