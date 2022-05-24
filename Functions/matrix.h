#include "f_library.h"
int** allocate_matrix(int **matrix, int n, int m){ //allocate memory in RAM for 2D array
    //n = rows * column = matrix_size
    int** mat = (int **)malloc(n * sizeof(int*));
    for (size_t i = 0; i < m; i++)  
        mat[i] = (int *)malloc(m * sizeof(int));
    
    //printf("%d\n",**mat); //location in memory
    return mat;
}

int** free_array(int **matrix,int size){ //deallocate outer array
    for (size_t i = 0; i < size; i++){
        free(matrix[i]);
        matrix[i] = NULL;
    }
    free(matrix);
    matrix = NULL;
    return 0;    
}
//print array according to defined size
int **pprint_matrix(int **matrix,int size){
    printf("\n"); 
    for (size_t i = 0; i <= size; i++){//rows
        for (size_t j = 0; j < size; j++) //cols
        printf("%d \t",matrix[i][j]);
        printf("\n");
    }
    printf("\n");
    return 0;
}
int print_matrix(int matrix[10][10],int row, int column){
    for (size_t i = 0; i < row; i++) //rows
        for (size_t j = 0; j < column; j++) //cols
            printf("%d \t", matrix[i][j]);
        
    printf("\n");
    return 0;
}