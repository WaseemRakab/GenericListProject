#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>



/* Definition for a binary tree node.*/
struct TreeNode {
	int val;
	struct TreeNode* left;
	struct TreeNode* right;
};

typedef struct TreeNode Tree;


void preorder(Tree* tree)
{
	if (tree == NULL)
		return;

	printf("%d,", tree->val);
	preorder(tree->left);
	preorder(tree->right);
}

int maxLevelSum(Tree* root)
{
	if (root == NULL)
		return 0;
}

int SumOfTwoSons(Tree* left, Tree* right) {

	return left->val + right->val;
}

void MinDigit(int num, int* minDig)
{
	if (num == 0)
		return;
	if (num % 10 != 0 && num % 10 < *minDig)
		*minDig = num % 10;
	return MinDigit(num / 10, minDig);
}

int afterFindingMinDig(int num, int digToRemove, bool removedOneMaxDigit)
{
	if (num == 0)
		return 0;
	if (num % 10 != digToRemove || removedOneMaxDigit)
		return afterFindingMinDig(num / 10, digToRemove, removedOneMaxDigit) * 10 + num % 10;
	else if (!removedOneMaxDigit)
	{
		removedOneMaxDigit = true;
		return afterFindingMinDig(num / 10, digToRemove, removedOneMaxDigit) + 0;
	}
}

int CountZeros(int num)
{
	if (num == 0)
		return 0;
	if (num % 10 == 0)
		return 1 + CountZeros(num / 10);
	return CountZeros(num / 10);
}

int SortDigits(int num)
{
	if (num == 0)
		return 0;
	int minDig = 9;
	int* max = &minDig;
	MinDigit(num, max);
	int newNum = afterFindingMinDig(num, minDig, false);
	return SortDigits(newNum) * 10 + minDig;
}

int main()
{
	/*Tree* tree = (Tree*)malloc(sizeof(Tree));
	if (tree != NULL) {
		tree->val = 1;
		tree->left = (Tree*)malloc(sizeof(Tree));
		if (tree->left != NULL) {
			tree->left->val = 7;
			tree->left->left = (Tree*)malloc(sizeof(Tree));
			if (tree->left->left != NULL) {
				tree->left->left->val = 7;

				tree->left->left->right = NULL;
				tree->left->left->left = NULL;
			}
			tree->left->right = (Tree*)malloc(sizeof(Tree));
			if (tree->left->right != NULL) {
				tree->left->right->val = -8;

				tree->left->right->left = NULL;
				tree->left->right->right = NULL;
			}
		}
		tree->right = (Tree*)malloc(sizeof(Tree));;
		if (tree->right != NULL) {
			tree->right->val = 0;
			tree->right->left = NULL;
			tree->right->right = NULL;
		}
	}
	preorder(tree);
	int max = maxLevelSum(tree);
	printf("%d", max);*/

	int num = 132562;
	int sorted = SortDigits(num) * (int)pow(10, CountZeros(num));
	printf("%d", sorted);

	return 0;
}