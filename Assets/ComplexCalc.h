#include "a_library.h"
#include <complex>
//#include <ccomplex>
//#include <complex.h>
//#include <complex.h> pro cpp compiler is not working :(
struct Resultimg{
    double real = 0,img = 0 ,temp = 0;
    double a= 0,ai = 0,b= 0,bi =0;
    char operand;
    //save result to string
    double numRes[INT8_MAX] = {0}; 
}; 
int error_operation(char op, double a, double ai){
    //convert char to int to check 
    int iop = atoi(&op);
    if (isdigit(iop)){
        printf("Your operator was: '%d' which is not supported...\n",iop);
        printf("Please try again.\n");
        simple_calc();
    }
    else if(isalpha(iop)){
        printf("Your operator was: '%c' which is not supported...\n",op);
        printf("Please try again.\n");
        simple_calc();
    }
    else if (a == 0 && ai == 0 ){
        printf("Cannot divide by '%lf'\n", ai);
        printf("Please try again.\n");
        simple_calc();
    }
    else{
        printf("-------------\t Expected an operator! \t-------------\n");
        printf("-------------\t Please try again! \t-------------\n");
        exit(0);
    }
    return 0;
}
double img_sum(struct Resultimg *ptr){
    //combine real first then imaginary
    //Result= (a+b)+(ai+bi)
    ptr->real = ptr->a + ptr->b;
    ptr->img = ptr->ai + ptr->bi;
    ptr->numRes[1] = ptr->real;
    ptr->numRes[2] = ptr->img;
    //display_function(double real, double img)
    //returns result[array]
    if (ptr->img >=0)
        printf("Sum of the complex numbers = %lf + %lfi\n", ptr->numRes[1],ptr->numRes[2]);
    else
        printf("Sum of the complex numbers = %lf %lfi\n", ptr->numRes[1], ptr->numRes[2]);
    return 1;
}
double img_diff(struct Resultimg *ptr){    
    ptr->real = ptr->a - ptr->b;
    ptr->img = ptr->ai - ptr->bi;
    if (ptr->img >=0)
        printf("Diffence of the complex numbers = %lf - %lfi\n", ptr->real, ptr->img);
    else
        printf("Difference of the complex numbers = %lf %lfi\n", ptr->real, ptr->img);
    return 1;
}
double img_mul(struct Resultimg *ptr){
    ptr->real = ptr->a * ptr->b;
    ptr->img = ptr->ai * ptr->bi;
    if (ptr->img >=0)
        printf("Multiplication of the complex numbers = %lf * %lfi\n", ptr->real, ptr->img);
    else
        printf("Multiplication of the complex numbers = %lf %lfi\n", ptr->real, ptr->img);
    return 1;
}
double img_divs(struct Resultimg *ptr){
    double _complex = ptr->a * ptr->b + ptr->ai * ptr->bi;
    //creal(_complex);
    //printf("Real value: %lf\n",creal(_complex));
    //division by 0 not allowed!
    if (ptr->b == 0 && ptr->bi == 0)
        error_operation(ptr->operand,ptr->b,ptr->bi);
    else{
        int x = ptr->a * ptr->b + ptr->ai * ptr->bi;
        int y = ptr->ai * ptr->b - ptr->a * ptr->bi;
        int z = ptr->b * ptr->b + ptr->bi *ptr->bi;
        if (x%z == 0 && y%z == 0){
          if (y/z >= 0)
            printf("Division of the complex numbers = %d + %di\n", x/z, y/z);
          else
            printf("Division of the complex numbers = %d %di\n", x/z, y/z);
        }
        else if (x%z == 0 && y%z != 0){
          if (y/z >= 0)
            printf("Division of two complex numbers = %d + %d/%di\n", x/z, y, z);
          else
            printf("Division of two complex numbers = %d %d/%di\n", x/z, y, z);
        }
        else if (x%z != 0 && y%z == 0){
          if (y/z >= 0)
            printf("Division of two complex numbers = %d/%d + %di\n", x, z, y/z);
          else
            printf("Division of two complex numbers = %d %d/%di\n", x, z, y/z);
        }
        else{
          if (y/z >= 0)
            printf("Division of two complex numbers = %d/%d + %d/%di\n",x, z, y, z);
          else
            printf("Division of two complex numbers = %d/%d %d/%di\n", x, z, y, z);
        }
    }
    return 0;    
}
//switch to decide which operation to sum, divide complex numbers.
void calculate_complex(double a,double ai,double b,double bi,struct Resultimg *ptr){
    switch (ptr->operand)
    {
    case '+':
    //ptr.result = 
        img_sum(ptr);
        break;
    case '-':
        img_diff(ptr);
        break;
    case '*':
        img_mul(ptr);
        break;
    case '/':
        img_divs(ptr);
        break;
    default:
        printf("-------------\t A problem has occured...\t-------------\n");
        printf("-------------\t Exiting the program now...\t-------------\n");
        exit(0);
        break;
    }
}
//function to check incoming characters and which error
int check_characters(char input,struct Resultimg *ptr){
    char pch = input;
    tolower(pch);
    if ( pch >= 'a' && pch <= 'z')
        error_operation(pch,ptr->a,ptr->ai);
    else if(pch >= '0' && pch <= '9')
        error_operation(pch,ptr->a,ptr->ai);
    //success characters is a special character
    printf("Your choice was: %c\n",pch);       
    return 1;
}
char check_character_input(char op,struct Resultimg *pRes){
    //scanf returns the value EOF (which is -1) on end of file
    while (scanf(" %c\n",&op)!=1){
            //assign output to Result
            pRes->operand = op;
            if (op >='a' && op <='z')
                exit(0); 
            //check if is number or character
            if (isdigit((int)op))
                exit(0);
            else
                check_characters(op,pRes);
            
        }
    return op;
}
void display_options_cmplx(){
    printf("\nPlease CHOOSE your operation for Complex numbers:\n");
    printf("Type '+' to add two complex numbers.\n");
    printf("Type '-' to subtract two complex numbers.\n");
    printf("Type '*' to multiply two complex numbers.\n");
    printf("Type '/' divide two complex numbers.\n");
    printf("Press 'Q' to exit the program...\n");
}
//create struct function
void check_complex_input(Resultimg a,Resultimg ai,Resultimg b,Resultimg bi){
}
//Choose complex operation first
//Function called from main() decides what to do next..
int complex_calc(){
    Resultimg sRes,a,b,c;
    Resultimg *pRes,*pa,*pb,*pc;
    pRes = &sRes; pa= &a; pb =&b; pc = &c;
    int flag = 1;
    char ch;
    while (flag){
        display_options_cmplx();
        //ask user which operation to run
        sRes.operand= check_character_input(ch,pRes);
        //check if operator was correct
        check_characters(sRes.operand,pRes);
        //ask user for the input numbers
        //sRes.a=check_complex_input(sRes,pRes);
        printf("Input in one line:\ta= real num (3) ai= complex num(7i) [ENTER]\n");
        printf("Input in second line:\tb= real num (1) bi= complex num(5i) [ENTER]\n");
        while (scanf(" %lf %lf\n %lf %lf",&sRes.a,&sRes.ai,&sRes.b,&sRes.bi)!=4){
        //assign result to struct
        pRes->a = sRes.a; pRes->ai = sRes.ai;
        pRes->b = sRes.b; pRes->bi = sRes.bi;
        if (!isdigit(sRes.a)||!isdigit(sRes.ai)||!isdigit(sRes.b)||!isdigit(sRes.bi))
            error_calc(sRes.a,sRes.operand);
        if (isalpha(sRes.a))
            error_calc(sRes.a,sRes.operand);
        
        return 1;
        }//while number input  
        printf("Your input was:\ta=%lf ib=%lf c=%lf di=%lf\n",pRes->a,pRes->ai,pRes->b,sRes.bi);
        //calculate the result
        calculate_complex(sRes.a,sRes.ai,sRes.b,sRes.bi,pRes);
        printf("Calculate again? (Y/N)\n");
        //ask user
        flag = end_program(flag,ch);
    }// while flag
    return 1;
}// complex_calc()
