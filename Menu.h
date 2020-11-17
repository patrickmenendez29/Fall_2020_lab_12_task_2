//
// Created by Patrick  Menéndez on 11/16/20.
//

#include <stdio.h>
#include "linkedlist.h"
#include "database.h"

#ifndef LAB_12_TASK_2_MENU_H
#define LAB_12_TASK_2_MENU_H

struct node *prompt_node (){
    struct node *new;

    char name[PLANT_NAME_LENGTH];
    int height;
    printf("Please enter the name\n");
    scanf("%s",name);
    printf("Please enter height\n");
    scanf("%d",&height);
    initialize_node(&new,name,height);
    return new;
}

void start_menu(struct node **root){
    int arg;

    load_database(root);

    do{
        save_database(*root);
        display_list(*root);
        printf("Please select one of the following:\n\
        0:Exit and save\n\
        1:Add plant (front)\n\
        2:Add plant (end)\n\
        3:Search plant\n\
        4:Swap\n");

        scanf("%d",&arg);


        struct node *new;
        switch (arg) {

            case 0:
                break;
            case 1:
                printf("");
                new = prompt_node();
                add_front(root,new);
                save_database(*root);
                printf("Plant added!\n");
                break;
            case 2:
                printf("");
                new = prompt_node();
                add_end(root,new);
                save_database(*root);
                printf("Plant added!\n");
                break;
            case 3:
                printf("Please enter the name of the plant\n");
                char name[PLANT_NAME_LENGTH];
                scanf("%s",name);
                search(*root,name);
                break;
            case 4:
                printf("Please enter name 1\n");
                char name_1[PLANT_NAME_LENGTH];
                scanf("%s",name_1);
                printf("Please enter name 2\n");
                char name_2[PLANT_NAME_LENGTH];
                scanf("%s",name_2);
                swap_in_list(root,name_1,name_2);
                printf("List updated\n");
                break;
            default:
                break;
        }
    } while(arg);
}

#endif //LAB_12_TASK_2_MENU_H
