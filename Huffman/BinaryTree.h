#pragma once
#include "TreeNode.h"
#include <string>
#include <map>

class BinaryTree
{
private:
    TreeNode* root;
    void attachLeftSubTree(BinaryTree& leftTree);
    void attachRightSubTree(BinaryTree& rightTree);
    void destroyTree(TreeNode *& treePtr);
	void copyTree(TreeNode*& nodePtr, TreeNode* srcNodePtr);
	void getCodeTableHelper(TreeNode* nodePtr, std::string code, std::map<char, std::string>& table);
public:
	BinaryTree();
    BinaryTree(char symbol, BinaryTree& leftTree, BinaryTree& rightTree);
    BinaryTree(BinaryTree& leftTree, BinaryTree& rightTree);    
	BinaryTree(char symbol);
	BinaryTree(BinaryTree& src);
    ~BinaryTree();
    char getRootData();
	std::map<char, std::string> getCodeTable();
};
