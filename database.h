//
// Created by Patrick on 11/16/2020.
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"

#define MAX_LINE_LENGTH 200
#define PLANT_NAME_LENGTH 20


#ifndef LAB_12_TASK_2_DATABASE_H
#define LAB_12_TASK_2_DATABASE_H

void load_database();
void save_database();

void load_database(struct node **root)
{
    FILE *fp;
    fp = fopen("Samples.csv", "r");
    if (fp == NULL)
    {
        fprintf(stderr, "Error reading file\n");
        exit(1);
    }

    char line[MAX_LINE_LENGTH];
    while (!feof(fp) && fgets(line, MAX_LINE_LENGTH, fp) != NULL)
    {
        char *value = strtok(line, ",");
        char name[PLANT_NAME_LENGTH + 1];
        strncpy(name, value, sizeof name);

        int height = atoi(strtok(NULL, ","));
        // Modify here
        // printf("%s, %i\n", name, height);

        struct node *new;

        initialize_node(&new,name,height);

        add_end(root,new);
    }

    fclose(fp);
}

void save_database(struct node *root) //does not work
{
    FILE *fp;
    fp = fopen("Samples.csv", "w");

    // Modify here
    // for each node
    struct node *temp_node;
    temp_node = root;
    while (temp_node != NULL){
        fprintf(fp, "%s,%i\n", temp_node->name, temp_node->height);
        //printf("%s %\n",temp_node->name,temp_node->height);
        temp_node = temp_node->next;
    }

    fclose(fp);
    printf("Database saved\n");
}

#endif //LAB_12_TASK_2_DATABASE_H
