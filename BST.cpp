#include <iostream>

using namespace std;

// Node Tree
typedef struct node
{
	uint16_t data;
	node* left;
	node* right;
}Tree;


//void display_tree(node* root)
//{
//	if (root->left != nullptr)
//		display_tree(root->left);
//	if (root->right != nullptr)
//		display_tree(root->right);
//	cout << root->data << endl;
//	
//}


node* insert_tree(node* root, uint16_t data)
{
	// if no node exists(root is null)
	if (root == nullptr)
	{
		root = new node;
		root->left = nullptr;
		root->right = nullptr;
		root->data = data;
		return root;
	}
	// we know root is not empty now
	else if (data <= root->data)
	{
		// data goes to the left side of node
		root->left = insert_tree(root->left, data);
	
	}
	else
		// data goes to the right side of node
		root->right = insert_tree(root->right, data);

	return root;
}

int main()
{
	// root start with pointing to nothing
	node* root = nullptr;

	root = insert_tree(root, 15);
	root = insert_tree(root, 10);
	root = insert_tree(root, 25);
	root = insert_tree(root, 7);
	root = insert_tree(root, 11);

	display_tree(root);
}