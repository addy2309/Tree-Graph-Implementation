#include <iostream>
using namespace std;

class list 
{
	public:
	int destination ;
	list * next ;
		
	list();
	
};

list :: list()
{
	next = NULL;
}
class Graph
{
		public:
		int index ;
		list * ptr ;
		Graph * next ;
		
		Graph();
		
}*head = NULL;

Graph :: Graph()
{
	ptr = NULL;
	next = NULL;
}

void create_node ( int orig )
{
	Graph * temp = new Graph ;
	temp->index = orig;
	
	if (head == NULL)
	 {
	 	head=temp;
	 }
	 else 
	 {
	 	Graph * start = head ;
	 	
	 	while(start->next != NULL)
	 	start = start -> next ;
	 	
	 	start->next = temp ;
	 	
	 }
	 
}

void create_link (int origin , int destination)
 {
 	Graph * temp = head ;
 	
 	while (temp != NULL)
 	{
 		if(temp->index ==origin)
 		{
 			list * node = new list ;
 			node->destination = destination;
 			
 			if(temp->ptr==NULL)
 			  temp->ptr=node;
 			else
 			 {
 			 	list * temp1=temp->ptr;
 			 	while(temp1->next!=NULL)
 			 		temp1=temp1->next;
 			 	temp1->next=node;
			 }
    	}
    	temp=temp->next;
	}
 }
 
void display ()
{
	Graph * temp = head ;
	
	while (temp != NULL)
	 {
	 	cout<<temp -> index ;
	 	
	 	list * trav = temp -> ptr ;
	 	
	 	while (trav != NULL)
	 	 {
	 	 	cout << " -> " <<trav -> destination;
			trav=trav->next; 
		 }
		 cout<<endl;
	 	temp = temp -> next ;
	 }
}

int main()
 {
 
 create_node (0);
 create_node (1);
 create_node (2);
 create_node (3);
 
 create_link (0,1);
 create_link (0,2);
 create_link (0,3);
 
 create_link (2,3);
 create_link (3,2);
 create_link (2,1);
 
 display();
 }

