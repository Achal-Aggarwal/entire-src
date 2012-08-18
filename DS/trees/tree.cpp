//sg
/* simple program to read a tree
 * 
 */
#include<iostream>
using namespace std;
/* A NODE OF THE TREE*/

template <class T>
struct TreeNode
{
	T  data;
	TreeNode * left,*right;
	TreeNode(T data)
	{
		
		this->data=data;
		left=right=NULL;
	}
};
/*CLASS REPRESENTING A TREE*/
template <class T>
class Tree
{
	TreeNode<T> * head;
	public:
	Tree(T  data)
	{
		head=new TreeNode<T>(data);
	}
	
	TreeNode<T>* getHead()
	{
		return head;
	}
	template<class L>
	friend istream& operator >> (istream& i,Tree<L>& t);
	void inorder(TreeNode<T>* head);
	int height(TreeNode<T>* head);
	int internalNodes(TreeNode<T>* head);
	int totalNodes(TreeNode<T>* head);
	int leafNodes(TreeNode<T>* head);
	void treeStatPrinter();
};
template<class T>
void Tree<T>::treeStatPrinter()
{
	cout<<"\n\t\tTREE STATS\n\n";
	cout<<"_____________________\n";
	cout<<"\tInorder Trace = ";inorder(head);cout<<"\n";
	cout<<"\n\tHeight = "<<height(head)<<"\n";
	cout<<"\n\tInternal Nodes = "<<internalNodes(head)<<"\n";
	cout<<"\n\tLeaf Nodes = "<<leafNodes(head)<<"\n";
	cout<<"\n\tTotal Nodes = "<<totalNodes(head)<<"\n";
	cout<<"_____________________\n";
}
template<class T>
int Tree<T>::height(TreeNode<T>* head)
{
	if((!head)||(!head->right&&!head->left))
	return 0;
	int lh=height(head->left);
	int rh=height(head->right);
	return 1+((lh>rh)?lh:rh);
}
template<class T>
int Tree<T>::internalNodes(TreeNode<T>* head)
{
	if(!head)
	return 0;
	if(!head->right&&!head->left)
	return 0;
	//ok not a leaf
	return 1+internalNodes(head->left)+internalNodes(head->right);
}
template<class T>
int Tree<T>::leafNodes(TreeNode<T>* head)
{
	if(!head)
	return 0;
	if(!head->right&&!head->left)
	return 1;
	//ok not a leaf
	return leafNodes(head->left)+leafNodes(head->right);
}

template<class T>
int Tree<T>::totalNodes(TreeNode<T>* head)
{
	if(!head)
	return 0;
	if(!head->right&&!head->left)
	return 1;
	//ok not a leaf
	return 1+totalNodes(head->left)+totalNodes(head->right);

}
template <class T>
void Tree<T>::inorder(TreeNode<T>* head)
{
	if(head)
	{
	inorder(head->left);
	cout<<" "<<head->data;
	inorder(head->right);
	}
}
template <class T>
istream& operator >> (istream& i,Tree<T>& t)
{
	//this will help in reading the tree in depth order
	TreeNode<T> * stack[100];
		
	int top=-1,lv,rv;
	bool complete=false;
	TreeNode<T> * curr=t.head,*lc,*rc;
	while(!complete)
	{
		cout<<"\n";
		cout<<"Enter left child of  "<<curr->data<<" : ";
		cin>>lv;
		cout<<"Enter right child of "<<curr->data<<" : ";
		cin>>rv;
		if((lv==0)&&(rv==0)) //at a leaf
		{
			if(top==-1) //no  more to process
			{
				complete=true;
				break;
			}
			else //go to the next node
			{
				curr=stack[top];
				top--;
				continue;
			}
		}
		else if((lv==0)&&(rv!=0)) //only right child is there
		{
		rc=new TreeNode<T>(rv);
		top++;
		stack[top]=rc;
		curr->right=rc;
		}
		else if((lv!=0)&&(rv==0)) //only left child is there
		{
		lc=new TreeNode<T>(lv);
		top++;
		stack[top]=lc;
		curr->left=lc;
		}
		else //not a leaf, gotta update the l and r childs
		{
		lc=new TreeNode<T>(lv);
		top++;
		stack[top]=lc;
		rc=new TreeNode<T>(rv);
		top++;
		stack[top]=rc;
		curr->left=lc;
		curr->right=rc;
		}
		curr=stack[top];
		top--;
		}
		
		
	
return i;
}
	
int main()
{
	int rootVal;
	cout<<"Enter root node value " ;
	cin>>rootVal;
	Tree<int> * t=new  Tree<int>(rootVal);
	cin>>(*t);

	t->treeStatPrinter();
	return 0;
}