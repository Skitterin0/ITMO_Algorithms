#include <iostream>
#include <vector>
using namespace std;

void qSort (vector<int>& array, int left, int right);

int main() {
    int n, k, A, B, C, a1, a2;
    freopen("kth.in", "r", stdin);
    freopen("kth.out", "w", stdout);
    cin>>n>>k;
    cin>>A>>B>>C>>a1>>a2;

    vector<int> array;
    array.push_back(a1);
    array.push_back(a2);

    int num;
    for (int i = 2; i < n; i++) {
        num = (A * array[i-2]) + (B * array[i-1]) + C;
        array.push_back(num);
    }

    qSort(array, 0, n-1);
    cout<<array[k-1]<<'\n';
    return 0;
}

void qSort (vector<int>& array, int left, int right) {
    int i = left;
    int j = right;
    int pivot = array[(left + right) / 2];

    while (i < j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            swap (array[i], array[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        qSort(array, left, j);
    if (right > i)
        qSort(array, i, right);
}