//---------------------------------------------------------------------------

#include <stdio.h>

#include <stdlib.h>
#include <conio.h>
#pragma hdrstop

#include <tchar.h>
#pragma argsused
//---------------------------------------------------------------------------


// ���� ���������� ������
typedef struct
{
	int data;               // ������������� ������
	struct Node* next;      // ��������� �� ��������� ����
} Node;

Node *header = NULL;

// ��������������� ������� ��� �������� ������ ���� queue
struct Node* newNode(int item)
{
	// �������� ����� ���� � ����
	Node* node = (Node*)malloc(sizeof(Node));

	// ���������, ��������� �� queue (����). ����� ������� �������� �����
	// �������� � ������������ ����
	if (node != NULL)
	{
		// ������������� ������ � ���������� ���� � ���������� ��
		node->data = item;
		node->next = NULL;
		return node;
	}
	else {
		printf("\nHeap Overflow");
		exit(EXIT_FAILURE);
	}
}
//---------------------------------------------------------------------------

// ������� ��� ���������� �������� � queue
void addNode(int item,int position)        // ������� position 0 - to begin, -1 - to end, number to position
{
	Node *temp;
	int i;
	// �������� ����� ���� � ����
	Node* node = newNode(item);

	printf("Inserting %d\n", item);

	// ������ ������: queue �����
	if (header == NULL)
	{
		// �������������� ��������� �� ������ � ��������� ������� ��������� �����
		header = node;
	}
	else
	{
		if(position == 0)
		{
		   // �������� ������
			node->next = header;
			header = node;
		}
		if(position == -1)
		{
		  temp = header;
		  while(temp->next !=NULL)
		  {
			temp = temp->next;
		  }
		  temp->next = node;
		}
		if(position > 0)
		{
		   i = 1;
		   temp = header;
			while( i!=position )
			{
				temp = temp->next;
				if(temp == NULL)
				{
				  printf("No correct position\n");
				  return;
				}
				i++;
			}
			node->next = temp->next;
			temp->next = node;

		}


	}
}

//---------------------------------------------------------------------------
// ������� ��� �������� ��������� �������� �� �������
int deleteNode(int position)        // ������� � ������ �������
{
	Node* temp, *prev;
	int i;
	if (header == NULL)
	{
		printf("Queue is empty\n");
		return;
	};
	temp = header;


	if(position == 0)   // ������� ������ �������
	{
	  header = temp->next;
	  printf("Removing first element %d\n", temp->data);
	  free(temp);
	}

	if(position == -1 )  // ������� ��������� �������
	{
		while(temp->next !=NULL)
		{
			prev = temp;
			temp = temp->next;
		}
		printf("Removing last element %d\n", temp->data);
		free(temp->next);
		prev->next = NULL;
	}

	if(position > 0 )  // ������� ������� � ������ �������
	{
	   i = 0;
	   while( i!=position )
	   {
			prev = temp;
			temp = temp->next;
			if(temp == NULL)
			{
				printf("No correct position\n");
				return;
			}
			i++;
	   }
	   prev->next = temp->next;
	   printf("Removing %d in position %d\n", temp->data,position);
	   free(temp);
	}
}

//---------------------------------------------------------------------------
void search(int element)
{
   Node *temp;
   int i = 0;
   temp = header;
   if(temp == NULL)
   {
		printf("Queue is empty\n");
		return;
   }

   printf("Search element:%d ",element);
   while(temp != NULL)
   {
	  if(temp->data == element)
	  {
		 printf("find in position %d\n",i);
		 return;
	  }

	  temp = temp->next;
	  i++;
   }
   printf("Not find\n");
}

//---------------------------------------------------------------------------
void isEmpty()
{
   if (header == NULL)
   {
	 printf("Queue is empty\n");
   }
   else
   {
	 printf("Queue is not empty\n");
   }
}
//---------------------------------------------------------------------------
void display()
{
   Node *temp;
   temp = header;
   if(temp == NULL)
   {
		printf("Queue is empty\n");
		return;
   }

   printf("All elements: ");
   while(temp != NULL)
   {
	  printf("%d ",temp->data);
	  temp = temp->next;
   }
   printf("\n");
}


//---------------------------------------------------------------------------
void reverse()
{

   Node *curr, *next, *prev = NULL;

   if(header == NULL)
   {
		printf("Queue is empty\n");
		return;
   }

   printf("Reverse\n");

    curr = header;
	while(curr != NULL)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	header = prev;

}
//---------------------------------------------------------------------------
void clear()
{
	Node *temp,*temp2;
	temp = header;
	if(header == NULL)
	{
		printf("Queue is empty\n");
		return;
	}

	printf("Is clear: \n");
	while(temp != NULL)
	{
		temp2 = temp;
		temp = temp->next;

		free(temp2);

	}
	header = NULL;

}
//---------------------------------------------------------------------------
int _tmain(int argc, _TCHAR* argv[])
{
	isEmpty();

	addNode(1,0);
	addNode(2,0);
	addNode(3,0);
	addNode(4,-1);
	addNode(5,0);
	addNode(6,-1);

	addNode(11,3);
	addNode(22,1);

	display();

	search(5);
	search(11);
	search(6);
	search(33);


	reverse();
	display();


	deleteNode(0);
	display();

	deleteNode(3);
	display();

	deleteNode(-1);
	display();

	clear();
	display();


	_getch();
	return 0;
}
//---------------------------------------------------------------------------
