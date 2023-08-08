#include <stdio.h>
#include <stdbool.h>

#include "task_list.h"

typedef struct Task task_t;
typedef struct Node node_t;

int main(int argc, char *argv[]) {
    node_t *head = NULL;

    unsigned int id;
    task_t *task;

    id = list_enumerate(head);
    task = task_new(id, "Task", "Task", false);
    task_list_append(&head, task);

    id = list_enumerate(head);
    task = task_new(id, "Title 2", "Description 2", false);
    task_list_append(&head, task);

    id = list_enumerate(head);
    task = task_new(id, "Fondle Breasts", "Find some pretty boobs and touch touch", true);
    task_list_append(&head, task);

    unsigned int query;

    task_list_print(head);

    printf("\n\n\n");

    query = 0;
    printf("%d : %p\n", query, task_query_list(head, query));
    task_print(task_query_list(head, query));

    printf("\n\n\n");

    query = 1;
    printf("%d : %p\n", query, task_query_list(head, query));
    task_print(task_query_list(head, query));

    printf("\n\n\n");

    query = 2;
    printf("%d : %p\n", query, task_query_list(head, query));
    task_print(task_query_list(head, query));

    printf("\n\n\n");

    /*
    task_add_new_to_list(&head, "Wash Dishes", "Wash the dishes please !!!");
    task_add_new_to_list(&head, "Wash Clothes", "Wash the clothes please !!!");
    */

    list_deallocate(&head);
    return 0;
}
