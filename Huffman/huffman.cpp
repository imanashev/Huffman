#include <iostream>
#include <map>
#include <queue>
#include <string>
#include <bitset>
#include <fstream>
#include <iterator>
#include "HuffmanTree.h"

#define INPUT_MODE 0	// 0 - read from terminal
						// 1 - read from file
#define DEBUG_MODE 1  
#define FILENAME "file.txt"

struct greaterOrder
{
	bool operator()(HuffmanTree *lhs, HuffmanTree *rhs)
	{
		return lhs->getRootFreq() > rhs->getRootFreq();
	}
};

HuffmanTree* huffmanEncode(std::string sourse, std::string &result)
{
	std::priority_queue <HuffmanTree*, std::vector <HuffmanTree*>, greaterOrder> queue;
	std::map<char, std::string> codeTable;
	unsigned int freq[255] = { 0 };
	for (auto symb : sourse) // count symbols frequency
	{
		freq[symb]++;
	}

	for (int i = 0; i < 255; i++) // filling queue
	{
		if (freq[i])
		{
			queue.push(new HuffmanTree(char(i), freq[i]));
		}
	}

	while (queue.size() > 1) //bulding tree
	{
		auto left = queue.top();
		queue.pop();

		auto right = queue.top();
		queue.pop();

		queue.push(new HuffmanTree(left->getRootFreq() + right->getRootFreq(), *left, *right));
	}

	codeTable = queue.top()->getCodeTable();

	result = "";
	for (auto symbol : sourse)
	{
		result += codeTable[symbol];
	}

	if(DEBUG_MODE) 	//Print part
	{
		std::cout << "Sourse: " << sourse << std::endl;

		std::cout << "Freq: " << std::endl;
		for (int i = 0; i < 255; i++)
		{
			if (freq[i])
			{
				std::cout << "'" << char(i) << "' : " << freq[i] << std::endl;
			}
		}
		std::cout << std::endl;

		std::cout << "Code:" << std::endl;
		for (auto i : codeTable)
		{
			std::cout << "'" << i.first << "' : " << i.second << std::endl;
		}
		std::cout << std::endl;

		std::cout << "Sourse text" << std::endl;
		for (auto symb : sourse)
		{
			std::cout << std::bitset<8>(symb) << ' ';
		}
		std::cout << std::endl << std::endl;

		std::cout << "Encoded text: " << std::endl;
		for (auto symbol : sourse)
		{
			std::cout << codeTable[symbol] << ' ';
		}
		std::cout << std::endl;
	}
	std::cout << "Sourse text len = " << sourse.length() * 8 << " bits" << std::endl;
	std::cout << "Encoded text len = " << result.length() << " bits" << std::endl;

	return queue.top();
}

std::string huffmanDecode(std::string encoded, HuffmanTree& codeTree)
{
	std::string result;
	result = codeTree.decode(encoded);
	return result;
}

void main()
{
	std::string input, encoded, decoded;

	if (INPUT_MODE)
	{
		std::ifstream in(FILENAME);
		std::string tmp;
		while (getline(in, tmp))
		{
			input += tmp + '\n';
		}
	}
	else
	{
		std::cout << "Enter text to encryption: "; 
		//getline(std::cin, input);
		input = "beep boop beer!";
	}

	HuffmanTree codeTree(*huffmanEncode(input, encoded));
	decoded = huffmanDecode(encoded, codeTree);

	if (DEBUG_MODE)
	{
		std::cout << std::endl << "Decoded text: " << std::endl << decoded << std::endl;
	}
}