/*
 * principal.c
 *
 *  Created on: 6 de jan de 2016
 *      Author: avilapm
 */


#include "arvoreAVL.h"



int main( int argc, char **argv ) {
	avl_tree_t *tree = NULL;
	int i = 0;
	int r = 0;


	tree = avl_create();


    avl_insert(tree,10);
    avl_insert(tree,5);
    avl_insert(tree,50);
    avl_insert(tree,3);
    avl_insert(tree,4);
    avl_insert(tree,60);
    avl_insert(tree,62);
    avl_insert(tree,7);


	avl_traverse_dfs( tree );

	return 0;
}