#include "HuffmanTree.h"

HuffmanTree::HuffmanTree() :root(NULL) {};

HuffmanTree::HuffmanTree(char symbol, unsigned int freq, HuffmanTree& leftTree, HuffmanTree& rightTree)
{
    root = new HuffmanNode(freq, symbol);
    attachLeftSubTree(leftTree);
    attachRightSubTree(rightTree);
}

HuffmanTree::HuffmanTree(unsigned int freq, HuffmanTree& leftTree, HuffmanTree& rightTree)
{
	root = new HuffmanNode(freq);
    attachLeftSubTree(leftTree);
    attachRightSubTree(rightTree);
}

HuffmanTree::HuffmanTree(char symbol, unsigned int freq)
{
	root = new HuffmanNode(freq, symbol);
}

HuffmanTree::HuffmanTree(HuffmanTree & src)
{
	copyTree(root, src.root);
}

HuffmanTree::~HuffmanTree()
{
    destroyTree(root);
}

void HuffmanTree::destroyTree(HuffmanNode *& treePtr)
{
	if (treePtr)
	{
		destroyTree(treePtr->leftChildPtr);
		destroyTree(treePtr->rightChildPtr);
		delete treePtr;
		treePtr = NULL;
	}
}

void HuffmanTree::copyTree(HuffmanNode *& nodePtr, HuffmanNode * srcNodePtr)
{
	if (srcNodePtr)
	{
		nodePtr = new HuffmanNode(srcNodePtr->freq, srcNodePtr->symb);
		copyTree(nodePtr->leftChildPtr, srcNodePtr->leftChildPtr);
		copyTree(nodePtr->rightChildPtr, srcNodePtr->rightChildPtr);
	}
	else
	{
		nodePtr = NULL;
	}
}

void HuffmanTree::attachLeftSubTree(HuffmanTree& leftTree)
{
 	root->leftChildPtr = leftTree.root;
	leftTree.root = NULL;
}

void HuffmanTree::attachRightSubTree(HuffmanTree& rightTree)
{
	root->rightChildPtr = rightTree.root;
	rightTree.root = NULL;
}

 char HuffmanTree::getRootSymb()
 {
     return root->symb;
 }

unsigned int HuffmanTree::getRootFreq()
 {
	 return root->freq;
 }

 std::map<char, std::string> HuffmanTree::getCodeTable()
 {
	 std::map<char, std::string> table;
	 getCodeTableHelper(root, "", table);
	 return table;
 }

 void HuffmanTree::getCodeTableHelper(HuffmanNode* nodePtr, std::string code, std::map<char, std::string>& table)
 {
	 if (nodePtr->leftChildPtr)
	 {
		 getCodeTableHelper(nodePtr->leftChildPtr, code + '0', table);
		 getCodeTableHelper(nodePtr->rightChildPtr, code + '1', table);

	 }
	 else
	 {
		 table[nodePtr->symb] = code;
	 }

 }

 std::string HuffmanTree::decode(std::string encoded)
 {
	 std::string result = "";
	 HuffmanNode *curNode = root;
	 for (auto i : encoded)
	 {
		 bool flag =  i - '0';
		 curNode = flag ? curNode->rightChildPtr : curNode->leftChildPtr;
		 if (curNode->symb != '\0')
		 {
			 result += curNode->symb;
			 curNode = root;
		 }
	 }
	 return result;
 }