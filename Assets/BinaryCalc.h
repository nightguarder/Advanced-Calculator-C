#include "a_library.h"
#define MAX_READ 63
struct Convert
{
    long long bin =0,hex = 0,dec=0,oct = 0,other =0;
    char choice;
    char buff[INT8_MAX];//buffer is limited to 127 characters
    long result =0;
};
//check if input contains any special characters. 
int contains_special(const char inp)
{
    if(inp == '!' || inp == '@' || inp == '#' || inp == '$'
      || inp == '%' || inp == '^' || inp == '&' || inp == '*'
      || inp == '(' || inp == ')' || inp == '-' || inp == '{'
      || inp == '}' || inp == '[' || inp == ']' || inp == ':'
      || inp == ';' || inp == '"' || inp == '<' || inp == '>' 
      || inp == '.' || inp == '/' || inp == '?' || inp == '+'
      || inp == '~' || inp == '`' )
    return 1;
   // Returns 1 if input contains a special character. Otherwise returns 0.
   return 0;
}
int error_option_input(char choice,long long num){
    int iop = atoi(&choice);
    if (isdigit(iop))
        exit(0);
    if (choice == 'q' || choice == 'Q'){
        printf("Exit program...\n");
        exit(0);
    }
    else if (!isdigit(num) || isalpha(num)){
        printf("Expected a number!\n");
        exit(0);
    }
    else if (choice == 'e'){
        printf("Your choice '%c' was not on the list!\n",choice);
        printf("Please try again.\n");
        exit(0);
    }
    else {
        printf("-------------\t A problem has occured... \t-------------\n");
        printf("-------------\t Exiting the program now...\t-------------\n");
        exit(0);
    }
    return 0;
}
//conversion from binary to other base 
long long binary_input(struct Convert *pCon){
    printf("Input in one line:\t binary number (01100100)\n");
    char *buff = pCon->buff;
    long long input = pCon->bin;
    int bit =0;
    while (scanf(" %s",buff)!=1)
    {
        int temp = atoi(buff);
        if (!isdigit(temp))
            error_option_input(pCon->choice,temp);
        else if (isalpha(temp))
            error_option_input(pCon->choice,temp);
    }
    int n = strlen(buff) -1;
    while (n >= 0){
        //shift 1 by number of bit to the left
		if (buff[n] == '1')
			input += (1 << (bit));
        //decrese the length and continue
		n = n - 1;
		// Count number of bits
		bit++;
	}
    pCon->bin = input;
    return input;
}
//called in case we need to convert decimal to binary
long long convert_dec_binary(struct Convert *pCon){
    char *buff = pCon->buff;
    long long input = pCon->dec;
    long long num = atoi(buff);
    int lenght = strlen(buff);
    int i = 0;
    num = (int)input;
    buff[i] = '\0';
    while (num>0){
        if(num %2 == 0){
            buff[i++] = '0';
            num /= 2;
        }
        else{
            buff[i++] = '1';
            num /= 2;
        }
    }
    //end array with '\0'
    buff[i] = '\0';
    //reverse buffer to display correct binary 1011 -> 1101
    strrev(buff);
    pCon->result = input;
    return input;
}
//conversion from decimal to other base
long long decimal_input(struct Convert *pCon){
    char *buff = pCon->buff;
    long long input = pCon->dec;
    long long num = atoi(buff);
    int i = 0;
    printf("Input in one line:\t Decimal number (12345)\n");
    while (scanf(" %lld",&input)!=1){
        //int temp = atoi(input);
        if (!isdigit(input))
            error_option_input(pCon->choice,input);
        else if (isalpha(input))
            error_option_input(pCon->choice,input);
    }
    //paste binary values to pCon.buffer
    pCon->dec =input;
    convert_dec_binary(pCon);
    pCon->result = input;
    return input;   
}
//conversion hexadecimal to other base
long long hexa_input(struct Convert *pCon){
    char *buff = pCon->buff;
    long long input = pCon->dec;
    long long hex = 0, res =0;
    printf("Input in one line:\t Hexadecimal number (11CD)\n");
    while (scanf(" %s",buff)!=1){
        int temp = atoi(buff);
        if (!isdigit(temp))
            error_option_input(pCon->choice,temp);
        else if (isalpha(temp))
            error_option_input(pCon->choice,temp);
    }
    int lenght = strlen(buff);
    char s_up[lenght];
    for (size_t i = 0; i < lenght; i++){
        //hex is digit from 0 - 15
        if (buff[i]== 'a'||buff[i]== 'b'||buff[i]== 'c'||buff[i]== 'd')
        s_up[i] = toupper((unsigned char)s_up[i]);

        else if ((buff[i]>='0')&& (buff[i]<='9'))
            hex = buff[i] - '0';
        else 
            hex = buff[i] - 'A' + 10;
        res *=16;
        res +=hex;
    }
    buff = s_up;
    //result assigned to struct  
    pCon->hex = res;
    pCon->dec = res;
    //printf("Number in struct: %lld,\n",pCon->dec);
    convert_dec_binary(pCon);
    return res;
}
//conversion from octal to other base 
long long octal_input(struct Convert *pCon){
    char *buff = pCon->buff;
    long long res =0;
    char *ptr;
    printf("Input in one line:\t Octal number (80)\n");
    while (scanf(" %s",buff)!=1){
        int temp = atoi(buff);
        if (!isdigit(temp))
            error_option_input(pCon->choice,temp);
        else if (isalpha(temp))
            error_option_input(pCon->choice,temp);
    }
    res = strtoul(buff,&ptr,8);
    pCon->oct = res;
    pCon->dec = res;
    convert_dec_binary(pCon);
    return res;
}
long long other_input(struct Convert *pCon){
    char *buff = pCon->buff;
    long long res = 0, base =0;
    char *ptr;
    printf("Input in one line:\t From which base you want to convert? (13)\n");
    scanf(" %d",&base);
    printf("Input in one line:\t Base '%d' number (12345)\n",base);
    while (scanf("%s",buff)!=1){
        int temp = atoi(buff);
        if (!isdigit(temp))
            error_option_input(pCon->choice,temp);
        else if (isalpha(temp))
            error_option_input(pCon->choice,temp);
    }
    res = strtoul(buff,&ptr,base);
    pCon->dec = res;
    pCon->other = res;
    convert_dec_binary(pCon);
    return res;
}
//decides which operation to run based on user's choice
long long decide_conversion(struct Convert *pCon){
    char choice = pCon->choice;
    long long result = pCon->result;
    tolower(choice);
    switch (choice){
    case 'a':
        printf("Your choice was: '%c' BINARY(2) to other base \n",choice);
        result =binary_input(pCon);
        break;
    case 'b':
        printf("Your choice was: '%c' DECIMAL(10) to other base \n",choice);
        result= decimal_input(pCon);
        break;
    case 'c':
        printf("Your choice was: '%c' HEXADECIMAL(16) to other base \n",choice);
        result =hexa_input(pCon);
        break;
    case 'd':
        printf("Your choice was: '%c' OCTAL(8) to other base \n",choice);
        result =octal_input(pCon);
        break;
    case 'f':
        printf("Your choice was '%c' to any Real number base\n",choice);
        result =other_input(pCon);
        break;
        break;
    default:
        printf("-------------\t A problem has occured...\t-------------\n");
        printf("-------------\t Exiting the program now...\t-------------\n");
        exit(0);
        break;
    }
    //assign result
    pCon->result = result;
    return result;
}
//check for invalid characters entered by user
int check_character_choice(char input, struct Convert *pCon){
    const char pch = input;
    tolower(pch);
    if (contains_special(pch)){
        input = 'e';
        error_option_input(input,pCon->bin);
    }
    if ( pch >= 'g' && pch <= 'z')
        error_option_input(pch,pCon->bin);
    else if(pch >= '0' && pch <= '9')
        error_option_input(pch,pCon->bin);
    //success characters is on the list
    //assign result to struct  
    pCon->choice = pch;
    return 1;
}
char choose_conversion(char op,struct Convert *pCon){
    while (scanf(" %c",&op)!=1){
            //assign output to Result
            tolower(op);
            if (op =='q')
                exit(0);
            if (op >='g' && op<='z')
                exit(0); 
            //check if is number or character
            if (isdigit((int)op))
                exit(0);
            else
                check_character_choice(op,pCon);
        }
    return tolower(op);
}
void display_result_binary(struct Convert *pCon){
    long long input = pCon->result;
    char *array = pCon->buff;
    printf("Binary: ");
    for (size_t i = 0; i <= strlen(array); i++)
        printf("%c",array[i]);
    printf("\n");
    printf("Decimal:  %lld\n", input);
    printf("Hexadecimal: [%X]\n",input);
    printf("Octal: %o\n",input);
}

void display_options_binhex(){
    printf("\nPlease CHOOSE your operation for Binary conversions:\n");
    printf("Type 'A' to convert from BINARY(2) to other base\n");
    printf("Type 'B' to convert from DECIMAL(10) to other base\n");
    printf("Type 'C' to convert from HEXADECIMAL(16) to other base\n");
    printf("Type 'D' to convert from OCTAL(8) to other base\n");
    printf("Type 'F' to convert from Decimal to any other base\n");
    printf("Press 'Q' to exit the program...\n");
} 
//main function called from main
int binary_calc(){
    //Ask user FROM and TO conversion...
    Convert sCon;Convert *pCon;
    pCon = &sCon;
    char ch;
    int flag = 1;
    //check option
    while (flag){
        display_options_binhex();
        pCon->choice = choose_conversion(sCon.choice,pCon);
        tolower(pCon->choice);
        //printf("Choice in struct: %c",pCon->choice);
        check_character_choice(sCon.choice,pCon);
        pCon->result = decide_conversion(pCon);
        display_result_binary(pCon);
        //printf("Number stored in struct: %lld\n",pCon->bin);
        printf("Calculate again? (Y/N)\n");
        //ask user
        flag = end_program(flag,ch);
    }//while flag
    //display_result()
    return 1;
}