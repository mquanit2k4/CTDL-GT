//xoa het cac node le trong dslk don
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
struct node{
	int data;
	struct node *next;
};
typedef struct node node;
node *makenode(int x){
	node *newnode=(node*)malloc(sizeof(struct node));
	newnode->data=x;
	newnode->next=NULL;
	return newnode;
}
//them 1 node vao cuoi ds
void pushback(node **head,int x){
	node *newnode=makenode(x);
	if(*head == NULL){
		*head=newnode;
	}
	else{
		node *tmp=*head;
		while(tmp->next != NULL){
			tmp=tmp->next;
		}
		tmp->next=newnode;
	}
}
//xoa node co gia tri le
node * xoa(node * head){
	node *tmp = head;
	node *prev = NULL;
	while(tmp != NULL){
		if(tmp->data % 2 != 0){
			//xoa node o dau
			if(prev == NULL){
				head=tmp->next;
				free(tmp);
				tmp=head;
			}
			//xoa node o giua or cuoi
			else{
				prev->next=tmp->next;
				free(tmp);
				tmp=prev->next;
			}
		}
		//di chuyen qua node tiep theo
		else{
			prev=tmp;
			tmp=tmp->next;
		}
		
	}
	return head;
	
}
void in(node *head){
	while(head != NULL){
		printf("%d ",head->data);
		head=head->next;
	}
}
int main(){
	node *head=NULL;
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		pushback(&head,x);
	}
	head = xoa(head);
	in(head);
	return 0;
}
