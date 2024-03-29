#include <iostream>

using namespace std;

// Node Tree
typedef struct node
{
	uint16_t data;
	node* left;
	node* right;
}Tree;


void disp_tree_leaf_only(node* root)
{
	if (root == nullptr)
	{
		cout << "empty tree" << endl;
		return;
	}

	if (root->left == nullptr && root->right == nullptr)
	{
		cout << root->data << endl;
		return;
	}

	if(root->left != nullptr)
		disp_tree_leaf_only(root->left);
	if(root->right != nullptr)
		disp_tree_leaf_only(root->right);
}

void disp_left_to_right_sorted(node* root)
{
	if (root == nullptr)
	{
		cout << "Nothing to display" << endl;
		return;
	}

	if(root->left != nullptr)
		disp_left_to_right_sorted(root->left);

	cout << root->data << endl;

	if (root->right != nullptr)
		disp_left_to_right_sorted(root->right);

}


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
	root = insert_tree(root, 9);
	root = insert_tree(root, 8);

	cout << "Display Leafs Only: " << endl;
	disp_tree_leaf_only(root);

	cout << "Display Tree Left to Right" << endl;
	disp_left_to_right_sorted(root);

}
