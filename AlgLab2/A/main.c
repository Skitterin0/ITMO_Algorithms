#include <stdio.h>
#include <stdlib.h>

void Qsort(int *array, int left, int right) {
    int i = left;
    int j = right;
    int pivot = array[(left+right)/2];
    while (i < j) {
        while (array[i] < pivot)
            i++;
        while (array[j] > pivot)
            j--;
        if (i <= j) {
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j)
        Qsort(array, left, j);
    if (right > i)
        Qsort(array, i, right);
}


int main() {
    int n;
    FILE *fileIn, *fileOut;
    fileIn = fopen("sort.in","r");
    fileOut = fopen("sort.out","w");

    fscanf(fileIn, "%d", &n);
    int arrayIn[300000] = {0};
    for (int i=0; i<n; i++){
        fscanf(fileIn, "%d", &arrayIn[i]);
    }



    for (int i=0; i<n; i++) {
        fprintf(fileOut, "%d ", arrayIn[i]);
    }



    fclose(fileIn);
    fclose(fileOut);
    return 0;
}