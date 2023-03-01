#include<iostream>
using namespace std;

struct Node
{
	int data;
	struct Node *next;
	
	int toString()
	{
		return data;
	}
};
Node *head;
int cnt;


Node* createNode(int ele)
{
	Node *temp = new Node();
	temp->data = ele;
	temp->next = NULL;
	return temp;
}
void insertBegin(int ele)
{
	Node *temp = createNode(ele);
	temp->next = head;
	head = temp;
	cnt++;	
}

void insertEnd(int ele)
{
	Node *temp = createNode(ele);
	if(head == NULL)
		head = temp;
	else
	{
		Node *p;
		for(p=head ; p->next!=NULL ;p=p->next);		
		p->next = temp;				
	}	
	cnt++;	
}

void deleteBegin()
{
	if(head == NULL)
		cout<<"\n no ele in list \n";
	else
	{
		cout<<"\n Deleting  = "<<head->data<<endl;
		Node *temp = head;
		head = head->next;
		temp->data = 0;
		temp->next = NULL;
		delete temp;
		cnt--;
	}
}



void deleteEnd()
{
	if(head == NULL)
		cout<<"\n no ele in list \n";
	else
	{
		Node *cp = head,*pp=head;
		for(;cp->next!=NULL;pp=cp,cp=cp->next);
		if(pp==cp)
			head = NULL;
		else
			pp->next=NULL;
		
		cout<<"\n Deleting = "<<cp->data<<endl;
		cp->data = 0;
		cp->next = NULL;
		delete cp;
		cnt--;
	}
}



void deletePos(int pos)
{
	if(pos==1)
		deleteBegin();
	else if(pos==cnt)
		deleteEnd();
	else
	{
		Node *pp =head,*cp=head;
		for(int i=1;i<pos;pp=cp,cp=cp->next);
		
		pp->next = cp->next;
		
		cout<<"\n Deleting = "<<cp->data<<endl;
		cp->data = 0;
		cp->next = NULL;
		delete cp;
		cnt--;
		
	}
}
		



void insertPos(int pos,int ele)
{
	if(pos==1)
		insertBegin(ele);
	else if(pos==cnt+1)
		insertEnd(ele);
	else
	{
		Node *temp = createNode(ele);
		Node *p=head;
		for(int i=1;i<pos-1;p=p->next,i++);
		temp->next = p->next;
		p->next = temp;
		cnt++;
	}	
}


void display()
{
	if(head == NULL)
		cout<<"\n No elements in list \n";
	else
	{
		cout<<"\n List ele = \n";
		for(Node *p=head;p!=NULL;p=p->next)
		{
			cout<<p->data<<"-->";
		}
	}
}


Node* at(int pos)
{
	if(head==NULL)
		return NULL;
	else
	{
			Node *p=head;
			for(int i=1;i<pos;p=p->next,i++);
			
			return p;
			
	}
}

Node* max()
{
	Node *p=head,*maximum=head;
	while(p!=NULL)
	{
		if(p->data>maximum->data)
		{
			maximum=p;
		}
		p=p->next;
	}
	return maximum;	
}
Node* min()
{
	Node *p=head,*minimum=head;
	while(p!=NULL)
	{
		if(p->data<minimum->data)
		{
			minimum=p;
		}
		p=p->next;
	}
	return minimum;	
}
void sort(int start,int end)
{
	Node *p1=head,*p2=head,*temp,*min;
	int val;
	for(int i=1;i<start;p1=p1->next,i++); //p1=300
	for(int i=1;i<end;p2=p2->next,i++);   //p2=600
	while(p1!=p2)
	{
		min = p1;
		temp = p1->next;
		while(temp!=p2->next)
		{
			if(min->data > temp->data)
			{
				min = temp;
			}
			temp = temp->next;
		}
		
		val = p1->data;
		p1->data = min->data;
		min->data = val;
		p1=p1->next;
	}
	
}





