#include<stdio.h>
#include<stdlib.h>
struct node{
	int expo;
	int coeff;
	struct node *next;
}*head1=NULL,*head2=NULL,*head3=NULL;

struct node* polyAddition();
struct node* createPoly(struct node *temp,int n);
void displayPoly(struct node *head);

int main(){
	int n1,n2;
	struct node *temp1,*temp2,*temp3;
	printf("\nHOW MANY ITEMS IN FIRST POLYNOMIAL: ");
	scanf("%d",&n1);
	head1=createPoly(head1,n1);
	temp1=head1;
	printf("FIRST POLYNOMIAL:\n");
	while(temp1 != NULL){
		printf("\t%dx^%d\t",temp1->coeff,temp1->expo);
		if(temp1->next != NULL)
		{
			printf("+");
		}	
		temp1=temp1 -> next;	
	}	
	printf("\nHOW MANY ITEMS IN SECOND POLYNOMIAL: ");
	scanf("%d",&n2);
	head2=createPoly(head2,n2);
	temp2=head2;
	printf("SECOND POLYNOMIAL:\n");
	while(temp2 != NULL){
		printf("\t%dx^%d\t",temp2->coeff,temp2->expo);
		if(temp2->next != NULL)
		{
			printf("+");
		}	
		temp2=temp2 -> next;
	}
	printf("\n");	
	head3=polyAddition();
	temp3=head3;
	printf("RESULTANT POLYNOMIAL:\n");
	while(temp3 != NULL){
		printf("\t%dx^%d\t",temp3->coeff,temp3->expo);
		if(temp3->next != NULL)
		{
			printf("+");
		}	
		temp3=temp3 -> next;	
	}
	
	
}

struct node* createPoly(struct node *head,int n){
	struct node *temp,*newnode;
	int i;
	head=NULL;
	for(i=0;i<n;i++){
		newnode=(struct node*)malloc(sizeof(struct node));
		printf("ENTER BLOCK %d: \n",i+1);
		printf("ENTER EXPONENT: ");
		scanf("%d",&newnode->expo);
		printf("ENTER COEFFICENT:");
		scanf("%d",&newnode->coeff);
		if(head==NULL){
			head=newnode;
			temp=head;
		}
		else{
			newnode->next=NULL;
			temp->next=newnode;
			temp=temp->next;
		}	
	}
	return head;
}

void dispalyPoly(struct node *head){
	struct node *temp;
	temp=head;
	while(temp != NULL){
		printf("%dx^%d",temp->coeff,temp->expo);
		if(temp->next != NULL){
			printf("+");
		}
		temp=temp->next;
	}
}	

struct node* polyAddition(){
	struct node *temp1=head1,*temp2=head2,*newnode;
	struct node *temp3=NULL;
	head3=NULL;
	while(temp1 != NULL && temp2 != NULL){
		
		newnode=(struct node*)malloc(sizeof(struct node));
		if(temp1->expo == temp2->expo){
			newnode->expo=temp1->expo;
			newnode->coeff=temp1->coeff+temp2->coeff;
			temp1=temp1->next;
			temp2=temp2->next;
		}
		else if(temp1->expo > temp2->expo){
			newnode->expo=temp1->expo;
			newnode->coeff=temp1->coeff;
			temp1=temp1->next;
		}
		else{
			
			newnode->expo=temp2->expo;
			newnode->coeff=temp2->coeff;
			temp2=temp2->next;
		}
		
		if(head3==NULL){
			head3=newnode;
			temp3=head3;
		}
		else{
			newnode->next=NULL;
			temp3->next=newnode;
			temp3=newnode;
		}		
			
	}
	while(temp1 != NULL){
			newnode=(struct node*)malloc(sizeof(struct node));	
			newnode->expo=temp1->expo;
			newnode->coeff=temp1->coeff;
			if(head3==NULL){
				head3=newnode;
				temp3=head3;
			}
			else{
				newnode->next=NULL;
				temp3->next=newnode;
				temp3=temp3->next;
			}
			temp1=temp1->next;
	}
	while(temp2 != NULL){
				
			temp3->expo=temp2->expo;
			temp3->coeff=temp2->coeff;
			newnode=(struct node*)malloc(sizeof(struct node));
			if(head3==NULL){
				head3=newnode;
				temp3=head3;
			}
			else{
				newnode->next=NULL;
				temp3->next=newnode;
				temp3=temp3->next;
			}
			temp2=temp2->next;
	}
	return head3;
}	
			


































		
		
			
