
#include<conio.h>
#include<iostream.h>
class NODE
{	public:
	int data;
	NODE *next,*prev;
};
class LIST
{
	NODE*start;
      public:
	LIST();
	void ADD_FIRST_52(int);
	void ADD_LAST_52(int);
	int DEL_FIRST_52();
	int DEL_LAST_52();
	void VIEW_ALL_52();
	void VIEW_REVERSE_52();
}
LIST::LIST()
{
	start=NULL;
}
void LIST::ADD_FIRST_52(int ele)
{
	//step
	NODE*NN=new NODE();
	//step2
	NN->data=ele;
	NN->next=NULL;
	NN->prev=NULL;
	if(start==NULL)
		start=NN;
	else
	{
		start->prev=NN;
		NN->next=start;
		start=NN;
	}
}
void LIST::ADD_LAST_52(int ele)
{
	NODE*ptr;
	//step1
	NODE*NN=new NODE();
	//step2
	NN->data=ele;
	NN->next=NULL;
	NN->prev=NULL;
	//step3
	if(start==NULL)
		start=NN;
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ptr->next=NN;
		NN->prev=ptr;
	}
}
int LIST::DEL_FIRST_52()
{
	int ele;
	if(start==NULL)
	{
		cout<<endl<<"list is empty";
		return NULL;
	}
	else
	{
		ele=start->data;
		start=start->next;
		if(start!=NULL)
			start->prev=NULL;
		return ele;
	}
}
int LIST::DEL_LAST_52()
{
	int ele;
	NODE*ptr,*ptr1;
	if(start==NULL)
	{
		cout<<endl<<"list is empty";
		return NULL;
	}
	else
	{
		ptr=start;
		//move up to last node
		while(ptr->next!=NULL)
			ptr=ptr->next;
		ele=ptr->data;
		if(ptr==start)
			start=NULL;
		else
		{
			//ptr=ptr->prev
			//ptr1->next=NULL;
			ptr->prev->next=NULL;
		}
		return ele;
	}

}
void LIST::VIEW_ALL_52()
{
	NODE*ptr;
	if(start==NULL)
		cout<<endl<<"List is empty" ;
	else
	{
		cout<<endl;
		ptr=start;
		while(ptr!=NULL)
		{
			cout<<" "<<ptr->data;
			ptr=ptr->next;
		}

	}
}
void LIST::VIEW_REVERSE_52()
{
	NODE*ptr;
	if(start==NULL)
		cout<<endl<<"List is empty" ;
	else
	{
		cout<<endl;
		ptr=start;
		while(ptr->next!=NULL)
		{
			cout<<" "<<ptr->data;
			ptr=ptr->prev;
		}

	}
}
void MENU()
{
	int ele,opt;
	LIST obj;
	do
	{
		cout<<"\n Select the option";
		cout<<"\n 1.ADD FIRST";
		cout<<"\n 2.ADD LAST";
		cout<<"\n 3.DELETE FIRST";
		cout<<"\n 4.DELETE LAST";
		cout<<"\n 5.VIEW ALL";
		cout<<"\n 6.VIEW REVERSE";
		cout<<"\n 7.EXIT";
		cout<<"\n Enter your choice";
		cin>>opt;
		switch(opt)
		{
			case 1:
				cout<<"\n Enter an ele to add at first";
				cin>>ele;
				obj.ADD_FIRST_52(ele);
				break;
			case 2:
				cout<<"\n Enter an ele to add at last";
				cin>>ele;
				obj.ADD_LAST_52(ele);
				break;
			case 3:
				ele=obj.DEL_FIRST_52();
				if(ele!=NULL)
					cout<<endl<<ele<<"\n Delete element";
				break;
			case 4:
				ele=obj.DEL_LAST_52();
				if(ele!=NULL)
					cout<<endl<<ele<<"\n Delete element";
				break;
			case 5:
				cout<<endl<<"\n the element in reversr order are";
				obj.VIEW_ALL_52();
				break;

			case 6:
				cout<<endl<<"\n the element in reversr order are";
				obj.VIEW_REVERSE_52();
				break;
			case 7:
				return;
			default:
				cout<<"\n Invalid choicee";
		}
	}while(1);
}
void main()
{
	clrscr();
	MENU();
	getch();

}




