#include <iostream>
#include <queue>
using namespace std;

class node
 {
 	int data ;
 	node * left ;
	node * right ;

	public :
		node();
		static node * insert ( node * , int );
		static node * createNode ( int );
		static void display ( node *);
		static int minimum ( node *);
		static int maximum ( node *);
		static int depth( node *);
		static void paths (node * , int * , int);
		static void mirror ( node *);
		static void lvlorder ( node *);
		static void linklist ( node * , node *& , node *&);
		static void lldisplay ( node *);
 };
 
void node :: lldisplay ( node * head )
 {
 	head->left->right = head ;
 	node * temp = head ;
 	do
 	 {
 	 	cout<<temp->data<<" ";
 	 	temp=temp->right;
		}while ( temp != head );
 }
 
void node :: linklist( node * root , node *& head , node *& temp )
 {
 	static int count;
 	
	if(root != NULL)
	 {
	 	linklist( root -> left , head ,temp );
	 	 count++;
	 	 
	 	 if(count == 1)
	 	  {
	 	  	head = root ;
	 	  	temp = head ;
			 }
			else
			 {
			 	root -> left = temp ;
			 	temp -> right = root ;
			 	temp = root ;
			 	head -> left = root ;
			 }
			 linklist( root -> right , head , temp );
	 }
 }

void node :: lvlorder ( node * head )
 {
 	queue <node *> store ;
 	
 	if(head !=NULL)
 	store.push(head);
 	
 	while(!store.empty())
 	 {
 	 	node * temp = store.front();
 	 	cout<<temp->data<<" ";
 	 	
 	 	if(temp -> left != NULL )
 	 	 store.push( temp->left );
 	 	 
 	 	if(temp -> right != NULL )
 	 	 store.push( temp->right );
 	 	 
		store.pop(); 
		}
 }

void node :: mirror ( node * head )
 {
 	if( head == NULL )
 	  return ;
 	  
 	node * temp ;
 	 mirror (head -> left );
 	 mirror (head -> right );
 	 
 	 temp = head->left ;
 	 head->left = head->right;
 	 head->right = temp;
 }

void node :: paths ( node * head , int *ar , int pos)
 {
 	if( head == NULL )
 	 return ;
 	 
 	ar[pos++]=head->data; 
 	
 	if( head->left == NULL && head->right == NULL)
 	 {
 	 	for(int i=0 ; i < pos ; i++)
 	 	 	cout<<ar[i]<<" ";
			 cout<<endl;
		}
	else
	 {
	 	paths ( head -> left , ar , pos );
  	paths ( head -> right, ar , pos);
	 }
 }

int node :: depth( node * head )
 {
 	if ( head == NULL )
 	 return 0 ;
 	 
 	int left = depth ( head -> left );
 	int right = depth ( head -> right );
 	
 	if( left > right )
 	 return left+1;
 	else
 	 return right+1;
 }

int node :: minimum ( node * head )
 {
 	if(head ->left == NULL)
 	 return head ->data;
 	 
 	minimum ( head ->left );
 }
 
int node :: maximum ( node * head )
 {
 	if(head ->right == NULL)
 	 return head ->data;
 	 
 	maximum ( head ->right );
 }

void node :: display ( node * head )
 {
 	if (head == NULL )
 	 return;
 	 
 	display(head->left);
	cout<<head->data<<"  "; 
 	display(head->right);
 	
 }

node * node :: createNode( int val )
  {
  	node * head = new node ;
  	head->data = val;
  	
  	return head;
	}

node * node :: insert ( node * head , int val )
	{
		if ( head == NULL )
		 	head = node :: createNode ( val );
		 
		 else if ( val > head->data)
		  head->right = insert ( head->right , val);
		 else
		  head->left = insert ( head-> left , val);
		 
		 return head;
	}

node :: node() 
 {
 	left = right = NULL;
 }

class tree
 {
 	node * root ;
 	
 	public :
 	tree();
	 void insert (int);
	 void display();
	 void minimum();
	 void maximum();
	 void depth();
	 void paths();
	 void mirror();
	 void lvlorder();
	 void linklist();
 };
 
void tree :: linklist ()
 {
 	cout<<"LinkList : Conversion Done \n";
 	node * link = NULL,* temp = NULL ;
 	
 	node :: linklist( root , link , temp);
 	node :: lldisplay( link );
 }
 
void tree :: lvlorder()
 {
 	cout<<"Level Or: ";
 	node :: lvlorder( root );
 	cout<<endl;
	} 
 
void tree :: mirror()
 {
 	cout<<"Mirror  : Complete";
 	node :: mirror ( root );
 	cout<<endl;
 }
 
void tree :: paths()
 {
 	int * ar = new int [100];
 	if(root == NULL )
 	 cout<<"ERROR TREE EMPTY\n";
 	
 	else
 	 {
 	 	cout<<"Paths   :"<<endl;
 	 	node :: paths( root , ar , 0);
		}
 	 
 }
 
void tree :: depth() 
 {
 	if(root == NULL )
 	 cout<<"ERROR TREE EMPTY\n";
 	 
 	else
 	 {
 	 	cout<<"Depth   : "<<node :: depth( root )<<endl;
		}
 }
 
void tree :: minimum()
 {
 	if(root == NULL)
 	 cout<<"ERROR TREE EMPTY\n";
 	 
 	cout<<"Minimum : "<<node :: minimum ( root )<<endl;
 }
 
void tree :: maximum()
 {
 	if(root == NULL)
 	 cout<<"ERROR TREE EMPTY\n";
 	 
 	cout<<"Maximun : "<<node :: maximum ( root )<<endl;
 }
 
void tree :: display ()
 {
 	if(root == NULL)
 	 cout<<"TREE EMPTY !\n";
 	else
 	 {
 	 	cout<<"Inorder : ";
		}
	  node :: display (root);
	  cout<<endl;
 	
 }
 
tree :: tree ()
 {
 	root = NULL;
 }
 
void tree :: insert ( int val )
 {
 	root = node :: insert ( root , val );
 }

int main()
 {
  tree obj;
  
  obj.insert(8);
  obj.insert(3);
  obj.insert(10);
  obj.insert(1);
  obj.insert(6);
  obj.insert(14);
  obj.insert(4);
  obj.insert(7);
  obj.insert(13);
  
  obj.display();
  obj.minimum();
  obj.maximum();
  
  obj.depth();
  obj.paths();
  
  obj.mirror();
	obj.display();
	obj.mirror();
	
	obj.lvlorder();
	
	obj.linklist();
 }

