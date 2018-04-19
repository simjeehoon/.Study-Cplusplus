#ifndef __TREENODE_H__
#define __TREENODE_H__
#include <iostream>

template <typename ElementType>
struct TreeNode{
	ElementType element;
	TreeNode* left;
	TreeNode* right;
	template<typename T>
	TreeNode(T init)
		:element(init), left(NULL), right(NULL) {}
	TreeNode()
		:left(NULL), right(NULL){}
};

#endif
