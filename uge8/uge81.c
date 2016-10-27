#include "uge8.h"

void llist_init(llist_t *ll) 
{
	node_t *new = malloc(sizeof(node_t));
	if (new == NULL) 
    {
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}

	new->next = NULL;
	ll->head = ll->tail = new;
}

void llist_put(llist_t *ll, void *item) 
{
	node_t *new = malloc(sizeof(node_t));
	if (new == NULL) 
    {
		perror("malloc failed");
		exit(EXIT_FAILURE);
	}
    
	new->item = *((int*)item);
	new->next = NULL;

	/* add the new node to the tail */
	ll->tail->next = new;
	ll->tail = new;
}

void *llist_pop(llist_t *ll, node_t *node) 
{
	node_t *old = ll->head;
   
    /* note that the head contains a 'dummy' node. That's why we test
     *  old->next. */

	if (old->next == NULL) 
    {
		return NULL; /* llist was empty */
	}
    

	node_t *new = old->next;
    
    while(new != NULL )
    {
        if(new == node)
        {
            old->next = new->next;
            void *item = new->item;
            free(new);
            /* update the head and free the old memory */
            return item;
        }
        
        old = old->next;
        new = new->next;


    }
    
    perror("pop failed, didn't find the node");
    exit(EXIT_FAILURE);
}

node_t *llist_search(llist_t *ll, void *item)
{

    node_t *node_search = ll->head;
    printf("searching for %d \n",*((int*)item));	
    if (node_search->next == NULL) 
    {
		return NULL; // llist was empty 
	}
    
    printf("searching for %d \n",*((int*)node_search->next->next->item));	
    
    node_search = node_search->next;
    printf("node has %d \n", *(int*)(node_search->item));
    if(*((int *)node_search->item) == (*(int*) item))
    {
        return  node_search;
    }        


    while (node_search != NULL)
    {
        printf("node has %d \n", *(int*)(node_search->item));
        if ((*(int*)node_search->item) == (*(int*)item))
        {
            return node_search;
        }
        
        node_search =node_search->next;
    }
    
    return NULL;   // did not find the item

}

void *llist_pop_item(llist_t *ll, void *item )
{
    llist_print(ll);
    return llist_pop(ll, llist_search(ll, item) );

}

void llist_print(llist_t *ll)
{
    node_t *node_search = ll->head;
    
    if (node_search->next == NULL) 
    {
        perror("print fail, tried to print a empty list");
        exit(EXIT_FAILURE);
	}

    node_search = node_search->next;
    
    while (node_search != NULL)
    {
        printf("%d ",(*(int*)node_search->item));
        
        node_search = node_search->next;
    }
    printf("\n");

}




int main(int argc, char **argv) 
{



	llist_t ll;

	llist_init(&ll);

	int val1 = 41;
    
    for(int i = 5; i>0; i--)
    {
	llist_put(&ll, &i);
    }
    puts("linked list:");
    
    llist_print(&ll);
    puts("poping elemenst list:");
    for(int jolo = 2; jolo<7; jolo++)
    {
    printf("poped %d \n", *(int*)(llist_pop_item(&ll, (void*)(&jolo))));
    }

    /*

	llist_put(&ll, &val);
	llist_put(&ll, &val);
	
    node_t *item1 = *(int *)llist_search(&ll, &val);
	assert(42 == *(int *)llist_pop(&q, item1));
    node_t *item2 = *(int *)llist_search(&ll, &val);
	assert(42 == *(int *)llist_pop(&q));
	assert(42 == *(int *)llist_pop(&q));
	assert(NULL == llist_get(&q));
	assert(NULL == llist_get(&q));
    */
	return 0;
}
