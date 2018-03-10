#include "RBTree.h"

void RBTreeRR(RBTree* t, RBNode* n) {

	RBNode *left = n->left;

	if (left == t->leaf)
		return;

	if (n->parent->left == n)
		n->parent->left = left;
	else
		n->parent->right = left;

	left->parent = n->parent;

	n->left = left->right;
	left->right = n;

}

void RBTreeLR(RBTree* t, RBNode* n) {

	RBNode *right = n->right;

	if (right == t->leaf)
		return;

	if (n->parent->left == n)
		n->parent->left = right;
	else
		n->parent->right = right;

	right->parent = n->parent;

	n->right = right->left;
	right->left = n;

}

RBNode* RBTreeGetUncle(RBNode *n) {
	return (n->parent->parent->right == n->parent) ? n->parent->parent->left : n->parent->parent->right;
}

void RBTreeCheckInsert(RBTree *t, RBNode* n) {

	char color;

	if (RBTreeGetUncle(n) == 'R') {

		n->parent->color = 'B';
		RBTreeGetUncle(n)->color = 'B';
		n->parent->parent->color = 'R';
		RBTreeCheckInsert(t, n->parent->parent);
		return;
	}

	if (n->parent->parent->left == n->parent) {
	
		if (n->parent->right == n) {

			RBTreeLR(t, n->parent);

		}

	}
	else {

		if (n->parent->left == n) {

			RBTreeRR(t, n->parent);

		}

	}

	// n becomes parent node after rotation above
	color = n->color;
	n->color = n->parent->color;
	n->parent->color = color;
	if (n->parent->left == n) {

		RBTreeRR(t, n->parent);

	}
	else {

		RBTreeLR(t, n->parent);

	}

}

RBNode* RBTreeInsert(RBTree *tree, int key) {

	RBNode *exist;
	RBNode *n;
	RBNode *parent;
	
	exist = RBTreeSearch(tree, key);
	if (exist != NULL)
		return exist;

	n = (RBNode*)malloc(sizeof(RBNode));
	n->key = key;
	n->color = 'R';
	n->lSubHeight = 0;
	n->rSubHeight = 0;
	n->parent = NULL;
	n->left = tree->leaf;
	n->right = tree->leaf;
	
	if (tree->root == NULL)
	{
		n->color = 'B';
		tree->root = n;
	}

	parent = tree->root;
	while (1) {
		n->parent = parent;

		if (parent->key > key) {
			parent->lSubHeight++;
			if (parent->left == tree->leaf) {
				parent->left = n;
				break;
			}
			else
				parent = parent->left;

		}
		else if (parent->key < key) {
			parent->rSubHeight++;
			if (parent->right == tree->leaf) {
				parent->right = n;
				break;
			}
			else
				parent = parent->right;
		}
		else {
			free(n);
			return parent;
		}

	}

	if (n->parent->color == 'B')
		return n;

	if (RBTreeGetUncle(n) == 'R')


	return n;

}