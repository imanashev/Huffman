#pragma once
#include <cstddef> // Определение константы NULL

class TreeNode
{
private:
    char symbol;
    TreeNode *leftChildPtr, *rightChildPtr;
    TreeNode(
        char symb = '\0', 
        TreeNode* left = NULL, 
        TreeNode* right = NULL):
     symbol(symb), leftChildPtr(left), rightChildPtr(right)
    {};
    friend class BinaryTree;
};