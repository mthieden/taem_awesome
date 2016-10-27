#include "uge8.h"

void llist_init(llist_t *ll) 
{
	node_t *new = malloc(sizeof(node_t));
	if (new == NULL) 
    {
		puts("malloc failed");
		exit(EXIT_FAILURE);
	}

	new->next = NULL;
	ll->head = ll->tail = new;
}

void llist_put(llist_t *ll, const_t item) 
{
	node_t *new = malloc(sizeof(node_t));
	if (new == NULL) 
    {
		puts("malloc failed");
		exit(EXIT_FAILURE);
	}
    new->item = item;
	new->next = NULL;

	/* add the new node to the tail */
	ll->tail->next = new;
	ll->tail = new;
}

const_t llist_pop(llist_t *ll, node_t *node) 
{
	node_t *old = ll->head;
   
    /* note that the head contains a 'dummy' node. That's why we test
     *  old->next. */

	if (old->next == NULL) 
    {
        puts("pop failed, empty list");
        exit(EXIT_FAILURE);
	}
    

	node_t *new = old->next;
    
    while(new != NULL )
    {
        if(new == node)
        {
            old->next = new->next;
            const_t item = new->item;
            free(new);
            /* update the head and free the old memory */
            return item;
        }
        
        old = old->next;
        new = new->next;


    }
    
    puts("pop failed, didn't find the node");
    exit(EXIT_FAILURE);
}

node_t *llist_search(llist_t *ll, const_t item)
{

    node_t *node_search = ll->head;
    if (node_search->next == NULL) 
    {
		return NULL; // llist was empty 
	}
    
    
    node_search = node_search->next;
    
    if(memcmp((void*)&node_search->item, (void*)&item, sizeof(const_t))==0)
    {
        return  node_search;
    }        


    while (node_search != NULL)
    {
        if(memcmp((void*)&node_search->item, (void*)&item, sizeof(const_t))==0)
        {
            return node_search;
        }
        
        node_search =node_search->next;
    }
    
    return NULL;   // did not find the item

}

const_t llist_pop_item(llist_t *ll, const_t item )
{
    return llist_pop(ll, llist_search(ll, item) );

}

void llist_print(llist_t *ll)
{
    node_t *node_search = ll->head;
    
    if (node_search->next == NULL) 
    {
        puts("print fail, tried to print a empty list");
        exit(EXIT_FAILURE);
	}

    node_search = node_search->next;
    
    while (node_search != NULL)
    {
        printf("name: %s \n",node_search->item.name);
        printf("%s %5d ", "acc score", node_search->item.accScore);
        printf("%20s %5d ", "aus score", node_search->item.ausScore);
        printf("%20s %5d \n\n", "end score", node_search->item.endScore);
        
        node_search = node_search->next;
    }
    printf("\n");

}


void read_data(char *file, llist_t *ll)
{

   // Declare File Position Pointer
   FILE * fp;
   fp = fopen (file, "r");
   const_t contestant;
   char file_input[64];

   // Parse every line and save in struct array
   while(!feof(fp))
   {
         // Reads to end of line, max 60 characters
         fgets(file_input, 60, fp);

         // Remove '\n' from line
         if(iscntrl(file_input[strlen(file_input) - 1])){
            file_input[strlen(file_input) - 1] = '\0';
         }
 
 
         //Tokenize r, at "," and assign to 
         char *tokenPtr = strtok(file_input, ",");
         strcpy(contestant.name, tokenPtr);
 
         tokenPtr = strtok(NULL, ",");
         contestant.accScore = atoi(tokenPtr);
 
         tokenPtr = strtok(NULL, ",");
         contestant.ausScore = atoi(tokenPtr);
 
         tokenPtr = strtok(NULL, ",");
         contestant.endScore = atoi(tokenPtr);
         
         llist_put(ll, contestant);
            

   }

   fclose(fp);
}



int main(int argc, char **argv) 
{


    char *file = "data.csv";
	llist_t ll;

	llist_init(&ll);
    read_data(file,&ll);    

    llist_print(&ll); 
    
    /* testing the different funkctions
	const_t val1 = {.name = "Ben and jerry", .accScore = 42, .ausScore = 432, .endScore = 1011};
	const_t val2 = {.name = "karl johan", .accScore = 45, .ausScore = 303, .endScore = 404};
	const_t val3 = {.name = "jensen bofhus", .accScore = 123, .ausScore = 423, .endScore = 121};
    
    for(int i = 5; i>0; i--)
    {
	    llist_put(&ll, val1);
	    llist_put(&ll, val3);
	    llist_put(&ll, val2);

    }
    puts("linked list:");
    
    llist_print(&ll);
    puts("poping elemenst list:");
    
    for(int i = 5; i>0; i--)
    {
        const_t poped = llist_pop_item(&ll, val2);
        printf("poped %s %d %d %d \n", poped.name, poped.accScore, poped.ausScore, poped.endScore);
        poped = llist_pop_item(&ll, val1);
        printf("poped %s %d %d %d \n", poped.name, poped.accScore, poped.ausScore, poped.endScore);
        poped = llist_pop_item(&ll, val3);
        printf("poped %s %d %d %d \n", poped.name, poped.accScore, poped.ausScore, poped.endScore);
    }
    llist_print(&ll);
    */
	return 0;
}
