#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int key;
    struct Node* next;
};
 

void printRandom(struct Node *head)
{
    
    if (head == NULL)
       return;
 
    
 
   
    int result = head->key;
 
    
    struct Node *current = head;
    int n;
    for (n=2; current!=NULL; n++)
    {
        // change result with probability 1/n
        if (rand() % n == 0)
           result = current->key;
 
        // Move to next node
        current = current->next;
    }
 
    printf("Randomly selected key is %d\n", result);
}


struct Node *newNode(int new_key)
{
    /* allocate node */
    struct Node* new_node =
        (struct Node*) malloc(sizeof(struct Node));
 
    /* put in the key  */
    new_node->key  = new_key;
    new_node->next =  NULL;
 
    return new_node;
}
 
 
/* Function to insert a node at the beginning of linked list */
void push(struct Node** head_ref, int new_key)
{
    /* allocate node */
    struct Node* new_node = new Node;
 
    /* put in the key  */
    new_node->key  = new_key;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}

int main()
{
    struct Node *head = NULL;
    int number_of_nodes;
    cin >> number_of_nodes;
    for (int i = 0; i < number_of_nodes; i++)
    {
        int x;
        cin >> x;
        push(&head, x);
    }
    
    printRandom(head);
 
    return 0;
    }
