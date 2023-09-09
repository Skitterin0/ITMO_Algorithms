#include <fstream>

int main() {
    std::ifstream fin("knapsack.in");
    std::ofstream fout("knapsack.out");

    int capacity, count;
    fin >> capacity >> count;

    int weigth [count + 1];

    for (int i = 1; i <= count; ++i) {
        fin >> weigth[i];
    }

    int backpack[count + 1][capacity + 1];
    for (int i = 0; i <= capacity; ++i) {
        backpack[0][i] = 0;
    }


    for (int i = 1; i <= count; ++i) {
        for (int j = 0; j <= capacity; ++j) {
            if (j >= weigth[i]) {
                backpack[i][j] = std::max(backpack[i - 1][j], backpack[i - 1][j - weigth[i]] + weigth[i]);
            }
            else {
                backpack[i][j] = backpack[i - 1][j];
            }
        }
    }

    fout << backpack[count][capacity];

    return 0;
}
