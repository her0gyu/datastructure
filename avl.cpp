#include <iostream>
#include <queue>

using namespace std;

typedef struct node {
	int data;
	struct node* left;
	struct node* right;
} node;

int max(int a, int b) {
	return a > b ? a : b;
}

node *create_node(int data) {
	node *n= new node();
	n->data = data;
	n->left = NULL;
	n->right = NULL;
	return n;
}

node *get_minnode(node *root) 
{
	if(root->left== NULL)
		return root;
	return get_minnode(root->left);
}

int height(node *root) {
	if(root == NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

int get_balance(node *root) 
{
	return height(root->left) - height(root->right);
}

node *right_rotate(node *root)
{
	node *t = root->left;
	node *u = t->right;
	t->right = root;
	root->left = u;
	return t;
}

node *left_rotate(node *root)
{
	node *t = root->right;
	node *u = t->left;
	t->left = root;
	root->right = u;
	return t;
}

node* re_balance(node *root) {

	int bal = get_balance(root);

	if(b > 1) {
		if(get_balance(root->left) < 0)
			root->left = left_rotate(root->left);
		return right_rotate(root);
	} else if(b < -1) {
		if(get_balance(root->right) > 0)
			root->right = regit_rotate(root->right);
		return left_rotate(root);

	}
	
	return root;
}

node* insert_node(node *root, int item)
{
	node *n = create_node(item);
	node *tmp;

	if(root == NULL) {
		return n;
	}
	
	tmp = root;
/*insertion*/
	while(tmp) {
		if(item < root->data) {
			if(tmp->left)
				tmp = tmp->left;
			else
				tmp->left = n;
		}
		else {
			if(tmp->right)
				tmp = tmp->right;
			else
				tmp->right = n;
	
		}	
	}
/*balance*/
	root = re_balance(root);
	
	return root;
}

node* delete_node(node *root, int key)
{
	if(root == NULL)
		return root;
	
	if(key < root->data)
		root->left = delete_node(root->left, key);
	else if(key > root->data)
		root->right = delete_node(root->right, key);
	else {
		if(!root->right) {
			node *temp = root->left;
			delete(root);
			root = NULL;
			return temp;
		} else if(!root->left) {
			node *temp = root->right;
			delete(root);
			root = NULL;
			return temp;
		}
		
		node *temp = get_minmode(root->right);
		root->data = temp->data;
		root->right = delete_node(root->right, temp->data);
	}

	root = re_balance(root);
	return root;
}

void level_order(node *root) 
{
	queue<node*> q;
	q.push(root);
	while(!q.empty()) {
		root = q.front();
		cout << root->data <<" ";
		q.pop();
		if(root->left)
			q.push(root->left);
		if(root->right)
			q.push(root->right);
	}
}


