#include<iostream>
using namespace std;
struct Node
{
	int key;
	Node *left = NULL;
	Node *right = NULL;
};
class Binary_Search_Tree
{
private:
	Node * pre;
public:
	Binary_Search_Tree()
	{
		pre = new Node;
		pre->key = INT_MAX;
	}
	void Insert(int x);
	bool Delete(int x);
	void Sort_Display(Node *p);
	Node *getroot()
	{
		return pre->left;
	}
};
void Binary_Search_Tree::Insert(int x)
{
	Node *head = pre;
	Node *parent = pre;
	while (head != NULL)
	{
		if (x >= head->key)
		{
			parent = head;
			head = head->right;
		}
		else
		{
			parent = head;
			head = head->left;
		}
	}
	if (parent->key < x)
	{
		parent->right = new Node;
		parent->right->key = x;
	}
	else
	{
		parent->left = new Node;
		parent->left->key = x;
	}


}
bool Binary_Search_Tree::Delete(int x)
{
	Node *head = pre;
	Node *parent = NULL;
	while (head != NULL && head->key != x)
	{
		if (head->key < x)
		{
			parent = head;
			head = head->right;
		}
		else
		{
			parent = head;
			head = head->left;
		}
	}
	if (head == NULL)
	{
		cout << "not found";
		return 0;
	}
	if (head->left == NULL && head->right == NULL)
	{
		if (parent->left == head)
			parent->left = NULL;
		else
			parent->right = NULL;
		delete head;
		return 1;
	}

	if (head->left == NULL && head->right != NULL)
	{
		if (parent->left == head)
			parent->left = head->right;
		else
			parent->right = head->right;
		delete head;
		return 1;
	}

	if (head->right == NULL && head->left != NULL)
	{
		if (parent->left == head)
			parent->left = head->left;
		else
			parent->right = head->left;
		delete head;
		return 1;
	}
	if (head->right != NULL && head->left != NULL)
	{
		if (parent->left == head)
		{
			parent->left = head->right;
			parent = head->right;
			while (parent->left != NULL)
				parent = parent->left;
			parent->left = head->left;
			delete head;
		}
		else
		{
			parent->right = head->left;
			parent = head->left;
			while (parent->left != NULL)
				parent = parent->right;
			parent->right = head->right;
			delete head;
		}
		return 1;
	}
}
void Binary_Search_Tree::Sort_Display(Node *p)
{
	if (p->left != NULL)
		Sort_Display(p->left);
	cout << p->key << " ";
	if (p->right != NULL)
		Sort_Display(p->right);
}
int main()
{
	Binary_Search_Tree T;
	T.Insert(8);
	T.Insert(15);
	T.Insert(200);
	T.Insert(9);
	T.Insert(5);
	T.Insert(65);
	T.Insert(4);
	T.Insert(-65);
	T.Insert(3);
	T.Delete(4);
	T.Sort_Display(T.getroot());
	system("pause");
}