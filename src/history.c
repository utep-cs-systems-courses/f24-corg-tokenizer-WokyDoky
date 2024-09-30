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
    newItem->str = str;
    newItem->next = NULL;

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
char *get_history_recursive(Item *current, int id) {
    if (current == NULL) return NULL; 
    if (current->id == id) return current->str;  
    return get_history_recursive(current->next, id);
}

char *get_history(List *list, int id) {
    if (list == NULL) return NULL;
    return get_history_recursive(list->root, id);  // Start the recursion
}

  /*Print the entire contents of the list. */
  void print_history(List *list){
    if (list == NULL) return;
    

    printf("HistoryPrinter \n");
    Item *current = list->root;
    while (current != NULL) {
        printf("H[%d]: %s \n", current->id, current->str);
        current = current->next;
    }
  }

  /*Free the history list and the strings it references. */
  void free_history(List *list){
    free(list); // Free the list structure itself
  }

  //-------------------------------------------------------
  // ====================Testing==========================
  //-------------------------------------------------------

  void pruebas() {
    List *testList = init_history();
    
    add_history(testList, "The cake is a lie!");
    add_history(testList, "But it was delicious.");
    add_history(testList, "True.");
    
    printf("\n--- Testing print_history ---\n");
    print_history(testList);
    printf("Pruebas: %s", get_history(testList, 3));
    free_history(testList);
}