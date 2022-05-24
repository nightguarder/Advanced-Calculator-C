#include "a_library.h"
struct Basic {
    double x=0,y=0,base =0, exponent =0;
    double result =0;
    char choice,sign;
};
int error_basic(double error){
    if(!isdigit(error))
    printf("Expected a number!\n");
    else if (isalpha(error))
        printf("Expected a number!\n");
    else if (error>6)
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
char choose_basic_options(struct Basic *pBas){
    char option = pBas->choice;
    int ESC = 0;
    while (scanf(" %c",&option)!=1){
        ESC = atoi(&option);
        //check if input is a number
        if (!isdigit(ESC)){
            printf("Failed. Expected a character or new line\n");
          return -1;
        }
        //check if is a character or contains special
        else if (isalpha(option))
            return error_basic(option);
            //not included!
        //else if(contains_special(option))
            //return error_basic(option);
    }
    if (isalpha(option))
        return error_basic(option);
    return tolower(option);
}
void display_result_basic(struct Basic *pBas){
printf("\nResult of %lf %c %lf = \n",pBas->base,pBas->sign,pBas->exponent);
printf("%lf\n",pBas->result);
}
double calc_exp(struct Basic *pBas){
    double res = pBas->result;
    double base = pBas->base;
    double exp = pBas->exponent;
    printf("Input in one line:\t base number(22) [SPACE] exponent(^2)\n");
    while (scanf(" %lf %lf",&base,&exp)!=2){
        if (!isdigit(base))
            error_basic(base);
        else if (isalpha(base))
            error_basic(base);
    }
    if (isalpha(base)|| isalpha(exp))
        error_basic(base);
    //save numbers to struct and assign sign
    pBas->base = base;
    pBas->exponent = exp;
    pBas->sign = '^';
    //calculate res
    return res = pow(base,exp);
}
double calc_log(struct Basic *pBas){
    double res = pBas->result;
    double base = pBas->base;
    double exp = pBas->exponent;
    printf("Input in one line:\t log(number)\n");
    while (scanf(" %lf",&base)!=1){
        if (!isdigit(base))
            error_basic(base);
        else if (isalpha(base))
            error_basic(base);
    }
    if (isalpha(base)|| isalpha(exp))
        error_basic(base);
    //save numbers to struct
    pBas->base = base;
    pBas->exponent = exp;
    pBas->sign = 'l';
    //calculate res
    return res = log(base);
}
double choose_basic_operation(struct Basic *pBas){
    double result = pBas->result;
    char choice = pBas->choice;
    switch (choice){
    case '1':
        printf("Your choice was: '%c' raise number top num^exp\n",choice);
        result =calc_exp(pBas);
        break;
    case '2':
        printf("Your choise was '%c' calculate log(2) of number\n",choice);
        result = calc_log(pBas);
        break;
    case '3':
        printf("Your choise was '%c' calculate log(base) of number\n",choice);
        break;
    case '4':
        printf("Your choise was '%c' calculate sqrt(2) of number\n",choice);
        break;
    case '5':
        printf("Your choise was '%c' calculate fact! of number\n",choice);
        break;
    default:
        printf("-------------\t A problem has occured...\t-------------\n");
        printf("-------------\t Exiting the program now...\t-------------\n");
        exit(0);
        break;
    }
    return result;
}
void display_basic_options(){
    printf("\nPlease CHOOSE your operation for Basic functions:\n");
    printf("Type '1' to calculate exp^ of a number\n");
    printf("Type '2' to calculate log(2) of number\n");
    printf("Type '3' to calculate log(e) of number\n");
    printf("Type '4' to calculate sqrt of number\n");
    printf("Type '5' to calculate fact! of number\n");
    printf("Press 'Q' to exit the program...\n");
}
int basic_calc(){
    Basic sBas;Basic *pBas;
    pBas = &sBas;
    char ch;
    int flag = 1;
    //check option
    while (flag){
        display_basic_options();
        pBas->choice = choose_basic_options(pBas);
        pBas->result = choose_basic_operation(pBas);
        display_result_basic(pBas);
        printf("Calculate again? (Y/N)\n");
        flag = end_program(flag,ch);
    }//while flag
    return 1;
}