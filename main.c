#include <stdio.h>
#include <malloc.h>
#include <conio.h>
#include "func.h"

int main(void)
{
    int **array, **help_array;    /* ��������� �� ������ */
    int i, rows, columns, max_i, max_j;
    char cheeck;

    printf("Enter number of rows (>1): ");
    /* �������� �� ����: �� ���� || ����� < 2 || ������ ����: ����� + ����� */
    while (scanf("%d", &rows) != 1 || rows <= 1 || (scanf("%c", &cheeck) == 1 && cheeck != '\n'))
    {
        scanf("%*[^\n]");
        printf("Wrong input. Try again.\n");
        printf("Enter number of rows (>1): ");
    }
    columns = rows - 1;
    printf("\nYour array:\n");

    /* ������ ��� �������� ������*/
    array = (int**)malloc(rows * sizeof(int*));     /* ��������� ������ ��� ������ ����������*/
    if (!array)
    {
        printf("error");
        exit(1);
    }
    for (i = 0; i < rows; i++)
    {
        array[i] = (int*)malloc(columns * sizeof(int));     /* ��������� ������ ��� �������� ����� */
    }

    input(rows, columns, array);    /* ��������� ���������� ������� */
    output(rows, columns, array);   /* ����� ��������� ������� */

    max(rows, columns, array, &max_i, &max_j);    /* ����� ��� �������� */

    /* ���������� ������ ��� �������� ������*/
    array = (int**)realloc(array, (rows + 1) * sizeof(int*));
    if (!array)
    {
        printf("error");
        exit(1);
    }
    rows += 1;
    array[rows - 1] = (int*)malloc(columns * sizeof(int));

    null_row(rows, columns, array, max_i, max_j);   /* ���������� ������ �� ����� */

    /* ������ ��� ��������������� (��������������) ������*/
    help_array = (int**)malloc(columns * sizeof(int*));
    if (!help_array)
    {
        printf("error");
        exit(1);
    }
    for (i = 0; i < columns; i++)
    {
        help_array[i] = (int*)malloc(rows * sizeof(int));
    }

    mirror_main_diagonal(rows, columns, array, help_array);   /* ����������� ������������ ������� ��������� */
    mirror_side_diagonal(rows, columns, array, help_array);   /* ����������� ������������ �������� ��������� */
    printf("\nResulting array:\n");
    output(rows, columns, array);

    /* ������� ������ ��������� � ���������������� ��������*/
    for (i = 0; i < rows; i++)
        free(array[i]);
    free(array);
    for (i = 0; i < columns; i++)
        free(help_array[i]);
    free(help_array);

    getch();
    return 0;
}
