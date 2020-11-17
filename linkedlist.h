//
// Created by Patrick on 11/16/2020.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#ifndef LAB_12_TASK_2_LINKEDLIST_H
#define LAB_12_TASK_2_LINKEDLIST_H
#define PLANT_NAME_LENGTH 20

struct node {
    struct node *next;
    struct node *previous;
    char name[PLANT_NAME_LENGTH];
    int height;

};

void add_front(struct node **, struct node *);
void add_end(struct node **root, struct node *new);
struct node *search(struct node *, char []);
void swap(struct node **, struct node **);
void swap_in_list(struct node **, char [], char []);
void display_list(struct node *);
void create_empty_note (struct node **);
void initialize_node(struct node **, char [PLANT_NAME_LENGTH], int );

void add_front(struct node **root, struct node *new){

    new->next = (*root);
    (*root) = new;

}

void add_end(struct node **root, struct node *new)
{


    if (*root == NULL)  //if root is null, set root to new
    {
        *root = new;
        return;
    }

    struct node *current = *root;


    while (current->next != NULL){      //while current is not last
        current = current->next;

    }

    current->next = new;        //set value to the last node
    new->previous = current;
}

void display_list(struct node *root){
    if (root == NULL){
        return;
    }
    printf("%s, %d\n",root->name, root->height);
    display_list(root->next);

}

void create_empty_note (struct node **n){
    *n = (struct node *) malloc(sizeof(struct node));
    (*n)->next = NULL;
    (*n)->previous = NULL;

}       //used to create a null pointer, no name and height

void initialize_node(struct node **n, char name[PLANT_NAME_LENGTH], int height){
    create_empty_note(n);
    strcpy((*n)->name,name);
    (*n)->height = height;

}       //used when the name and height are known

void swap (struct node **node_1, struct node **node_2){
    struct node **temp = node_1;
    *node_1 = *node_2;
    *node_2 = *temp;
}
void swap_in_list(struct node **root, char name_1[],char name_2[]){

    struct node *temp = *root;
    struct node **node_1;
    struct node **node_2;

    while (temp != NULL){
        if (strcmp(temp->name,name_1) == 0){
            node_1 = &temp;
            //printf("Match for node 1 found\n");
            break;
        }
        temp = temp->next;
    }

    temp = *root;
    while (temp != NULL){
        if (strcmp(temp->name,name_2) == 0){
            node_2 = &temp;
            printf("match for node 2 found\n");
        }
        temp = temp->next;
    }
    if (node_2 == NULL || node_1 == NULL){
        printf("No match found for either value\n");
        exit(1);
    }

    swap(node_1,node_2);


}

struct node *search (struct node *root, char name[]){

    int res = strcmp(root->name,name);

    if (root->next == NULL && res != 0){
        printf("Error, could not find the plant with name %s\n",name);
        exit(1);
    } else if (res == 0){
        printf("plant name: %s, height: %d\n",root->name, root->height);
        return root;
    }
    search(root->next,name);

    return NULL;
}

#endif //LAB_12_TASK_2_LINKEDLIST_H
