#pragma once
#include "HuffmanNode.h"
#include <string>
#include <map>

class HuffmanTree
{
private:
	HuffmanNode* root;

    void attachLeftSubTree(HuffmanTree& leftTree);
    void attachRightSubTree(HuffmanTree& rightTree);
    void destroyTree(HuffmanNode *& treePtr);
	void copyTree(HuffmanNode*& nodePtr, HuffmanNode* srcNodePtr);
	void getCodeTableHelper(HuffmanNode* nodePtr, std::string code, std::map<char, std::string>& table);
public:
	HuffmanTree();
	HuffmanTree(HuffmanTree& src);
	~HuffmanTree();

	HuffmanTree(char symbol, unsigned int freq, HuffmanTree& leftTree, HuffmanTree& rightTree);
	HuffmanTree(unsigned int freq, HuffmanTree& leftTree, HuffmanTree& rightTree);
	HuffmanTree(char symbol, unsigned int freq);

    char getRootSymb();
	unsigned int getRootFreq();
	std::map<char, std::string> getCodeTable();
	std::string decode(std::string encoded);
};

