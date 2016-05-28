#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int main(){
    char input[200];
    
  system("gcc -o lex lexer.c");
   system("./lex");
    
    
    /**
    FILE* fin = NULL;
    fin = fopen("output.txt","r");
    
    char temp_char;
    temp_char = fgetc(fin);
    int i = 0;
    while(temp_char != EOF)
    {
        if (temp_char != '\n')
        {
            input[i] = temp_char;
            i++;
            temp_char = fgetc(fin);
        }else{
            input[i] = '\0';
            
            printf("%s\n",input);
            i = 0;
            temp_char = fgetc(fin);
        }
    }
    input[i] = '\0';
    printf("%s\n",input );
    fclose(fin);
    
    
    
    **/
    
    FILE* fin = NULL;
    fin = fopen("output_for_parser.txt","r");
    
    char temp_char;
    temp_char = fgetc(fin);
    int i = 0;
    while(temp_char != EOF)
    {
        if (temp_char != '\n')
        {
            input[i] = temp_char;
            i++;
            temp_char = fgetc(fin);
        }else{
            input[i] = '\0';
            
            printf("%s\n",input);
            i = 0;
            temp_char = fgetc(fin);
        }
    }
    input[i] = '\0';
    printf("%s\n",input );
    fclose(fin);
    
    
    
    
    
    // aaaa
    //char input_string[30] = "(rcc)(rcc)$";
    char input_string[200];
    int pp = 0;
    while (input[pp] != '\0') {
        input_string[pp] = input[pp];
        pp++;
    }
    input_string[pp] = '$';
    input_string[pp+1]='\0';
    //printf("%s",input_string);
    char stack_string[400] = "P$";
    char rules[9][10][30] = { "NT", "$","i","n","r","w","f","o","e","v",
                 "P", "Error","TP","Error","Error","TP","TP","Error","Error","TP",
                 "T", "Error","H","Error","Error","A","W","Error","Error","D",
                 "D", "Error","Error","Error","Error","Error","Error","Error","Error","viei",
                 "H", "Error","ieioi","Error","Error","Error","Error","Error","Error","Error",
                 "W", "Error","Error","Error","Error","Error","fBT","Error","Error","Error",
                 "A", "Error","Error","Error","Error","wBT","Error","Error","Error","Error",
                 "B", "Error","irX","Error","Error","Error","Error","Error","Error","Error",
                 "X", "Error","i","n","Error","Error","Error","Error","Error","Error"};
    char temp[2];
    temp[0] = stack_string[0];
    temp[1] = '\0';
    char temp1[2];
    temp1[0] = input_string[0];
    temp1[1] = '\0';
    int stack_pointer = 0;
    int input_pointer = 0;
   // printf("\n%s\n",rules[0][9]);
    int hh = 5;
    while (1) {
        
        int ll = stack_pointer;
        printf("Stack = ");
        while (stack_string[ll] != '\0') {
            printf("%c",stack_string[ll]);
            ll++;
        }
        printf("    ");
        
        ll = input_pointer;
        printf("Input = ");
        while (input_string[ll] != '\0') {
            printf("%c",input_string[ll]);
            ll++;
        }
        printf("\n");
        
        
        
        
        temp[0] = stack_string[stack_pointer];
        temp1[0] = input_string[input_pointer];
      if (temp[0] == '$' && temp1[0] == '$') {
            printf("String is valid\n");
            break;
        }else if( temp[0] == '$' && temp1[0] != '$'){
            printf("String is not valid\n");
            break; 
        }
	     else if( temp[0] == 'P' && temp1[0] == '$'){
	          printf("String is valid\n");
		       break;
	     }
        int i = 0;
        for (i = 1; i<10; i++) {
           
            if (strcmp(temp1,rules[0][i]) == 0) {
                break;
            }
        }
        int j = 0;
        for (j = 1; j<9; j++) {
            if (strcmp(temp,rules[j][0]) == 0) {
                break;
            }
        }
        // printf("%s\n",rules[j-1][0]);
          // printf("%s\n",temp);
        //printf("i == %d  j == %d\n", i, j);
        if ((i == 10) || (j == 9)) {
            printf("String is not valid %d %d\n",i,j);
            break;
        }
        //printf("rule = %s",rules[j][i]);
        char temp3[20];
        int len = sizeof(rules[j][i]);
        int k = 0;
        for (k = 0; k<len; k++) {
            temp3[k] = rules[j][i][k];
        }
        temp3[k] = '\0';
        //printf("temp3 = %s\n",temp3);
        if (strcmp(temp3,"Error") == 0) {
            printf("String is not valid\n");
            break;
        }
        char front_end[20];
        char back_end[20];
        //printf("sp = %d\n",stack_pointer);
        
        for (k = 0; k<stack_pointer; k++) {
            //printf("Inside for\n");
            //printf("%c\n",front_end[k]);
            //printf("%c\n",stack_string[k]);
            front_end[k] = stack_string[k];
            //printf("%c\n",front_end[k]);
            //printf("%c\n",stack_string[k]);
        }
        //printf("k = %d\n",k);
        //printf("%c\n",front_end[0]);
        front_end[k] = '\0';
        
        int p = 0;
        for (k = stack_pointer+1; k<strlen(stack_string); k++) {
            back_end[p] = stack_string[k];
            p++;
        }
        back_end[p] = '\0';
        //printf("Stack String = %s\n",stack_string);
        //printf("front end = %s\n",front_end);
        //printf("temp3 = %s\n",temp3);
        //printf("backend = %s\n",back_end);
        p = 0;
        //printf("size = %d\n",sizeof(front_end));
        /**
        for (k = 0; k<sizeof(front_end); k++) {
            stack_string[p] = front_end[k];
            p++;
        }
         **/
        k = 0;
        while (front_end[k] != '\0') {
            stack_string[p] = front_end[k];
            k++;
            p++;
        }
        /**
        for (k = 0; k<sizeof(temp3); k++) {
            printf("%c\n",stack_string[p]);
            stack_string[p] = temp3[k];
            printf("%c\n",stack_string[p]);
            p++;
        }
         **/
        k = 0;
        while (temp3[k] != '\0') {
            stack_string[p] = temp3[k];
            k++;
            p++;
        }
        /**
        for (k = 0; k<sizeof(back_end); k++) {
            stack_string[p] = back_end[k];
            p++;
        }
        **/
        //printf("back = %c\n",back_end[0]);
        k = 0;
        while (back_end[k] != '\0') {
            stack_string[p] = back_end[k];
            k++;
            p++;
        }
        stack_string[p] = '\0';
        
        
        int stack_pointer_1 = stack_pointer;
        int input_pointer_1 = input_pointer;
        
        
        while (stack_string[stack_pointer] == input_string[input_pointer]) {
            if (stack_string[stack_pointer] == '$') {
                break;
            }else{
                stack_pointer++;
                input_pointer++;
            }
        }
        if (stack_pointer_1 != stack_pointer) {
            ll = stack_pointer_1;
            printf("Stack = ");
            while (stack_string[ll] != '\0') {
                printf("%c",stack_string[ll]);
                ll++;
            }
            printf("    ");
            
            ll = input_pointer_1;
            printf("Input = ");
            while (input_string[ll] != '\0') {
                printf("%c",input_string[ll]);
                ll++;
            }
            printf("\n");
            
        }
        //printf("Stck pointer = %d\n",stack_pointer);
        //printf("INput Pointer = %d\n",input_pointer);
        //break;
    }

    return 0;
}
