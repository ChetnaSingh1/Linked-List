#include<stdio.h>
#include<stdlib.h>

int data;
void display();
struct node
{
	int info;
	struct node *next;
}*start=NULL;

void add_beg()				//to add at the beginning
{
	printf("\nEnter element to add ");
		scanf("%d",&data);
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=data;
	newnode->next=start;
	start=newnode;
	display();
}

void add_end()						//to add at the end
{
	printf("\nEnter element to add ");
		scanf("%d",&data);
	struct node *temp;
	struct node *newnode;
	newnode=(struct node*)malloc(sizeof(struct node));
	newnode->info=data;
	newnode->next=NULL;
	temp=start;
	while(temp->next!=NULL)
		{
			temp=temp->next;
		}
	temp->next=newnode;
	display();

}

void del_beg()						//to delete at the end
{
	struct node *temp;
	temp=start;
	start=start->next;
	free(temp);
	display();
}

void del_end()						//to delete from the beginning
{
	struct node *temp,*ptr;
	temp=start;
	while(temp->next->next!=NULL)
		temp=temp->next;
	ptr=temp->next;
	temp->next=NULL;
	free(ptr);
	display();
}

void display()			//to display
{
	struct node *temp;
	temp=start;
	if(start==NULL)
		printf("list is empty");
	else
		while(temp!=NULL)
			{
				printf("\ndata=%d\tpresent add=%u\tnext add=%u\n",temp->info,temp,temp->next);
				temp=temp->next;
			}
}

int main()
{
	int a;
	while(1)		//loop works infinitely
		{
			printf("\n1.Add at beginning\n2.Add at end\n3.Delete from beginning\n4.Delete from end\nEnter choice ");
				scanf("%d",&a);
			switch(a)
				{
					case 1:add_beg();
						break;
					case 2:add_end();
						break;
					case 3:del_beg();
						break;
					case 4:del_end();
						break;
				}
		}
}
