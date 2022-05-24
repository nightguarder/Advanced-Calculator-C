#include "libraries.h"
int error_calc(double par1,char op){
  if (isalpha(op)){
    printf("Expected an operator!\n");
    exit(0);
  }
  if (isalpha(par1)){
    printf("Expected a number!\n");
    exit(0);
  }
  //add overflow error
  else{
        printf("-------------\t Expected an operator! \t-------------\n");
        printf("-------------\t Please try again! \t-------------\n");
        exit(0);
  }
  
  return 0;
}
int erorr_handle(int argc, char** argv)
{   
    if (argc < 1){
      printf("Too few arguments entered.\n");
      exit(0);
    }
    
    if (argc =='q')
    {
      printf("Exit the program...\n");
      exit(0);
    }
    if (!isdigit(argc))
    {
      printf("Expected a number!\n");
      exit(0);
    }
    
    //program is working only with 2 parameters passed
    else if( argc == 2 ){
      printf("Expected ./program.cpp string(name) number(option):\n");
      printf("You only passed: %s %s \n",argv[0],argv[1]);
      exit(0);
    }
    //too many? exit
    else if( argc > 3 )
      exit(0);
    //program not found
    else if(argv[0] == NULL)
      exit(0);
    //no paramater passed
    else if(argv[1] == NULL)
      exit(0);
    //other errors
    else 
      printf("-------------\t A problem has occured... \t-------------\n");
      printf("-------------\t Exiting the program now...\t-------------\n");
      exit(0);
    
    return 0;
}
//initial check if the parameters entered when executing the program is correct
void check_param(int argc, char* argv[], int *pr, int *pr2){
    char *p = 0;
    errno = 0;
    int n = 0;
    //convert string to int &p = modified end pointer 10 = radix number 
    int temp = strtol(argv[2],&p,10);
    if (argc == 0)
      erorr_handle(argc,argv);
 //program only needs 2 parameters .\program -name -number
    if (argv[1]==NULL)
      erorr_handle(argc,argv); 
    //if parameter is invalid or larger than int
    else if (errno != 0 || *p != '\0'|| temp>INT_MAX || temp<INT_MIN)
      erorr_handle(n,argv);
    else{
      printf("parameters passed: %s, %s, %s\n",argv[1],argv[2],argv[3]);
      printf("-------------\tOK Starting the calculator now...\t-------------\n");
    }
}
//check what the user has entered, usually asked if paramaters doesnt match Calculator options
int check_input(int x, int *save1){
  int input = 0;
  char ESC;
    while (scanf(" %d%c",&x,&ESC)!=2)
    {
        tolower(ESC);
        //check for exit
        if (ESC =='q')
          exit(0);
        if (x =='q'||ESC == 'q')
          exit(0);
        //check if input is a number
        else if (!isdigit(x))
          erorr_handle(x,__argv);
        //not a number? return
        else
          printf("Failed. Expected a number or new line\n");
          return -1;
    }
    //user didnt choose from list 1-6
    if (x > 6) 
      return erorr_handle(x,__argv);
    else if(x == 0)
      return erorr_handle(x,__argv);
    //sucess continue
    else
    *save1 = x;
    x = *save1;
    printf ("Your option was: %d . %d\n", x,save1);
    return x;
}

