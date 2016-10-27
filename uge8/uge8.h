#include <assert.h>
#include <ctype.h>
#include <error.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct contestant{
    char name[64];
    int accScore; // Accureacy score
    int ausScore; // Aussie-Round score
    int endScore; // Endurance score
} const_t;


typedef struct node {
    const_t item;
	struct node *next;
} node_t;

typedef struct llist {
	node_t	*head;
	node_t	*tail;
} llist_t;

/* llist_init initializes a new linked list */
void llist_init(llist_t *ll);

/* llist_put adds the item to the tail of the inked linkedlist */
void llist_put(llist_t *ll, const_t item);

/* llist_pop pops and returns the item of the node from the linkedlist*/
const_t  llist_pop(llist_t *ll, node_t *node_ptr);

/* llist_search returns the node with the requested item */
node_t *llist_search(llist_t *ll, const_t item);

/* llist_pop_item takes a item as input and pops the element with the item*/
const_t llist_pop_item(llist_t *ll, const_t item );
    

/* llist_print prints the linkedlist */
void llist_print(llist_t *ll);

/*   llist_summary prints max, min and average of values*/
void llist_summary(llist_t *ll);

