#include<stdio.h>
#include<string.h>
#define size 15
char s[size],out[size];
int top=-1,d=0;
void push(char x);
char pop();
int pri(char x);

int main(){
	char ex[20],x;
	int i,l;
	printf("ENTER THE EXPRESSION:  ");
	scanf("%s",ex);
	l=strlen(ex);
	for(i=0;i<l;i++){
		if((ex[i] =='+' )||( ex[i] =='-' )||( ex[i] =='*' )||( ex[i] =='/' )||( ex[i] == '^' )||( ex[i] =='%')){
			x=ex[i];
				while( pri(s[top]) >= pri(ex[i]) ){
					out[d++]=pop();
				}
				push(x);
		}		
		else if( ex[i]== '(' ){
			push(ex[i]);
		}
		else if(ex[i] == ')'){
			while(s[top] != '(' ){
				x=pop();
				out[d++]=x;
			
			}
			pop();
			
		}
	
		else{
			out[d++]=ex[i];
		}
		
	}
	while(top !=-1){
		out[d++]=pop();
	}	
	out[d]='\0';
	printf("POST FIX EXPRESSION:%s\n",out);	
}	

void push(char x){
	if(top==size-1){
		printf("\nStack is Full\n");
	}	
	else{
		top++;
		s[top]=x;
	}
}
char pop(){
	char y;
	if(top==-1){
		
	}
	else{
		y=s[top];
		top--;
		return y;
	}
}

int pri(char x){
	if(x=='-' || x=='+'){
		return 1;
	}
	else if(x=='*' || x=='/'){
		return 2;
	}
	else if (x=='^' || x=='%'){
		return 3;
	}
	else{
		return 0;
	}	
}			
									
		
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
						
									
				
