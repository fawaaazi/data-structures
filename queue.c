#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;

}*front=NULL,*rear=NULL;

void dequeue();
void enqueue();
void display();

int main(){
	int choice,flag=0;
	while(flag==0){
		printf("\n1.enqueue\n2.dequeue\n3.display\n4.exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				enqueue();
				display();
				break;
			case 2:
				dequeue();
				display();
				break;
			case 3:
				display();
				break;
			case 4:
				flag=1;
				break;
			default:
				printf("INVALID CHOICE");
		}
	}	
	
}

void enqueue(){
	int data;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	if(front==NULL){
		printf("ENTER DATA: ");
		scanf("%d",&data);
		newnode->data=data;
		newnode->next=front;
		front=newnode;
		rear=newnode;
	}
	else{	
		printf("ENTER DATA:  ");
		scanf("%d",&data);	
		newnode->data=data;
		rear->next=newnode;
		newnode->next=NULL;
		rear=newnode;
	}
}

void dequeue(){
	struct node *temp;
	if(rear==NULL){
		printf("QUEUE IS EMPTY\n");
	}
	else{
		temp=front;
		front=front->next;
		printf("DEQUEUED ELEMENT:%d\n",temp->data);
		free(temp);
	}
}

void display(){
	struct node *temp;
	temp=front;
	if(front==NULL ){
		printf("QUEUE IS EMPTY");
	}
	else{
		while(temp != NULL){
			printf("%d\t",temp->data);
			temp=temp->next;
		}	
		
	}
}
				
				
				
								
					
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
				
					
			
	
