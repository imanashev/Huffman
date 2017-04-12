#include "BinaryTree.h"

BinaryTree::BinaryTree() :root(NULL) {};

BinaryTree::BinaryTree(char symbol, BinaryTree& leftTree, BinaryTree& rightTree)
{
    root = new TreeNode(symbol, NULL, NULL);
    attachLeftSubTree(leftTree);
    attachRightSubTree(rightTree);
}

BinaryTree::BinaryTree(BinaryTree& leftTree, BinaryTree& rightTree)
{
    root = new TreeNode;
    attachLeftSubTree(leftTree);
    attachRightSubTree(rightTree);
}

BinaryTree::BinaryTree(char symbol)
{
	root = new TreeNode(symbol, NULL, NULL);
}

BinaryTree::BinaryTree(BinaryTree & src)
{
	copyTree(root, src.root);
}

BinaryTree::~BinaryTree()
{
    destroyTree(root);
}

void BinaryTree::destroyTree(TreeNode *& treePtr)
{
	if (treePtr)
	{
		destroyTree(treePtr->leftChildPtr);
		destroyTree(treePtr->rightChildPtr);
		delete treePtr;
		treePtr = NULL;
	}
}

void BinaryTree::copyTree(TreeNode *& nodePtr, TreeNode * srcNodePtr)
{
	if (srcNodePtr)
	{
		nodePtr = new TreeNode(srcNodePtr->symbol);
		copyTree(nodePtr->leftChildPtr, srcNodePtr->leftChildPtr);
		copyTree(nodePtr->rightChildPtr, srcNodePtr->rightChildPtr);
	}
	else
	{
		nodePtr = NULL;
	}
}

void BinaryTree::attachLeftSubTree(BinaryTree& leftTree)
{
 	root->leftChildPtr = leftTree.root;
	leftTree.root = NULL;
}

void BinaryTree::attachRightSubTree(BinaryTree& rightTree)
{
	root->rightChildPtr = rightTree.root;
	rightTree.root = NULL;
}

 char BinaryTree::getRootData()
 {
     return root->symbol;
 }

 std::map<char, std::string> BinaryTree::getCodeTable()
 {
	 std::map<char, std::string> table;
	 getCodeTableHelper(root, "", table);
	 return table;
 }

 void BinaryTree::getCodeTableHelper(TreeNode* nodePtr, std::string code, std::map<char, std::string>& table)
 {
	 if (nodePtr->leftChildPtr)
	 {
		 getCodeTableHelper(nodePtr->leftChildPtr, code + '0', table);
		 getCodeTableHelper(nodePtr->rightChildPtr, code + '1', table);

	 }
	 else
	 {
		 table[nodePtr->symbol] = code;
	 }

 }