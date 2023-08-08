#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "task_list.h"

typedef struct Task task_t;
typedef struct Node node_t;

unsigned int list_enumerate(node_t *head) {
    unsigned int i = 0;
    node_t *p = head;
    while(p != NULL) {
        i++;
        p = p->next;
    }
    return i;
}

task_t *task_query_list(node_t *head, unsigned int id) {
    task_t *task;
    node_t *p = head;
    while(p != NULL) {
        if(p->task->id == id) {
            task = p->task;
            break;
        }
        p = p->next;
    }
    return task;
}

void task_print(task_t *task) {
    printf("%d | %s | %s | %s\n",
            task->id,
            task->title,
            task->description,
            task->is_complete ? "Complete" : "Incomplete"
          );
}

void task_list_print(node_t *head) {
    for(node_t *p = head; p != NULL; p = p->next) {
        task_print(p->task);
    }
    printf("\n");
}

void task_list_append(node_t **head, task_t *task) {
    node_t *new_node = malloc(sizeof(node_t));
    if(new_node == NULL) exit(0);

    new_node->task = task;
    new_node->next = NULL;

    if(*head == NULL) {
        *head = new_node;
        return;
    }

    node_t *p = *head;
    while(p->next != NULL) p = p->next;

    p->next = new_node;
}

task_t *task_new(unsigned int id, char* title, char* description, bool is_complete) {
    task_t *new_task = malloc(sizeof(task_t));
    if(new_task == NULL) exit(0);

    new_task->id = id;
    new_task->title = malloc(strlen(title) + 1);        // +1 str terminator
    new_task->description = malloc(strlen(description) + 1);
    strcpy(new_task->title, title);
    strcpy(new_task->description, description);
    new_task->is_complete = is_complete;

    return(new_task);
}

/* this here doesnt work and i dont know why :(
void task_add_new_to_list(node_t **head, char *title, char *description) {
    unsigned int id = list_enumerate(*head);
    task_t *new = task_new(id, title, description, false);
    task_list_append(head, new);
}
*/

void list_deallocate(node_t **head) {
    node_t *p = *head;
    while(p != NULL) {
        node_t *aux = p;
        task_t *task = p->task;
        p = p->next;

        free(task->title);
        free(task->description);
        free(task);
        free(aux);
    }
}

