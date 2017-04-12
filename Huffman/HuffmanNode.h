#pragma once
#include <cstddef>

class HuffmanNode
{
private:
    char symb;
	unsigned int freq;
	HuffmanNode *leftChildPtr, *rightChildPtr;
	HuffmanNode(
		unsigned int _freq = 0,
        char _symb = '\0',
		HuffmanNode* left = NULL,
		HuffmanNode* right = NULL):
     freq(_freq), symb(_symb), leftChildPtr(left), rightChildPtr(right)
    {};
    friend class HuffmanTree;
};