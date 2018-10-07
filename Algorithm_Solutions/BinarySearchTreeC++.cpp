#include <iostream>
#include <queue>
#include <stack>

using namespace std;

template<class T>
class BSTnode
{
	public:
		T key;
		BSTnode *left, *right;
		
		BSTnode()
		{
			left=right=0;
		}
		
		BSTnode(const T& el, BSTnode* l=0, BSTnode* r=0)
		{
			key=el;
			left=l;
			right=r;
		}
};

template<class T>
class BST
{
	public:
		BSTnode<T>* root;
		
		BST()
		{
			root=0;
		}
		
		~BST()
		{
			clear();
		}
		
		void clear()
		{
			clear(root);
			root=0;
		}
		
		bool isEmpty() const
		{
			return root==0;
		}
		
		void preorder()
		{
			preorder(root);
		}
		
		void postorder()
		{
			postorder(root);
		}
		
		void inorder()
		{
			inorder(root);
		}
		
		T* search(const T& el) const
		{
			return search(root, el);
		}
		
		void breadthFirst();
		void iterativePreorder();
		void iterativePostorder();
		void iterativeInorder();
		
		void insert(const T&);
		void deleteByMerging(BSTnode<T>*&);
		void findAndDeleteByMerging(const T&);
		void findAndDeleteByCopying(const T&);
		void deleteByCopying(BSTnode<T>*&);
		void balance(T*, int, int);
		
		void clear(BSTnode<T>*);
		T* search(BSTnode<T>*, const T&) const;
		void preorder(BSTnode<T>*);
		void postorder(BSTnode<T>*);
		void inorder(BSTnode<T>*);
		
		void levelOrder(BSTnode<T>*);
		int count(BSTnode<T>*);
		int leafCount(BSTnode<T>*);
		int nonLeafCount(BSTnode<T>*);
		int height(BSTnode<T>*);
		void mirror(BSTnode<T>*);
		void processNode(BSTnode<T>*);
		T* searchByMerging(BSTnode<T>*, const T&) const;
		
		int LeftCount(BSTnode<T> *);
		int rightCount(BSTnode<T> *node);
		
		virtual void visit(BSTnode<T>* p)
		{
			cout<<p->key<<" ";
		}
};

template<class T>
T* BST<T> :: search(BSTnode<T>* p, const T& el) const
{
	while(p!=0)
		
		if(el == p->key)
		
			return &p->key;
		
		else if(el < p->key)
			
			p=p->left;
			
		else
			
			p=p->right;
	
	return 0;
}

template<class T>
void BST<T> :: inorder(BSTnode<T> *p)
{
	if(p!=0)
	{
		inorder(p->left);
		
		visit(p);
		
		inorder(p->right);
	}
}

template<class T>
void BST<T> :: preorder(BSTnode<T> *p)
{
	if(p!=0)
	{
		visit(p);
		
		preorder(p->left);
		
		preorder(p->right);
	}
}

template<class T>
void BST<T> :: postorder(BSTnode<T> *p)
{
	if(p!=0)
	{
		postorder(p->left);
		
		postorder(p->right);
		
		visit(p);
	}
}

template<class T>
void BST<T> :: insert(const T& el)
{
	BSTnode<T> *p=root, *prev=0;
	while(p!=0)
	{
		prev=p;
		
		if(p->key < el)
		
			p=p->right;
		
		else
		
			p=p->left;
	}
	
	if(root==0)
		
		root=new BSTnode<T>(el);
		
	else if(prev->key < el)
	
		prev->right=new BSTnode<T>(el);
		
	else
	
		prev->left=new BSTnode<T>(el);
}

template<class T>
void BST<T> :: deleteByMerging(BSTnode<T>*& node)
{
	BSTnode<T> *tmp=node;
	
	if(node!=0)
	{
		if(!node->right)
		
			node=node->left;
			
		else if(node->left == 0)
			
			node=node->right;
			
		else
		{
			tmp=node->left;
			
			while(tmp->right!=0)
				tmp=tmp->right;
				
				
			tmp->right=node->right;
			
			tmp=node;
			node=node->left;
		}
		
		delete tmp;
	}
}

template<class T>
void BST<T> :: findAndDeleteByMerging(const T& el)
{
	BSTnode<T> *node=root, *prev=0;
	
	while(node!=0)
	{
		if(node->key == el)	break;
		
		prev=node;
		
		if(node->key < el)
			
			node=node->right;
			
		else
		
			node=node->left;
	}
	
	if(node!=0 && node->key == el)
		
		if(node == root)
		
			deleteByMerging(root);
			
		else if(prev->left == node)
		
			deleteByMerging(prev->left);
		
		else
		
			deleteByMerging(prev->right);
			
	else if(root!=0)
		
		cout<<"\nkey "<<el<<" is not in the tree \n";
		
	else
	
		cout<<"\nThe tree is empty \n";
}

template<class T>
void BST<T> :: findAndDeleteByCopying(const T& el)
{
	BSTnode<T> *node=root, *prev=0;
	
	while(node!=0)
	{
		if(node->key == el)	break;
		
		prev=node;
		
		if(node->key < el)
			
			node=node->right;
			
		else
		
			node=node->left;
	}
	
	if(node!=0 && node->key == el)
		
		if(node == root)
		
			deleteByCopying(root);
			
		else if(prev->left == node)
		
			deleteByCopying(prev->left);
		
		else
		
			deleteByCopying(prev->right);
			
	else if(root!=0)
		
		cout<<"\nkey "<<el<<" is not in the tree \n";
		
	else
	
		cout<<"\nThe tree is empty \n";
}

template<class T>
void BST<T> :: deleteByCopying(BSTnode<T>*& node)
{
	BSTnode<T> *previous, *tmp=node;
	
	if(node->right == 0)
	
		node=node->left;
		
	else if(node->left == 0)
	
		node=node->right;
		
	else
	{
		tmp=node->left;
		previous=node;
		
		while(tmp->right!=0)
		{
			previous=node;
			tmp=tmp->right;
		}
		
		node->key=tmp->key;
		
		
		if(previous == node)
			previous->left=tmp->left;
		
		else 
			previous->right=tmp->left;
	}
	delete tmp;
}

template<class T>
void BST<T> :: levelOrder(BSTnode<T> *root)
{
	if(root==NULL)	return;
	
	queue<BSTnode<T>*> Q;
	Q.push(root);
	
	while(!Q.empty())
	{
		BSTnode<T>* current=Q.front();
		cout<<current->key<<" ";
	
		if(current->right != NULL)	Q.push(current->right);
	
		if(current->left != NULL)	Q.push(current->left);
	
		Q.pop();
	}
}

template<class T>
int BST<T> :: height(BSTnode<T> *root)
{
	if(root==NULL)	return -1;
	
	return max(height(root->left), height(root->right))+1;
}

template<class T>
int BST<T> :: count(BSTnode<T> *node)
{
	if(node!=0)
	{
		return count(node->left)+count(node->right)+1;
	}

	else 	return 0;
} 

template<class T>
int BST<T> :: leafCount(BSTnode<T> *node)
{
	if(node==NULL)	return 0;
	
	if(node->left==NULL && node->right==NULL)	return 1;
	
	else
		return leafCount(node->left)+leafCount(node->right);
}

template<class T>
int BST<T> :: LeftCount(BSTnode<T> *node)
{
	if(node->left!=0)
	{
		if(node->right)
			return LeftCount(node->left)+LeftCount(node->right)+1;
		
		else 	return LeftCount(node->left)+1;
	}
}

template<class T>
int BST<T> :: rightCount(BSTnode<T> *node)
{
	if(node->right!=0)
	{
		if(node->left)
			return rightCount(node->right)+rightCount(node->left)+1;
			
		else 	return rightCount(node->right)+1;
	}
}

template<class T>
void BST<T> :: mirror(BSTnode<T> *root)
{
	if(!root)	return;
	
	BSTnode<T> *temp=root->left;
	
	root->left=root->right;
	root->right=temp;
	
	mirror(root->left);
	mirror(root->right);
}

int main()
{
	BST<int> *b=new BST<int>();
	int el;
	char ch='y';
	
	do
	{
		cout<<"Enter the element to be inserted : ";
		cin>>el;
		b->insert(el);
		cout<<"\nDo you want to do more (y/n) ? ";
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	
	cout<<"\nThe inorder traversal : ";
	b->inorder(b->root);
	
	cout<<"\nThe preorder traversal : ";
	b->preorder(b->root);
	
	cout<<"\nThe postorder traversal : ";
	b->postorder(b->root);
	
	cout<<"\nEnter number to be deleted by merging : ";
	cin>>el;
	b->findAndDeleteByMerging(el);
	
	cout<<"\nThe inorder traversal : ";
	b->inorder(b->root);
	
	cout<<"\nThe preorder traversal : ";
	b->preorder(b->root);
	
	cout<<"\nThe postorder traversal : ";
	b->postorder(b->root);

    	cout<<"\nEnter the number to be deleted by copying : ";
	cin>>el;
	b->findAndDeleteByCopying(el);
	
	cout<<"\nThe inorder traversal : ";
	b->inorder(b->root);
	
	cout<<"\nThe preorder traversal : ";
	b->preorder(b->root);
	
	cout<<"\nThe postorder traversal : ";
	b->postorder(b->root);
	
	cout<<"\nEnter element to be searched in tree : ";
	cin>>el;
	if(b->search(el))
		cout<<el<<" has found in tree !!!";
	else 
		cout<<el<<" has not found in tree !!!";
	
	cout<<"\nLeaf count : "<<(b->leafCount(b->root));
	cout<<"\nTotal count : "<<(b->count(b->root));
	cout<<"\nNon-leaf count : "<<((b->count(b->root))-(b->leafCount(b->root)));
	
	cout<<"\nThe left nodes : "<<(b->LeftCount(b->root));

	cout<<"\nThe right nodes : "<<(b->rightCount(b->root));

	cout<<"\nMirror image (preorder) : ";
	b->mirror(b->root);
	b->preorder(b->root);
	
	cout<<"\nLevel order : ";
	b->levelOrder(b->root);
	
	cout<<"\nThe height of tree : "<<(b->height(b->root));
	
	return 0;
}
