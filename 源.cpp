// C program to demonstrate delete operation in binary search tree
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int key;
	int subtree_size;
	struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item)
{
	struct node *temp = (struct node *)malloc(sizeof(struct node));
	temp->subtree_size = 1;
	temp->key = item;
	temp->left = temp->right = NULL;
	return temp;
}

// A utility function to do inorder traversal of BST
void inorder(struct node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->key);
		inorder(root->right);
	}
}

/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key)
{
	/* If the tree is empty, return a new node */
	if (node == NULL) return newNode(key);

	/* Otherwise, recur down the tree */
	if (key < node->key)
	{
		node->left = insert(node->left, key);
		node->subtree_size++;
	}
	else
	{
		node->right = insert(node->right, key);
		node->subtree_size++;
	}

	/* return the (unchanged) node pointer */
	return node;
}

/* Given a non-empty binary search tree, return the node with minimum
key value found in that tree. Note that the entire tree does not
need to be searched. */
struct node * minValueNode(struct node* node)
{
	struct node* current = node;

	/* loop down to find the leftmost leaf */
	while (current->left != NULL)
		current = current->left;

	return current;
}

/* Given a binary search tree and a key, this function deletes the key
and returns the new root */
struct node* deleteNode(struct node* root, int key)
{
	// base case
	if (root == NULL) return root;

	// If the key to be deleted is smaller than the root's key,
	// then it lies in left subtree
	if (key < root->key)
	{
		root->left = deleteNode(root->left, key);
		root->subtree_size--;
	}

	// If the key to be deleted is greater than the root's key,
	// then it lies in right subtree
	else if (key > root->key)
	{
		root->right = deleteNode(root->right, key);
		root->subtree_size--;
	}
	// if key is same as root's key, then This is the node
	// to be deleted
	else
	{
		// node with only one child or no child
		if (root->left == NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if (root->right == NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}

		// node with two children: Get the inorder successor (smallest
		// in the right subtree)
		struct node* temp = minValueNode(root->right);

		// Copy the inorder successor's content to this node
		root->key = temp->key;

		// Delete the inorder successor
		root->right = deleteNode(root->right, temp->key);
		root->subtree_size--;
	}
	return root;
}

int GetLand(node *root, int key)
{
	int land = 0;
	while (root->key != key)
	{
		if (root->key < key)
		{
			land += 1 + root->left->subtree_size;
			root = root->right;
		}
		else
		{
			root = root->left;
		}
	}
	if (root->left != NULL)
		land += root->left->subtree_size + 1;
	else
		land += 1;
	return land;
}

// Driver Program to test above functions
int main()
{
	/* Let us create following BST
	50
	/     \
	30      70
	/  \    /  \
	20   40  60   80 */
	struct node *root = NULL;
	root = insert(root, 50);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 40);
	root = insert(root, 70);
	root = insert(root, 60);
	root = insert(root, 80);
	printf("%d", GetLand(root,50));
	system("pause");
	return 0;
}
