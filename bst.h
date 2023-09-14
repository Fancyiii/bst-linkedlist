/** @addtogroup [C] [C: C Programming Exercise]
* [C Programming Exerceise]
* @{
*/

/*
 * Copyright (C) 2023 Creative Technology Ltd.
 * All Rights Reserved.
 *
 * This software and its associated documentation may contain some
 * proprietary, confidential and trade secret information of
 * Creative Technology Ltd. and except as provided by written agreement with
 * Creative Technology Ltd.
 *
 * a)   no part may be disclosed, distributed, reproduced, transmitted,
 *      transcribed, stored in a retrieval system, adapted or translated
 *      in any form or by any means electronic, mechanical, magnetic,
 *      optical, chemical, manual or otherwise,
 *
 *      and
 *
 * b)   the recipient is not entitled to discover through reverse
 *      engineering or reverse compiling or other such techniques or
 *      processes the trade secrets contained therein or in the
 *      documentation.
 */

#ifndef _BST_H
#define _BST_H

struct Node {
	int data;
	struct Node* left;
	struct Node* right;
};

struct Node* NewNode(int key); /* Helper Function to Insert a new Node. */

struct Node* Insert(struct Node* root, int key); /*Insert the value key to the appropriate place in the BST.*/

struct Node* RemoveKey(struct Node* root, int key); /*remove the value key from the tree.*/

struct Node* Search(struct Node* root, int key); /* Return the Node of the tree which has the value key.*/

struct Node* FindMin(struct Node* root); /* Return the minimum value in the tree.*/

struct Node* FindMax(struct Node* root); /* Return the maximum value in the tree. */

void InOrderTraversal(struct Node* root); /* Print the in-order traversal of the tree. */

void PreOrderTraversal(struct Node* root); /* Print the pre-order traversal of the tree. */

void PostOrderTraversal(struct Node* root); /* Print the post-order traversal of the tree. */

void KeysLessThan(struct Node* root, int key); /* Return sorted list of keys that is smaller than the specified key. */

void KeysMoreThan(struct Node* root, int key); /* Return sorted list of keys that is smaller than the specified key. */

#endif


