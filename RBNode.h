#pragma once

#ifndef _RBNODE_H_
#define _RBNODE_H_

#include <stdio.h>
#include <stdlib.h>

typedef struct RBNode {

	int key;
	char color;

	int lSubHeight;
	int rSubHeight;

	RBNode *parent;
	RBNode *left;
	RBNode *right;

}RBNode;

#endif