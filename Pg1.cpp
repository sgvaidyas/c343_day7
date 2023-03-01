#include<iostream>
#include "singlylinked.h"

int main()
{
	head = NULL;
	cnt =0;
	int ch,ele,pos,start,end;
	Node *temp;
	do
	{
		cout<<"\n1 InsertBegin";
		cout<<"\n2 InsertEnd";
		cout<<"\n3 InsertPos";
		cout<<"\n4 DeleteBegin";
		cout<<"\n5 DeleteEnd";
		cout<<"\n6 DeletePos";
		cout<<"\n7 Display";
		cout<<"\n8 At";
		cout<<"\n9 Max";
		cout<<"\n10 Min";
		cout<<"\n11 Sort (Conditional)";
		cout<<"\n Enter choice = ";
		cin>>ch;
		if(ch>=1 && ch<=3)
		{
			cout<<"\n Enter the ele = ";
			cin>>ele;
		}
		switch(ch)
		{
			case 1:insertBegin(ele);
			       break;
			case 2:insertEnd(ele);
			       break;
			case 3: cout<<"\n Enter the pos = ";
				    cin>>pos;
					if(pos>=1 && pos<=cnt+1)
						insertPos(pos,ele);
					else
						cout<<"\n Invalid position \n";
			       break;
			case 4:deleteBegin();
			       break;
			case 5:deleteEnd();
			       break;
			case 6: cout<<"\n Enter the pos = ";
				    cin>>pos;
					if(pos>=1 && pos<=cnt)
						deletePos(pos);
					else
						cout<<"\n Invalid position \n";
			       break;
			case 7:display();break;
			case 8:cout<<"\n Enter the pos = ";
				    cin>>pos;
					if(pos>=1 && pos<=cnt)
						cout<<at(pos)->toString();
					else
						cout<<"\n Invalid position \n";
			       break;
			case 9:temp = max();
					if(temp)
						cout<<"MAX = "<<temp->toString()<<endl;
					else
						cout<<"\n list is empty \n";
					break;
			case 10:temp = min();
					if(temp)
						cout<<"MIN = "<<temp->toString()<<endl;
					else
						cout<<"\n list is empty \n";
					break;
			case 11:cout<<"\n Enter the start pos = ";
				    cin>>start;
				    cout<<"\n Enter the end pos = ";
				    cin>>end;
				    if(start<1 || end>cnt)
				    	cout<<"\n Invalid start and end\n";
				    else
				    	sort(start,end);
				    break;
			case 12:break;
			default:cout<<"\n Invalid choice \n";
		}
	}while(ch!=12);
	
}
