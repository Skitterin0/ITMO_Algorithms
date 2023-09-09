#include <stdio.h>

int main() {
    int n, i;
    FILE *fileIn, *fileOut;
    fileIn = fopen("antiqs.in","r");
    fileOut = fopen("antiqs.out", "w");
    fscanf(fileIn, "%d", &n);

    int array[70000];
    for (i = 0; i < n; i++) {
        array[i]=i+1;
    }

    int temp;
    for (i = 0; i < n; i++){
        temp = array[i];
        array[i] = array[i/2];
        array[i/2] = temp;
    }

    for (i = 0; i < n; i++)
        fprintf(fileOut, "%d ", array[i]);

    fclose(fileIn);
    fclose(fileOut);
    return 0;
}
