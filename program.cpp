//Tento zdrojovy kod jsem vypracoval zcela samostatne bez cizi pomoci
//Neokopiroval jsem ani neopsal jsem cizi zdrojove kody
//Nikdo me pri vypracovani neradil
//Pokud nektery radek porusuje toto pravidlo je oznacen komentarem
//NENI MOJE TVORBA
//Poruseni techto pravidel se povazuje za podvod, ktery lze potrestat VYLOUCENIM ZE STUDIA
//Cyril Steger učo. 36830
#include <stdio.h>
#include "Headers/include.h" // all Headers files are included here
//#include "Functions/functions.h"

int user_choice(int choice){
  int temp = 0;
  int *pchoice = &choice;
  switch (choice){
    case 1:
        printf("You choice was: '%d' Simple calculation \n",pchoice);
        simple_calc();
        break;
    case 2:
        printf("You choice was: '%d'. Basic functions \n",*pchoice);
        break;
    case 3:
        printf("Your choice was: '%d'. Trigometry functions \n",*pchoice);
        break;
    case 4:
        printf("Your choice was: '%d'. Binary conversion \n",*pchoice);
        binary_calc();
        break;
    case 5:
        printf("Your choice was: '%d'. Custom functions \n",*pchoice);
        custom_calc();
        break;
    case 6:
        printf("Your choice was: '%d'. Complex arithmetics \n",*pchoice);
        complex_calc();
        break;
  default:
        printf("Your option was not on the list!\n");
        printf("Please choose from the list (1-6)\n");
        printf("Press 'Q' to exit the program...\n");
        //check only input and call user_choice
        check_input(temp,pchoice);
        user_choice(temp);
    break;
  }
  return choice;
}
void option_list(char * option[]){
    //option from the parameters
    char *p = 0;
    char *pchoice = option[2];
    int user = 0;
    int temp = strtol(option[2],&p,10);
    printf("1. Simple calculation\t (+, -, /, *, %)\n");
    printf("2. Basic functions\t (exp^, log, ln, sqrt, n!)\n");
    printf("3. Trigometry functions\t (sin, cos, tan, cot)\n");
    printf("4. Binary conversion\t (BIN, HEX, DEC, OCT)\n");
    printf("5. Custom functions\t (gcd, lcm, matrix)\n");
    printf("6. Complex arithmetics\t (a+bi,a-bi,a*bi,a/bi)\n");
    //printf("Your option was: %s %s\n",option[1],option[2]);//1
    //choose which action to run or ask the user
    switch (temp){
    case 1:
        printf("You choice was '%s'. Simple calculation \n",pchoice);
        simple_calc();
        break;
    case 2:
        printf("You choice was '%s'. Basic functions \n",pchoice);
        basic_calc();
        break;
    case 3:
        printf("Your choice was '%s'. Trigometry functions \n",pchoice);
        break;
    case 4:
        printf("Your choice was '%s'. Binary conversion \n",pchoice);
        binary_calc();
        break;
    case 5:
        printf("Your choice was '%s'. Custom functions \n",pchoice);
        custom_calc();
        break;
    case 6:
        printf("Your choice was '%s'. Complex arithmetics \n",pchoice);
        complex_calc();
        break;
    //not on the list? check input again
    default:
        printf("Your option was not on the list!\n");
        printf("Please choose from the list (1-6)\n");
        printf("Press 'Q' to exit the program...\n");
        temp = check_input(temp,&user);
        user_choice(temp);
        break;
    }
    return;
}
int main(int argc, char **argv){
    int pn,pm,user,temp1 =0;
    int flag = 1;
    //Check start parameters
    check_param(argc,argv,&pn,&pm);
    printf("-------------\tWelcome to Advanced Calculator! %s\t-------------\n",argv[1]);
    printf("-------------\t        by Cyril Steger            \t-------------\n");
    //choose from the list
    while(flag){
        printf("-------------\tPress 'Q' to exit the program...\t-------------\n");
        option_list(argv);
        return flag = 0;
    }
    return 0;
}