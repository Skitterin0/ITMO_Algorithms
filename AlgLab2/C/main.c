#include <stdio.h>

int main() {
    int n;
    FILE *fileIn, *fileOut;
    fileIn = fopen("inversions.in", "r");
    fileOut = fopen("inversions.out", "w");

    fscanf(fileIn, "%d", &n);
    int arrayIn[100000] = {0};

    for (int i = 0; i < n; i++) {
        fscanf(fileIn, "%d", &arrayIn[i]);
    }

    int countInversions = 0;
    for (int i=0; i<n-1; i++){
        for (int j=i+1; j<n; j++){
            if (arrayIn[i] > arrayIn[j])
                countInversions++;
        }
    }

    fprintf(fileOut,"%d", countInversions);

    fclose(fileIn);
    fclose(fileOut);
    return 0;
}

