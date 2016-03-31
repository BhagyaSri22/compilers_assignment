#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//if finalState[i]=1, it is a final state
//int finalState[20]={0,0,0,0,1,0,1,0,0,0,0,0,1,0,0,1,0,1,0,1}; 
//q4=int
//q6=if
//q12=float
//q15=floor
//q17=digit
//q20=identifier

//scanner begin
char INPUT_BUFFER[200]; //storing the stream of characters that is read from file
int INPUT_BUFFER_PTR=0;
char s[20];int g=0;char new_char;//newly added by bhagya

void flush(void)
{
	//printf("Flushing now...IBP is %d\n", INPUT_BUFFER_PTR);	
	int i=0;
	
	while(i<200)
	{
		INPUT_BUFFER[i]='\0';
		i++;
	}
	INPUT_BUFFER_PTR=0;
}	
	
int isOperator(char input)
{
	if (input=='+'||input=='-'||input=='*'||input=='/'||input=='<'||input=='>'||input=='='||input=='('||input==')'||input==';'||input==',')
		return 1;
	else
		return 0;
}

int main(void)
{

	FILE *fpIn, *fpOut, *fpOut2;
	char *inputFileName = "input1.txt";
	char *outputFileName = "output.txt";

	fpOut=fopen("output.txt","w+");
	fpOut2=fopen("output_tok.txt","w+");
	//fclose(fpOut);
	
	fprintf(fpOut,"\nName: BHAGYA SRI\n");
	fprintf(fpOut,"Input file: input1.txt\n\n");
	fprintf(fpOut,"LINE\tTYPE\t\tLEXEME\n");
	fprintf(fpOut,"------------------------------\n");

	printf("Name: pro-b\n");
	printf("Input file: input1.txt\n");

	//fprintf(fpOut2,"\nTOKEN_TYPE\tLINE NUMBER\n");
	//fprintf(fpOut2,"-----------------------------\n");
	//char INPUT_BUFFER[200]; //storing the stream of characters that is read from file
	//int INPUT_BUFFER_PTR=0;
	char inputChar;
	fpIn=fopen("input1.txt", "r");
	
	int lineNo;
	int currentState=0;
	lineNo=1;
	while(!feof(fpIn))
	{
				
		inputChar=fgetc(fpIn);
		INPUT_BUFFER[INPUT_BUFFER_PTR]=inputChar;
		INPUT_BUFFER_PTR++;
		//printf("Current state is now: %d\n", currentState);
		//printf("\n IN SWITCH CASE NOW!\n");
		switch(currentState)
		{	
			case 0:switch(inputChar){

			       	case 'v':currentState=1;

			       	break;
			       	case 'i':currentState=4;
			       	break;
			       	case 'f':currentState=13;
			       	break;
			       	case 'r':currentState=24;
			       	break;
			       	case 'b':currentState=30;
			       	break;
			       	case 'w':currentState=34;
			       	break;
			       	case 't':currentState=39;
			       	break;
			       	case 'e':currentState=43;
			       	break;
			       	case ' ':
					case '\t':
					case '\n': if (inputChar=='\n')
							lineNo++;
					    currentState=0;
						INPUT_BUFFER_PTR=0;
						break;
					case '+':currentState=56;
							     break;

						case '-':currentState=57;
							     break;

						case '*': currentState=58;
							     break;

						case '/': currentState=59;
								  break;
						
						case '<': currentState=60;
								  break;
						
						case '>': currentState=61;
								  break;
						case '=': currentState=62;
								break;
						case '{': currentState=63;
								break;

						case '}': currentState=64;
								break;

						case '(': currentState=65;
								break;
		
						case ')': currentState=66;
								break;
						case ';': currentState=69;
								break;
						case ',':currentState=70;
								break;
						case '"':currentState=1234;
						        break;

						case '1':
						case '2':
						case '3':
						case '4':
						case '5':
						case '6':
						case '7':		
						case '8':
						case '9':
						case '0': currentState=75;
							  break;
				
	
			       	default:currentState=888;
			       	break;

			       }break;
	        case 1234:while(inputChar!='\"')
	        {
	        inputChar=fgetc(fpIn);
		INPUT_BUFFER[INPUT_BUFFER_PTR]=inputChar;
		INPUT_BUFFER_PTR++;
	        	

	        }
	      INPUT_BUFFER[INPUT_BUFFER_PTR]='\0';
				fprintf(fpOut,"%d\tSTR LIT\t\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"STR LIT \t%d\n",lineNo);
			//	INPUT_BUFFER_PTR=0;
				flush();
				currentState=0;
			//	fseek(fpIn,-1,SEEK_CUR);
	        			
	        			
				
				break;	
	        			 
			case 1:switch(inputChar)
					{
						case 'a': currentState=2;
							//puts("case1");
							  break;
						
						case '+':
						case '=':
						case '<':
						case '>':
						case '/':
						case '*':
						case '%':
						case ' ':
						case '\n': if (inputChar=='\n')
									lineNo++;
						case ';':
						case '\t': currentState=888;
								   fseek(fpIn,-1,SEEK_CUR);
									INPUT_BUFFER_PTR--;
								   break;
						
						default: if(isalnum(inputChar))
								 {
									currentState=888;
								 }
							else if (isOperator(inputChar)==1)	 
								{
									currentState=888;
									fseek(fpIn,-1,SEEK_CUR);
									
									INPUT_BUFFER_PTR--;
								}
							else
								 	currentState=999;
							     break;
								 
					}
				break;//break for case1
			case 2:switch(inputChar)
					{
						case 'r': currentState=3;

							  break;
						
						case '+':
						case '=':
						case '<':
						case '>':
						case '/':
						case '*':
						case '%':
						case ' ':
						case '\n': if (inputChar=='\n')
									lineNo++;
						case ';':
						case '\t': currentState=888;
								   fseek(fpIn,-1,SEEK_CUR);
									INPUT_BUFFER_PTR--;
								   break;
						
						default: if(isalnum(inputChar))
								 {
									currentState=888;
								 }
							else if (isOperator(inputChar)==1)	 
								{
									currentState=888;
									fseek(fpIn,-1,SEEK_CUR);
									
									INPUT_BUFFER_PTR--;
								}
							else
								 	currentState=999;
							     break;
								 
					}
				break;	//break of case2
			case 3:
				puts("this is case0 var1\n");
				INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tkeyword var\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"NUM\t\t%d\n",lineNo);
				puts("this is case0 var2\n");
				INPUT_BUFFER_PTR=0;
				flush();
				currentState=0;
				fseek(fpIn,-1,SEEK_CUR);

				break;	
			case 4:switch(inputChar)
					{
						case 'f': currentState=5;
							  break;
						case 'n':currentState=6;
							  break;
						case 'm':currentState=8;
							  break;
						case '+':
						case '=':
						case '<':
						case '>':
						case '/':
						case '*':
						case '%':
						case ' ':
						case '\n': if (inputChar=='\n')
									lineNo++;
						case ';':
						case '\t': currentState=888;
								   fseek(fpIn,-1,SEEK_CUR);
									INPUT_BUFFER_PTR--;
								   break;
						
						default: if(isalnum(inputChar))
								 {
									currentState=888;
								 }
							else if (isOperator(inputChar)==1)	 
								{
									currentState=888;
									fseek(fpIn,-1,SEEK_CUR);
									
									INPUT_BUFFER_PTR--;
								}
							else
								 	currentState=999;
							     break;
								 
					}
				break;//break for case4
			
			case 5:
			INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tkeyword if\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"NUM\t\t%d\n",lineNo);
				INPUT_BUFFER_PTR=0;
				flush();
				currentState=0;
				fseek(fpIn,-1,SEEK_CUR);
				break;	
			case 6:switch(inputChar)
			{
				case 't':currentState=7;
					break;
					case '+':
					case '=':
					case '<':
					case '>':
					case '/':
					case '*':
					case '%':
					case ' ':
					case '\n': if (inputChar=='\n')
								lineNo++;
					case ';':
					case '\t': currentState=888;
							   fseek(fpIn,-1,SEEK_CUR);
								INPUT_BUFFER_PTR--;
							   break;
					
					default: if(isalnum(inputChar))
							 {
								currentState=888;
							 }
						else if (isOperator(inputChar)==1)	 
							{
									currentState=888;
									fseek(fpIn,-1,SEEK_CUR);
									
									INPUT_BUFFER_PTR--;
								}
							else
								 	currentState=999;
							     break;
								 
					}
				break;//break for case6
			case 7:
			INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tkeyword int\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"NUM\t\t%d\n",lineNo);
				INPUT_BUFFER_PTR=0;
				flush();
				currentState=0;
				fseek(fpIn,-1,SEEK_CUR);
				break;	
			case 8:switch(inputChar)
			{
				case 'p':currentState=9;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 8
			case 9:switch(inputChar)
			{
				case 'o':currentState=10;
				break;				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 9
			case 10:switch(inputChar)
			{
				case 'r':currentState=11;
				break;
								case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 10
			case 11:switch(inputChar)
			{
				case 't':currentState=12;
				break;
								case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 11
			case 12:
			INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tkeyword import\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"NUM\t\t%d\n",lineNo);
				INPUT_BUFFER_PTR=0;
				flush();
				currentState=0;
				fseek(fpIn,-1,SEEK_CUR);
				break;	
			case 13:switch(inputChar)
			{
				case 'a':currentState=14;
				break;
								case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 13
			case 14:switch(inputChar)
			{
				case 'l':currentState=15;
				break;
								case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 14
			case 15:switch(inputChar)
			{
				case 's':currentState=16;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 15
			case 16:switch(inputChar)
			{
				case 'e':currentState=17;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 16
			case 17:
			INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tkeyword false\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"NUM\t\t%d\n",lineNo);
				INPUT_BUFFER_PTR=0;
				flush();
				currentState=0;
				fseek(fpIn,-1,SEEK_CUR);
				break;	
			case 18:switch(inputChar)
			{
				case 'o':currentState=19;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 18
			case 19:switch(inputChar)
			{
				case 'a':currentState=20;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 19
			case 20:switch(inputChar)
			{
				case 't':currentState=21;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 20
			case 21://end case
			INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tkeyword float %s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"NUM\t\t%d\n",lineNo);
				INPUT_BUFFER_PTR=0;
				flush();
				currentState=0;
				fseek(fpIn,-1,SEEK_CUR);
				break;	
			case 22:switch(inputChar)
			{
				case 'r':currentState=23;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 22
			case 23://end case
			INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tkeyword for\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"NUM\t\t%d\n",lineNo);
				INPUT_BUFFER_PTR=0;
				flush();
				currentState=0;
				fseek(fpIn,-1,SEEK_CUR);
				break;	
			case 24:switch(inputChar)
			{
				case 'e':currentState=25;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 24
			case 25:switch(inputChar)
			{
				case 't':currentState= 26;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 25
			case 26:switch(inputChar)
			{
				case 'u':currentState=27;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 26
			case 27:switch(inputChar)
			{
				case 'r':currentState=28;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 27
			case 28:switch(inputChar)
			{
				case 'n':currentState=29;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 28
			case 29://end case
			INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tkeyword return\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"NUM\t\t%d\n",lineNo);
				INPUT_BUFFER_PTR=0;
				flush();
				currentState=0;
				fseek(fpIn,-1,SEEK_CUR);
				break;	
			case 30:switch(inputChar)
			{
				case 'o':currentState=31;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 30
			case 31:switch(inputChar)
			{
				case 'o':currentState= 32;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 31
			case 32:switch(inputChar)
			{
				case 'l':currentState=33;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 32
			case 33://end case
			INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tkeyword bool\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"NUM\t\t%d\n",lineNo);
				INPUT_BUFFER_PTR=0;
				flush();
				currentState=0;
				fseek(fpIn,-1,SEEK_CUR);
				break;	
			case 34:switch(inputChar)
			{
				case 'h':currentState=35;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 34
			case 35:switch(inputChar)
			{
				case 'i':currentState=36;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 35
			case 36:switch(inputChar)
			{
				case 'l':currentState=37;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 36
			case 37:switch(inputChar)
			{
				case 'e':currentState=38;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 37
			case 38://end case
			INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tkeyword while\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"NUM\t\t%d\n",lineNo);
				INPUT_BUFFER_PTR=0;
				flush();
				currentState=0;
				fseek(fpIn,-1,SEEK_CUR);
				break;	
			case 39:switch(inputChar)
			{
				case 'r':currentState=40;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 39
			case 40:switch(inputChar)
			{
				case 'u':currentState= 41;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 40
			case 41:switch(inputChar)
			{
				case 'e':currentState= 42;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 41
			case 42://end case
			INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tkeyword true\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"NUM\t\t%d\n",lineNo);
				INPUT_BUFFER_PTR=0;
				flush();
				currentState=0;
				fseek(fpIn,-1,SEEK_CUR);
				break;	
			case 43:switch(inputChar)
			{
				case 'l':currentState=44;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 43
			case 44:switch(inputChar)
			{
				case 's':currentState=45;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 44
			case 45:switch(inputChar)
			{
				case 'e':currentState=46;
						break;
				case '+':
				case '=':
				case '<':
				case '>':
				case '/':
				case '*':
				case '%':
				case ' ':
				case '\n': if (inputChar=='\n')
							lineNo++;
				case ';':
				case '\t': currentState=888;
						   fseek(fpIn,-1,SEEK_CUR);
							INPUT_BUFFER_PTR--;
						   break;
				
				default: if(isalnum(inputChar))
						 {
							currentState=888;
						 }
					else if (isOperator(inputChar)==1)	 
						{
							currentState=888;
							fseek(fpIn,-1,SEEK_CUR);
							
							INPUT_BUFFER_PTR--;
						}
					else
						 	currentState=999;
					     break;
						 
			}break;//break for case 45
			case 46://end case
			INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tkeyword else\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"NUM\t\t%d\n",lineNo);
				INPUT_BUFFER_PTR=0;
				flush();
				currentState=0;
				fseek(fpIn,-1,SEEK_CUR);
				break;
			case 56:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tTK_KEY_PLUS\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"PLUS\t\t%d\n",lineNo);					
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;	
				break;

			case 57:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tTK_KEY_MINUS\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"MINUS\t\t%d\n",lineNo);				
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;
				break;
	
			case 58:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tTK_KEY_MULT\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"MULT\t\t%d\n",lineNo);				
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;	
				break;

			case 59:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tTK_KEY_DIV\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"DIV\t\t%d\n",lineNo);					
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;	
				break;

			case 60:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tTK_KEY_LT\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"LT\t\t%d\n",lineNo);				
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;
				break;

			case 61:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
			fprintf(fpOut,"%d\tTK_KEY_GT\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"GT\t\t%d\n",lineNo);					
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;	
				break;

			case 62:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tTK_KEY_EQ\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"EQ\t\t%d\n",lineNo);					
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;
				break;

			case 63://printf("%s%d",INPUT_BUFFER,INPUT_BUFFER_PTR);
				INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
			fprintf(fpOut,"%d\tTK_KEY_OBRACE\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"OPC\t\t%d\n",lineNo);					
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;
				break;

			case 64:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
			fprintf(fpOut,"%d\tTK_KEY_CBRACE\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"CLC\t\t%d\n",lineNo);			
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;
				break;

			case 65:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tTK_KEY_OCBRAC\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"OPR\t\t%d\n",lineNo);					
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;			
				break;

			case 66:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tTK_KEY_CCBRAC\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"CLR\t\t%d\n",lineNo);					
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;
				break;

			case 67:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tTK_KEY_SQ\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"%s\n",INPUT_BUFFER);					
				fseek(fpIn,-1,SEEK_CUR);
				flush();		
				currentState=0;
				break;

			case 68:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tTK_KEY_DQ\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"%s\n",INPUT_BUFFER);				
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;						 
				break;

			case 69:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tTK_KEY_SEMI\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"SEMI\t\t%d\n",lineNo);
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;						 
				break;
			//write case 48 and 49
			
			case 70:INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
				fprintf(fpOut,"%d\tTK_KEY_COMA\t%s\n",lineNo,INPUT_BUFFER);
				fprintf(fpOut2,"COMA\t\t%d\n",lineNo);
				fseek(fpIn,-1,SEEK_CUR);
				flush();
				currentState=0;						 
				break;

			case 888: switch(inputChar)
				  {
				 	case '+':
					case '=':
					case '<':
					case '>':
					case '-':	
					case '/':
					case '*':
					case '%':
					case ' ':
					case '\n': if (inputChar=='\n')
									lineNo++;
					case ')':
					case '(':
					case '{':
					case '}':
					case '\'':
					case '"':

					//INPUT_BUFFER_PTR=0;
					/*
					while(1)
					{
						new_char=fgetc(fpIn);
						if(new_char=='\n')lineNo++;
						else if(new_char=='\"')break;
						else {fprintf(fpOut,"%c",new_char);}
					//INPUT_BUFFER[INPUT_BUFFER_PTR]=new_char;
					//INPUT_BUFFER_PTR++;
					}
					
					//INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
					//fprintf(fpOut,"%d\tSTR LITERAL\t%s\n",lineNo,INPUT_BUFFER);
					currentState=0;
						  		flush();
					          	INPUT_BUFFER_PTR = 0;
							fseek(fpIn,-1,SEEK_CUR);
					break;
					*/
					case ';':
					case ',':
					case '\t':  INPUT_BUFFER[INPUT_BUFFER_PTR-1]='\0';
								fprintf(fpOut,"%d\tIDENTIFIER\t%s\n",lineNo,INPUT_BUFFER);
								fprintf(fpOut2,"ID\t\t%d\n",lineNo);
				 	        	currentState=0;
						  		flush();
					          	INPUT_BUFFER_PTR = 0;
							fseek(fpIn,-1,SEEK_CUR);
				                  break;

				        default: if(isalnum(inputChar))
						    currentState=888;
						 break;
				  }
					break;
				case 75:
				switch(inputChar)
				  {
						case '1':
						case '2':
						case '3':
						case '4':
						case '5':
						case '6':
						case '7':		
						case '8':
						case '9':
						case '0': currentState=75;
							  break;
					
					case '+':
				        case '-':
					case '*':
					case '/':
					case '>':
					case '<':
					case '=': 
					case ' ':
					case ')':
					case '(':
					case ',':
					case ';': fseek(fpIn,-1,SEEK_CUR);
						  currentState=444;
						  break;
					
					default: if(isalpha(inputChar))
						 currentState=888;
				
               				 break;				  
				  }
				break;

			}//end of switch

	//puts("hytrf\n");
	}//end big while
}//end main
