#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Practice 6
//Варианты 1 и 3
int main(void) {
srand(time(NULL));
int **ar;
int i, j, n, *mas;
n = rand() % 5;
printf("Количество строк матрицы: %d\n", n);
ar = (int **) malloc(n * sizeof(int *)); //выделение памяти для двумерного массива
mas = (int *) malloc(n * sizeof(int)); //выделение памяти для одномерного массива (в данной задаче для количества элементов в строке)
//значения одномерного массива
for (i = 0; i < n; i++) {
mas[i] = rand() % 10 + 1;
printf("Количество столбцов строки %d: %d\n", i + 1, mas[i]);
ar[i] = (int *) malloc(mas[i] * sizeof(int)); //выделение памяти для указателей на строки
}
printf("\n");
//адреса одномерного массива
for (i = 0; i < n; i++) {
printf("Адрес %d-го элемента: %p\n", i + 1, &mas[i]);
}
printf("\n");
//значения двумерного массива
for (i = 0; i < n; i++) {
for (j = 0; j < mas[i]; j++) {
ar[i][j] = rand() % 201 + 100;
printf("ar[%d][%d]= %d\t", i + 1, j + 1, ar[i][j]);
}
printf("\n");
}
printf("\n");
//адреса двумерного массива
for (i = 0; i < n; i++) {
for (j = 0; j < mas[i]; j++) {
printf("Адрес %d-го элемента в %d-м столбце: %p\n", i + 1, j + 1, &ar[i][j]);
}
}
printf("\n");
//значения двумерного массива
for (i = 0; i < n; i++) {
for (j = 0; j < mas[i]; j++) {
printf("%5d ", ar[i][j]); // 5 знакомест под элемент массива
}
printf("\n");
free(ar[i]); //освобождение памяти под строку
}
free(ar); //освобождение памяти
free(mas);
return 0;
}