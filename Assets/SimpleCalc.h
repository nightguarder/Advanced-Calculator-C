//%lf.........double //%lld..........long long int //%f..........float //%d..........int //%u..........unsigned int //%s..........char[]//%c.........char
#include "a_library.h"
struct Result{
    double number1 =0,number2=0,result = 0;
    char operand;
};
//Siple calculation functions
void display_result(double n1,double n2,char op, struct Result *ptr){
    printf("Result: %lf %c %lf = %lf\n",n1,op,n2,ptr->result);
}
double add_sum(double n1,double n2, struct Result *ptr){
    return ptr->result = n1 + n2;
}
double subtract(double n1,double n2,struct Result *ptr){
    return ptr->result = n1 - n2;
}
double multiply(double n1,double n2,struct Result *ptr){
    return ptr->result = (n1 * n2);
}
double divide(double n1,double n2,struct Result *ptr){
    return ptr->result = n1 / n2;
}
double remainder(double n1,double n2,struct Result *ptr){
    return ptr->result = fmod(n1,n2);
}
int end_program(int flag,char ch){
    scanf(" %c",&ch);
        if (isalpha(ch))
        ch = tolower(ch);
        if (ch == 'n')
            flag == 1;
        if (ch == 'y')
            flag == 0;
        else {
            printf("Exit program...\n");
            return 0;
        }
    return flag;
}
//calculate and display Results
void calculate_res(char op,double pnum1,double pnum2, struct Result *ptr){
    double temp;
    temp =fmod(pnum1,pnum2);
    //truncate numbers if it has no decimals
    /* if (temp != 0){
        pnum1 = trunc(pnum1*0.10)/0.10;
        pnum2 = trunc(pnum2*0.10)/0.10;
    } */
    //choose operation
    switch (op)
    {
    case '+':
        add_sum(pnum1,pnum2,ptr);
        display_result(pnum1,pnum2,op,ptr);
        break;
    case '-':
        subtract(pnum1,pnum2,ptr);
        display_result(pnum1,pnum2,op,ptr);
        break;
    case '*':
        multiply(pnum1,pnum2,ptr);
        display_result(pnum1,pnum2,op,ptr);
        break;
    case '/':
        divide(pnum1,pnum2,ptr);
        display_result(pnum1,pnum2,op,ptr);
        break;
    case '%':
        remainder(pnum1,pnum2,ptr);
        display_result(pnum1,pnum2,op,ptr);
        break;
    default:
        error_calc(pnum1,op);
        break;
    }
    //printf("1st. Parameters passed: %c %lf\n",op, ptr->result);
}
//prepare input before calculation
int simple_calc(){
    //variables
    int flag = 1;
    char op,ch;
    //create pointer for Result
    Result sRes;Result *pRes;
    pRes = &sRes;
    //while flag
    while(flag){
        printf("\n");
        printf("Input in one line: (1)number (+,-,*,/,%)operator (1)number\n");
        while (scanf(" %lf %c %lf",&sRes.number1,&sRes.operand,&sRes.number2)!=3){
            //assign output to Result
            //check if sRes is a number
            if (!isdigit(sRes.number1)||!isdigit(sRes.number2))
                error_calc(sRes.number1,sRes.operand);
            tolower(sRes.operand);
            //check if sRes is a number
            if (sRes.operand >='a'&& sRes.operand<='z')
                exit(0);
            if (isdigit((int)sRes.operand))
                exit(0);
            else{
                printf("Unexpected error...\n");
                error_calc(sRes.number1,sRes.operand);
                exit(0);
            }
            return 1;
        } //while input
        //assign output to Result
        pRes->number1 = sRes.number1; pRes->number2 = sRes.number2;
        pRes->operand = sRes.operand;
        //calculate Users>>> choice op, first number, second number, struct pointer
        calculate_res(pRes->operand,pRes->number1,pRes->number2,pRes);
        printf("Calculate again? (Y/N)\n");
        //ask user
        flag = end_program(flag,ch);
    }//while flag
return 1;
}