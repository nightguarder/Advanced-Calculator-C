#include "../Functions/functions.h"//greatest_common_divisor & least common multiple & Euclidian
#include "../Functions/matrix.h" //allocate matrix, free memory and print
//initialize all matrices
int const m =10, n=10;
struct Function{
    int a=0,b=0,c=0,result = 0,scalar = 0;
    int row,col;
    int matrix[m][n] ={0};
    char choice;
};
int error_function(int error){
    int *pch = &error;
    if(!isdigit(error))
    printf("Expected a number!\n");
    else if(contains_special((char)error))
        printf("Special character entered. Expected a number!\n");
    else if (isalpha(error))
        printf("Expected a number!\n");
    else if (error>5)
        printf("Option not on the list!\n");
    else if (error == 0)
        printf("This character is not accepted!\n");
    else{
        printf("-------------\t A problem has occured...\t-------------\n");
        printf("-------------\t Exiting the program now...\t-------------\n");
        exit(0);
    }
    exit(0);
    return -1;
}
void matrix_add_sub(int matrixA[m][n], int matrixB[m][n], int row, int col, int op){
    printf("\nSum of MatrixA + MatrixB =\n");
    int sumM[10][10];
    int subM[10][10];
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++)
            subM[i][j] = op * matrixB[i][j];
    //printing and add the numbers in the matrix
    for (size_t i = 0; i < row; i++)
        for (size_t j = 0; j < col; j++){
            sumM[i][j] = matrixA[i][j] + subM[i][j];
            printf(" %d\t", sumM[i][j]);
            if(j == col-1)
                printf("\n\n"); //new row  if col ends
        }
}
void matrix_scalar(int matrixA[m][n], int row, int col, int scalar){
    int scalM[m][n];
    //multiply each element in col&row with scalar input
    printf("\nScalar of '%d' * Matrix =\n",scalar);
    for (size_t i = 0; i < row; i++){
        for (size_t j = 0; j < col; j++){
            scalM[i][j] = scalar * matrixA[i][j];
            printf(" %d\t", scalM[i][j]);
            if(j == col-1)
                printf("\n\n"); //new row  if col ends
        }
    }
}
void matrix_mul(int matrixA[m][n],int matrixB[m][n], int rowA, int colA, int rowB, int colB){
    int mulM[m][n] ={0};
    printf("\nMultiply of MatrixA * MatrixB =\n");
    //for each row multiply the elements in colA with colB
    for (size_t i = 0; i<rowA; ++i){
        for (size_t j = 0; j < colB; ++j){
            for (size_t k = 0; k < colA; ++k)
                    mulM[i][j] += matrixA[i][k] * matrixB[k][j];
            printf(" %d\t", mulM[i][j]);
        }
        printf("\n\n");
    }
}
//ask user what the size should be
void read_matrix_size(struct Function *pFun){
    printf("Input in one line: row(3) [SPACE] col(3)\n");
    while (scanf(" %d %d",(&pFun->row), (&pFun->col))!=2){
        if (!isdigit(pFun->row)||!isdigit(pFun->col))
            error_function(pFun->row);
        else if (isalpha(pFun->row)|| isalpha(pFun->col))
            error_function(pFun->row);
    }
}
//read user's input to matrix
int read_matrix(int matrix[m][n], int row, int column){
    for (int i = 0; i < row; i++){
        printf("\t%d entries for row %d: ", column, i + 1);
        for (int j = 0; j < column; j++)
            scanf("%d", &matrix[i][j]);//read until end of column
    }
    return 1;
}
struct Function check_dimensions(struct Function *pFun){
    struct Function mA,mB;
    printf("Input the size of Matrix A:\n");
    read_matrix_size(&mA);
    printf("Input the size of Matrix B:\n");
    read_matrix_size(&mB); 
    //check if col and row matches
    if ((mA.row != mB.row) || (mA.col != mB.col)){ 
        printf("\nMatrices must be the same size!\n");
        error_function(mA.row);
    }
    return mA;
}
//pre-fucntion to read Elements of matrix
void read_matrix_numbers(int matrix[m][n],int row, int col){
    printf("\nEnter elements of Matrix %d x %d:\n",row,col);
    read_matrix(matrix,row,col);
}
//performing caluclation based on user's choice
int decide_matrix_operation(struct Function *pFun){
    struct Function ans,ans2;
    int result = pFun->result;
    char option = pFun->choice;
    int matrixA[m][n],matrixB[m][n];
    switch (option){
    case '1':
        printf("Your choice was: %c Addition\n",pFun->choice);
        //check if matrices are the same size
        ans = check_dimensions(pFun);
        //put this into function tree
        //read for each matrix
        read_matrix_numbers(matrixA,ans.row,ans.col);
        read_matrix_numbers(matrixB,ans.row,ans.col);
        matrix_add_sub(matrixA,matrixB,ans.row,ans.col,1);
        break;
    case '2':
        printf("Your choice was: %c Addition\n",pFun->choice);
        ans = check_dimensions(pFun);
        read_matrix_numbers(matrixA,ans.row,ans.col);
        read_matrix_numbers(matrixB,ans.row,ans.col);
        matrix_add_sub(matrixA,matrixB,ans.row,ans.col,-1);
        break;
    case '3':
        printf("Your choice was: %c Scalar multiply\n",pFun->choice);
        printf("\nEnter the scalar first: ");
        scanf("%d", &pFun->scalar);
        ans = check_dimensions(pFun);
        read_matrix_numbers(matrixA,ans.row,ans.col);
        matrix_scalar(matrixA,ans.row,ans.col,pFun->scalar);
        break;
    case '4':
         printf("Your choice was: %c Multiplication\n",pFun->choice);
         ans = check_dimensions(pFun);
         //read matrixA then matrixB
         read_matrix(matrixA,ans.row,ans.col);
                    //matrixA row, col              MatrixB row,col
         matrix_mul(matrixA,matrixB,ans.row,ans.col,ans2.row,ans2.col);
         break;
    default:
        printf("-------------\t Option is not on the list!\t-------------\n");
        printf("-------------\t Exiting the program now...\t-------------\n");
        exit(0);
        break;
    }
    return result;
}
char choose_matrix_operation(struct Function *pFun){
    char op = pFun->choice;
    printf("\nPlease choose your Matrix operation:\n");
    printf("1. to Add\n");
    printf("2. to Subtract\n");
    printf("3. to Scalar Multiply\n");
    printf("4. to Multiply two matrices\n");
    scanf(" %c", &op);
    if (!isdigit(op))
        error_function(op);
    return tolower(op);
}
//function to handle operations
int calc_matrix(struct Function *pFun){
    int res = pFun->result;
    //ask which operation (+,-,*) to run
    pFun->choice = choose_matrix_operation(pFun);
    //switch case which operation to run
    decide_matrix_operation(pFun);
    return res;
}
//calculation greatest common divisor
int calc_gcd(struct Function *pFun){
    int x = pFun->a; int y = pFun->b;
    int res = pFun->result;
    printf("Input in one line: number(123) [SPACE] number(321)\n");
    while (scanf(" %d %d",&x,&y)!=2){
        if (!isdigit(x)||!isdigit(y))
            error_function(x);
        else if(isalpha(x)|| isalpha(y))
            error_function(x);
    }
    printf("Your input: %d, %d\n",x,y);
    printf("Greatest common divisor of %d, %d = ",x,y);
    res = gcd(x,y);
    return res;
}
//calculation least common multiple
int calc_lcm(struct Function *pFun){
    int x = pFun->a; int y = pFun->b;
    int res = pFun->result;
    printf("Input in one line: number(123) [SPACE] number(321)\n");
    while (scanf(" %d %d",&x,&y)!=2){
        if (!isdigit(x)||!isdigit(y))
            error_function(x);
        else if(isalpha(x)|| isalpha(y))
            error_function(x);
    }
    printf("Your input: %d, %d\n",x,y);
    printf("Least common multiple of %d, %d = ",x,y);
    res = lcm(x,y);
    return res;
}
//calculation extended euclidian and returning result
int calc_ecl(struct Function *pFun){
    int x = pFun->a; int y = pFun->b;
    int res = pFun->result;
    int px=0,py = 0;
    printf("Input in one line: number(123) [SPACE] number(321)\n");
    while (scanf(" %d %d",&x,&y)!=2){
        if (!isdigit(x)||!isdigit(y))
            error_function(x);
        else if(isalpha(x)|| isalpha(y))
            error_function(x);
    }
    printf("Your input: %d, %d\n",x,y);
    printf("Extended euclidian of %d, %d = ",x,y);
    res = extended_ecl(x,y,&px,&py);
    return res;
}
//decide which function to run based on choice.
int choose_function(struct Function *pFun){
    char choice = pFun->choice;
    int result = pFun->result;
    switch (choice){
    case '1':
        printf("Your choice was: '%c' Greatest Common Divisor (GCD)\n",choice);
        result = calc_gcd(pFun);
        break;
    case '2':
        printf("Your choise was '%c' Least Common Multiple (LCM)\n",choice);
        result = calc_lcm(pFun);
        break;
    case '3':
        printf("Your choise was '%c' Extended Euclidian (ECL)\n",choice);
        result = calc_ecl(pFun);
        break;
    case '4':
        printf("Your choise was '%c' Matrix operations (+,-,*)\n",choice);
        result = calc_matrix(pFun);
        break;
    default:
        printf("-------------\t A problem has occured...\t-------------\n");
        printf("-------------\t Exiting the program now...\t-------------\n");
        exit(0);
        break;
    }
    return result;
}
void display_result_function(struct Function *pFun){
    int result = pFun->result;
    //printf("%d\n",pFun->result);
}
int check_function_input(struct Function *pFun){
    char op = pFun->choice;
    int ESC;
    while (scanf(" %c",&op)!=1){
        ESC = atoi(&op);
        //check if input is a number
        if (!isdigit(ESC))
            error_function(ESC);
        //check if is a character or contains special    
        else if (isalpha(op))
            return error_function(op);
        else if(contains_special(op))
            return error_function(op);
    }
    if (isalpha(op))
        return error_function(op);
    
    return tolower(op);
}
void display_functions(){
    printf("\nPlease CHOOSE your fucntion from the list:\n");
    printf("Type '1' for Greatest Common Divisor (GCD)\n");
    printf("Type '2' for Least Common Multiple (LCM)\n");
    printf("Type '3' for Extended euclidian algorithm (ECL)\n");
    printf("Type '4' for Matrix operations (+,-,*)\n");
    printf("Press 'Q' to exit the program...\n");
}
//main function called from main
int custom_calc(){
    Function sFun;Function *pFun;
    pFun = &sFun;
    char ch;
    int flag = 1;
    //check option
    while (flag){
        display_functions();
        pFun->choice = check_function_input(pFun);
        pFun->result = choose_function(pFun);
        //printf("Result in struct: %d",pFun->result);
        display_result_function(pFun);
        printf("Calculate again? (Y/N)\n");
        flag = end_program(flag,ch);
    }//while flag
    return 1;
}