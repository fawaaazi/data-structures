#include <stdio.h>
#include <stdlib.h>
struct bstnode{
	int data;
	struct bstnode *right;
	struct bstnode *left;
};
struct bstnode *root=NULL;
	

// Function prototypes
void insertnode(struct bstnode *atnode, struct bstnode *temp);
void preorder(struct bstnode *atnode);
void inorder(struct bstnode *atnode);
void postorder(struct bstnode *atnode);

int main() {
    int choice, k;
    struct bstnode *temp;

    printf("=====Binary Search Tree=====\n");
    
    do {
        printf("\nEnter your choice:\n");
        printf("1. Insert to BST\n");
        printf("2. Traversal\n");
        printf("0. Exit\n");

        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("\nCase 1\n");
                printf("Enter the key to be inserted: ");
                scanf("%d", &k);
                
                temp = (struct bstnode *)malloc(sizeof(struct bstnode));
                temp->data = k;
                temp->left = NULL;
                temp->right = NULL;
                
                insertnode(root,temp);
                break;
                
            case 2:
                printf("\nCase 2\n");
                printf("\n------Preorder traversal------\n");
                preorder(root);
                
                printf("\n------Inorder traversal------\n");
                inorder(root);
                
                printf("\n------Postorder traversal------\n");
                postorder(root);
                break;
                
            default:
                printf("\nWrong Choice\n");
        }
    } while (choice != 0);

    return 0;
}

void insertnode(struct bstnode *atnode, struct bstnode *temp){

	if(atnode == NULL){
		root=temp;
	}
	else{
		if(atnode->data >= temp->data){
			if(atnode->left == NULL){
				atnode->left=temp;
			}
			else{
				insertnode(atnode->left,temp);
			}
		}
		else{
			if(atnode->right == NULL){
				atnode->right=temp;
			}
			else{
				insertnode(atnode->right,temp);
			}
		}
	}						
						
}
	
		
void preorder(struct bstnode *atnode){
	if(atnode != NULL){
		printf("%d\t",atnode->data);
		preorder(atnode->left);
		preorder(atnode->right);
	}	
}

void inorder(struct bstnode *atnode){
	if(atnode != NULL){
		inorder(atnode->left);
		printf("%d\t",atnode->data);
		inorder(atnode->right);
	}	
}
void postorder(struct bstnode *atnode){
	if(atnode != NULL){
		postorder(atnode->left);
		postorder(atnode->right);
		printf("%d\t",atnode->data);
	}
}		
		
				

