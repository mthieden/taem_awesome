#include "uge8.h"

void llist_init(llist_t *ll) 
{
	node_t *new = malloc(sizeof(node_t));
	if (new == NULL) 
    {
		puts("malloc failed");
		exit(EXIT_FAILURE);
	}

    // the next node of the linked list is set to null
	new->next = NULL;
	ll->head = ll->tail = new;
}// end of llist_init

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

	/* add the new node to the tail of the linked list*/
	ll->tail->next = new;
	ll->tail = new;
}// end of llist_put

const_t llist_pop(llist_t *ll, node_t *node) 
{
	node_t *old = ll->head;
   
    /* note that the head contains a 'dummy' node. That's why we test
     *  old->next. */

	if (old->next == NULL) 
    {
        //prints an error message and terminates
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
            // update the linked list and free the old memory 
            return item;
        }
        
        old = old->next;
        new = new->next;


    }
    
    puts("pop failed, didn't find the node");
    exit(EXIT_FAILURE);
}// end of llist_pop

node_t *llist_search(llist_t *ll, const_t item)
{

    node_t *node_search = ll->head;
    //chescks if the list is empty
    if (node_search->next == NULL) 
    {
		return NULL;  
	}
    
    // the element used to iterate
    node_search = node_search->next;
    
    while (node_search != NULL)
    {
        // memcmp takes two voidpointers and a length, and compare the data
        // from the pointer to the length
        if(memcmp((void*)&node_search->item, (void*)&item, sizeof(const_t))==0)
        {
            return node_search;
        }
        
        // node_search is set to the next element in the linked list
        node_search =node_search->next;
    }
    
    return NULL;   // did not find the item

}//end of llist_search

const_t llist_pop_item(llist_t *ll, const_t item )
{
    return llist_pop(ll, llist_search(ll, item) );

}//end of llist_pop_item

void llist_print(llist_t *ll)
{
    // node_search is set to the first element of the linked list
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

}//end of llist_print


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
 
 
         //Tokenize file_input, at "," and insert the elements into the linked list  
         char *tokenPtr = strtok(file_input, ",");
         strcpy(contestant.name, tokenPtr);
 
         tokenPtr = strtok(NULL, ",");
         contestant.accScore = atoi(tokenPtr); // never use atoi if you like your clients :(
 
         tokenPtr = strtok(NULL, ",");
         contestant.ausScore = atoi(tokenPtr);
 
         tokenPtr = strtok(NULL, ",");
         contestant.endScore = atoi(tokenPtr);
         
         llist_put(ll, contestant);
            

   }

   fclose(fp);
}// end of read_data

void llist_summary(llist_t *ll)
{
    node_t *node_search = ll->head;
    
    int acc_min, acc_max, acc_ave = 0;
    int aus_min, aus_max, aus_ave = 0;
    int end_min, end_max, end_ave = 0;
    int i = 0;

    if (node_search->next == NULL) 
    {
        puts("print fail, tried to print a empty list");
        exit(EXIT_FAILURE);
	}
    node_search = node_search->next;
    acc_min = acc_max = node_search->item.accScore; 
    aus_min = aus_max = node_search->item.ausScore;
    end_min = end_max = node_search->item.endScore;
    

    while (node_search != NULL)
    {  
        //checks acc value and find max and minvalues 
        if(acc_min > node_search->item.accScore)
        {
            acc_min = node_search->item.accScore;
        }
        if(acc_max < node_search->item.accScore)
        {
            acc_max = node_search->item.accScore;
        }
        // add element to calculate average
        acc_ave += node_search->item.accScore;


        //checks aus value and find max and minvalues 
        if(aus_min > node_search->item.ausScore)
        {
            aus_min = node_search->item.ausScore;
        }
        if(aus_max < node_search->item.ausScore)
        {
            aus_max = node_search->item.ausScore;
        }
        aus_ave += node_search->item.ausScore;


        //checks end value and find max and minvalues 
        if(end_min > node_search->item.endScore)
        {
            end_min = node_search->item.endScore;
        }
        if(end_max < node_search->item.endScore)
        {
            end_max = node_search->item.endScore;
        }
        end_ave += node_search->item.endScore;


        i++;
        node_search = node_search->next;
    }
    //calculate the average
    float acc_average = (float)acc_ave/(float)i; 
    float aus_average = (float)aus_ave/(float)i;
    float end_average = (float)end_ave/(float)i;

    //prints the found values
    printf("%s %d %s %d %s %.2f %s %d \n","accScore min: ", acc_min,"accScore max: ", acc_max,"accScore average: ", acc_average,"total", acc_ave);
    printf("%s %d %s %d %s %.2f %s %d \n","ausScore min: ", aus_min,"ausScore max: ", aus_max,"ausScore average: ", aus_average,"total", aus_ave);
    printf("%s %d %s %d %s %.2f %s %d \n","endScore min: ", end_min,"endScore max: ", end_max,"endScore average: ", end_average,"total", end_ave);
}// end of llist_summary


int main(int argc, char **argv) 
{

    char *file = "data.csv";
	llist_t ll;

	llist_init(&ll);
    read_data(file,&ll);    
    puts("printing linked list");
    llist_print(&ll); 
    
    puts("printing linked list");
    llist_summary(&ll);
    
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
