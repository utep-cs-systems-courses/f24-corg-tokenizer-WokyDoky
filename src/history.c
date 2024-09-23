#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"


/* Initialize the linked list to keep the history. */
  List* init_history(){
    List *list = (List *)malloc(sizeof(List));
    if (list != NULL) {
        list->root = NULL; //List.root = null; in java. 
    }
    return list;
  }

  /* Add a history item to the end of the list.
    List* list - the linked list
    char* str - the string to store
  */
  void add_history(List *list, char *str){
    if (list == NULL) return;

    Item *newItem = (Item *)malloc(sizeof(Item));
    newItem->str = str; //Posible strdup(str);

    if (list->root == NULL) {
        newItem->id = 1;
        list->root = newItem;
    } else {
        Item *current = list->root;
        while (current->next != NULL) {
            current = current->next;
        }
        newItem->id = current->id + 1;
        current->next = newItem;
    }

  }

  /* Retrieve the string stored in the node where Item->id == id.
    List* list - the linked list
    int id - the id of the Item to find */
  char *get_history(List *list, int id){
    if (list == NULL) return NULL;
    Item *current = list->root;
    while (current -> next != NULL) {
        if (current -> id == id) return current -> str;
        current = current->next;
    }
    return NULL; //Not found.  
    
  }

  /*Print the entire contents of the list. */
  void print_history(List *list){
    if (list == NULL) return;
    Item *current = list->root;
    while (current -> next != NULL) {
        printf("H[%d]: %s \n", current -> id, current -> str);
        current = current->next;
    }
  }

  /*Free the history list and the strings it references. */
  void free_history(List *list){
    if (list == NULL) return;

    Item *current = list->root;
    while (current != NULL) {
        Item *nextItem = current->next;
        free(current->str); // Free the duplicated string
        free(current);      // Free the node itself
        current = nextItem;
    }
    free(list); // Free the list structure itself
  }