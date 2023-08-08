struct Task {
    unsigned int id;
    char *title;
    char *description;
    bool is_complete;
};

struct Node {
    struct Task *task;
    struct Node *next;
};

typedef struct Task task_t;
typedef struct Node node_t;

unsigned int list_enumerate(node_t *head);
task_t *task_query_list(node_t *head, unsigned int id);

void task_print(task_t *task);
void task_list_print(node_t *head);

void task_list_append(node_t **head, task_t *task);

task_t *task_new(unsigned int id, char *title, char *description, bool is_complete);
void task_add_new_to_list(node_t **head, char *title, char *description);

void list_deallocate(node_t **head);
