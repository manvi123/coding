#include <stdio.h>
#include <malloc.h>	
struct node
{
	int vertex;
	struct node *next;
};
typedef struct node* NODE;

void init(NODE head[], int n)
{
	int i=1;
	for(i=1;i<n;i++)
	{
		head[i] = NULL;
	}
}
NODE getnode()
{
	NODE ptr;
	ptr= (NODE)malloc(sizeof(struct node));
	ptr->vertex = 0;
	ptr->next = NULL;
	return ptr;
}

void create(NODE head[],int n)
{
	int stop = 0;
	int v1,v2=0;
	NODE ptr1,ptr2;
	printf("if you want to stop press 1 else press 0 after entering the edges\n");
	while(stop!=1)
	{
		printf("Enter the edges");
		scanf("%d %d",&v1,&v2);
		ptr1 = getnode();
		ptr1->vertex = v2;
		ptr2 = head[v1];
		if(ptr2 == NULL)
		{
			head[v1] = ptr1;
		}
		else
		{
			while(ptr2->next!= NULL)
			{
				ptr2 = ptr2->next;
			}
			ptr2->next = ptr1;
		}


		scanf("%d",&stop);
	}
}
void display(NODE head[],int n,int start)
{
	NODE ptr;
	int i = start;
	ptr = head[start];
	for(i= start;i<n;i++)
	{
		ptr = head[i];
		printf("\nhead[%i]",i);
		while(ptr!= NULL)
		{
			printf("->%d",ptr->vertex);
			ptr = ptr->next;
		}
	}
}

void main()
{
	int n,i;
	int start =1;
	printf("number of nodes");
	scanf("%d",&n);
	NODE head[10];
	init(head,n);
	create(head,n);
	display(head,n,start);
}