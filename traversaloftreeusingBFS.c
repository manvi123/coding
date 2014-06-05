#include <stdio.h>
#include <stdlib.h>

#define MAX_Q_SIZE 20
struct node
{
	int data;
	struct node *left;
	struct node *right;
};



typedef struct node NODE;
NODE *root =NULL;
struct queue
{
	struct node *queuedata[MAX_Q_SIZE];
	int front;
	int rear;
};
typedef struct queue QUEUE;
struct node* insert(int data, struct node *root)
{
	struct node *temp = NULL;
	if(root == NULL)
	{
		printf("here");
		temp= (NODE*)malloc(sizeof(struct node));
		temp->data = data;
		temp->left = NULL;
		temp->right = NULL;
		return temp; 
	}
	else
	{
		printf("else" );
		temp = root;
		while(temp!= NULL)
		{
			if(data < temp->data)
			{
				printf("left");
				temp = temp->left;
			}
			else
			{
				printf("right");
				temp = temp->right;
			}
		}
		temp = (NODE*) malloc(sizeof(NODE));
		temp -> data = data;
		temp->left = NULL;
		temp->right = NULL;
		return root;
	}	
}

QUEUE * createqueue(QUEUE *queue)
{
	queue = (QUEUE *)malloc(sizeof(QUEUE));
	queue ->front = queue->rear = 0;
	return queue;
}

void insertqueue(struct node* tempptr,struct queue *temp)
{
	if(tempptr!= NULL)
	{
		temp->queuedata[temp->rear] = tempptr;
		temp->rear++;
	}
}

struct node* dequeue(struct queue *temp)
{
	struct node * node = temp->queuedata[(temp->front)]; 
	temp->front++;
	return node;
}


void traversaltree(NODE *temp)
{
	NODE *tempptr = temp;
	QUEUE *queue = NULL;
	if(temp == NULL)
	{
		printf("tree is empty");
	}
	else
	{
		queue = createqueue(queue);
		while(tempptr!= NULL)
		{
			printf("tree is %d \n", tempptr->data);
			if(tempptr->left!= NULL)
			{
				insertqueue(tempptr->left,queue);
			}
			if(tempptr->right!= NULL)
			{
				insertqueue(tempptr->right,queue);
			}
			tempptr = dequeue(queue);
		}
	}
}

struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}

int main()
{
	int i=0;
	int data;
	//struct node *temp = NULL;
	for(i =0;i<10;i++)
	{
		scanf("Enter the data =%d",&data);
		if(data!= 0)
		{
			root = insert(data,root);
		}
	}
	 
/*struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); */
  traversaltree(root);
}

