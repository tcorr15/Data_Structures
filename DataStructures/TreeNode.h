#ifndef TREENODE_H
#define TREENODE_H

#include <iostream>

// An object of type TreeNode holds three things: 
//		- an item (of type T)
//		- a left subtree
//		- a right subtree

template <typename T>
class TreeNode
{
public:
	TreeNode(T i, TreeNode<T>* l, TreeNode<T>* r);
	TreeNode(T i);
	~TreeNode();

	TreeNode<T>* insert(TreeNode<T>* tree, T item);
	void traverse();

	bool searchTree(T key);

	template<typename U>
	friend int depth(TreeNode<U>* tree);

	friend int sigma(TreeNode<int>* tree);

	friend int maxnum(TreeNode<int>* tree);
private:
	// The three things held in a TreeNode
	T item;
	TreeNode<T>* left, * right;
};

template <typename T>
TreeNode<T>::TreeNode(T i, TreeNode<T>* l, TreeNode<T>* r)
	: item(i), left(l), right(r)
{
}

template <typename T>
TreeNode<T>::TreeNode(T i)
	: item(i), left(0), right(0)
{
}

template <typename T>
TreeNode<T>::~TreeNode()
{
	if (left) delete left;
	if (right) delete right;
}

template <typename T>
TreeNode<T>* TreeNode<T>::insert(TreeNode<T>* tree, T item)
{
	// Inserts item in tree, and returns the new tree
	if (tree == 0)
		tree = new TreeNode<T>(item);
	else
		if (item < tree->item)
			tree->left = insert(tree->left, item);
		else
			tree->right = insert(tree->right, item);
	return tree;
}

template <typename T>
void TreeNode<T>::traverse()
{
	if (left != 0)
		left->traverse();
	std::cout << item << std::endl;
	if (right != 0)
		right->traverse();
}

template<typename T>
bool TreeNode<T>::searchTree(T key) {
	if (item == key) {
		return true;
	}
	if (left != 0) {
		bool found = left->searchTree(key);
		if (found) return true;
	}
	if (right != 0)
		return right->searchTree(key);
	return false;
}

#endif
