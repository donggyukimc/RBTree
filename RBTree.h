#pragma once

#ifndef _RBTREE_H_
#define _RBTREE_H_

#include "RBNode.h"

typedef struct RBTree {

	RBNode *root;
	RBNode *leaf;

}RBTree;

void RBTreeRR(RBTree*, RBNode*);
void RBTreeLR(RBTree*, RBNode*);
RBNode* RBTreeGetUncle(RBNode*);

RBNode* RBTreeSearch(RBTree*, int);

void RBTreeCheckInsert(RBTree*, RBNode*);
RBNode* RBTreeInsert(RBTree*, int);

RBNode* RBTreeDelete(RBTree*, int);

#endif