#include<stdio.h>
#include<string.h>
#define size 15
int s[size];
int top=-1,d=0;
void push(int x);
int pop();


int main(){
	char ex[20],x;
	int i,l,a,b,c;
	printf("ENTER THE EXPRESSION:  ");
	scanf("%s",ex);
	l=strlen(ex);
	for(i=0;i<l;i++){
		x=ex[i];
		if(x=='+'){
			a=pop();
			b=pop();
			c=a+b;
			push(c);
		}
		else if(x=='-'){
			a=pop();
			b=pop();
			c=a-b;
			push(c);
		}
		else if(x=='*'){
			a=pop();
			b=pop();
			c=a*b;
			push(c);
		}
		else if(x=='/'){
			a=pop();
			b=pop();
			c=a/b;
			push(c);
		}
		else if(x=='^'){
			a=pop();
			b=pop();
			c=a^b;
			push(c);
		}
		else if(x=='%'){
			a=pop();
			b=pop();
			c=a%b;
			push(c);
		}
		else{
			push(x-'0');
		}
	}
	printf("RESULT:%d\n",s[top]);
}	
					

void push(int x){
	if(top==size-1){
		printf("\nStack is Full\n");
	}	
	else{
		top++;
		s[top]=x;
	}
}
int pop(){
	int y;
	if(top==-1){
		
	}
	else{
		y=s[top];
		top--;
		return y;
	}
}

		
									
