#include"assambler.h"
/*====================================================================================================================================================================*/
struct extern_node{
    char* label;
    int address;
    struct extern_node* next;
    struct extern_node* prev;
} ;

 struct ExternList {
    ExternNode* head;
} ;
/*====================================================================================================================================================================*/
 struct entry_node{
    char* label;
    struct entry_node* next;
} ;

 struct EntryList {
    EntryNode* head;
} ;
/*====================================================================================================================================================================*/
 struct jump_node{
    char* label;
    struct jump_node* next;
} ;

 struct JampList {
   JampNode* head;
} ;
/*===================================================================================================================================================================*/
void set_next_node(EntryNode *node, EntryNode *next_node)
{node->next = next_node;}
/*===================================================================================================================================================================*/
EntryNode *get_next_node(EntryNode *node)
{return node->next;}
/*===================================================================================================================================================================*/
char *get_label(EntryNode *node)
{return node->label;}
/*===================================================================================================================================================================*/
void set_label(EntryNode *node, char *label)
{node->label = label;}
/*===================================================================================================================================================================*/
ExternNode* get_extern_list_head(ExternList* list) 
{return list->head;}
/*===================================================================================================================================================================*/
void set_extern_list_head(ExternList* list, ExternNode* new_head)
{list->head = new_head;}
/*===================================================================================================================================================================*/
EntryNode* get_entry_list_head(EntryList* list)
{return list->head;}
/*===================================================================================================================================================================*/
void set_entry_list_head(EntryList* list, EntryNode* new_head)
{list->head = new_head;}
/*===================================================================================================================================================================*/JampNode* get_jamp_list_head(JampList* list)
{return list->head;}
/*===================================================================================================================================================================*/
void set_jamp_list_head(JampList* list, JampNode* new_head)
{list->head = new_head;}
/*===================================================================================================================================================================*/
ExternList* create_extern_list()
{
    ExternList* list = (ExternList*)malloc(sizeof(ExternList));
    if (list == NULL) {
        printf("Error: Failed to allocate memory for list\n");
        exit(1);
    }
    list->head = NULL;
    return list;
}
/*====================================================================================================================================================================*/
void add_extern_node(ExternList* list, char* label) {
    ExternNode* new_node = (ExternNode*)malloc(sizeof(ExternNode));
    if (new_node == NULL) {
        printf("Error: Failed to allocate memory for new list node\n");
        return;
    }
    new_node->label = (char*)malloc(strlen(label) + 1);
    if (new_node->label == NULL) {
        printf("Error: Failed to allocate memory for label\n");
        return;
    }
    strcpy(new_node->label, label);
    new_node->address = 0;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (list->head == NULL)
    {
        list->head = new_node;
    } else
    {
        ExternNode* current = list->head;
        while (current->next != NULL) 
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}
/*====================================================================================================================================================================*/
void update_address_in_list_by_name(ExternList* list, char* label, int address) {

    ExternNode* current = find_extern_node(list->head, label);
    if (current != NULL) {
        while (current->next != NULL && strcmp(current->next->label, label) == 0) {
            current = current->next;
        }
        ExternNode* new_node = (ExternNode*)malloc(sizeof(ExternNode));
        if (new_node == NULL) {
            printf("Error: Failed to allocate memory for new list node\n");
            return;
        }
        new_node->label = (char*)malloc(strlen(label) + 1);
        if (new_node->label == NULL) {
            printf("Error: Failed to allocate memory for label\n");
            return;
        }
        strcpy(new_node->label, label);
        new_node->address = address;
        new_node->next = current->next;
        new_node->prev = current;

        if (current->next != NULL) {
            current->next->prev = new_node;
        }
        current->next = new_node;
    } else {
        printf("Label %s not found in list\n", label);
    }
}

/*====================================================================================================================================================================*/
void print_extern_list(ExternList * list)
    {
        ExternNode *current = list->head;
        printf("Extern\n");
        while (current != NULL)
        {
            printf("%s: %d\n", current->label, current->address);
            current = current->next;
        }
    }
/*===================================================================================================================================================================*/
void clear_extern_list(ExternList * list)
    {
        ExternNode *current = list->head;
        while (current != NULL)
        {
            ExternNode *next = current->next;
            free(current->label);
            free(current);
            current = next;
        }
        list->head = NULL;
	free(list);
    }
/*===================================================================================================================================================================*/
 ExternNode *find_extern_node(ExternNode * head, char *label)
    {
        ExternNode *current = head;
        while (current != NULL)
        {
            if (strcmp(current->label, label) == 0)
            {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
/*===================================================================================================================================================================*/
EntryList* create_entry_list() {
    EntryList* list = (EntryList*)malloc(sizeof(EntryList));
    if (list == NULL) {
        printf("Error: Failed to allocate memory for list\n");
        exit(1);
    }
    list->head = NULL;
    return list;
}
/*===================================================================================================================================================================*/
void add_entry_label(EntryList * list, char *label)
    {
        EntryNode *new_node = (EntryNode *)malloc(sizeof(EntryNode));
        if (new_node == NULL)
        {
            printf("Error: Failed to allocate memory for new list node\n");
            exit(1);
        }
        new_node->label = (char *)malloc(strlen(label) + 1);
        if (new_node->label == NULL)
        {
            printf("Error: Failed to allocate memory for label\n");
            exit(1);
        }
        strcpy(new_node->label, label);
        new_node->next = NULL;

        if (list->head == NULL)
        {
            list->head = new_node;
        }
        else
        {
            EntryNode *current = list->head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new_node;
        }
    }
/*===================================================================================================================================================================*/
 void print_entry_list(EntryList * list)
    {
        printf("Entry\n");
        EntryNode *current = list->head;
        while (current != NULL)
        {
            printf("%s\n", current->label);
            current = current->next;
        }
    }
/*===================================================================================================================================================================*/
void free_entry_list(EntryList * list)
    {
        EntryNode *current = list->head;
        while (current != NULL)
        {
            EntryNode *next = current->next;
            free(current->label);
            free(current);
            current = next;
        }
        list->head = NULL;
	free(list);
    }
/*===================================================================================================================================================================*/
 EntryNode *find_entry_node(EntryNode * head, char *label)
    {
        EntryNode *current = head;
        while (current != NULL)
        {
            if (strcmp(current->label, label) == 0)
            {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
/*===================================================================================================================================================================*/
 JampList *create_jump_list()
    {
        JampList *list = (JampList *)malloc(sizeof(JampNode));
        if (list == NULL)
        {
            printf("Error: Failed to allocate memory for list\n");
            exit(1);
        }
        list->head = NULL;
        return list;
    }
/*===================================================================================================================================================================*/
void add_jump_label(JampList * list, char *label)
    {
        JampNode *new_node = (JampNode *)malloc(sizeof(JampNode));
        if (new_node == NULL)
        {
            printf("Error: Failed to allocate memory for new list node\n");
            return;
        }
        new_node->label = (char *)malloc(strlen(label) + 1);
        if (new_node->label == NULL)
        {
            printf("Error: Failed to allocate memory for label\n");
            return;
        }
        strcpy(new_node->label, label);
        new_node->next = NULL;

        if (list->head == NULL)
        {
            list->head = new_node;
        }
        else
        {
            JampNode *current = list->head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = new_node;
        }
    }
/*===================================================================================================================================================================*/
void print_jamp_list(JampList * list)
    {
        printf("Jamp\n");
        JampNode *current = list->head;
        while (current != NULL)
        {
            printf("%s\n", current->label);
            current = current->next;
        }
    }
/*===================================================================================================================================================================*/
void free_jamp_list(JampList * list)
    {
        JampNode *current = list->head;
        while (current != NULL)
        {
            JampNode *next = current->next;
            free(current->label);
            free(current);
            current = next;
        }
        list->head = NULL;
	free(list);
    }
/*===================================================================================================================================================================*/
JampNode *find_jamp_node(JampNode * head, char *label)
    {
        JampNode *current = head;
        while (current != NULL)
        {
            if (strcmp(current->label, label) == 0)
            {
                return current;
            }
            current = current->next;
        }
        return NULL;
    }
/*===================================================================================================================================================================*/
void process_file(ExternList* extern_list, const char* input_file_name) {
    FILE* input_file = fopen(input_file_name, "r");
    if (input_file == NULL) {
        printf("Error: Failed to open file '%s'\n", input_file_name);
        return;
    }

    char* output_file_name = add_ext_to_filename(input_file_name, ".ext");
    FILE* out_file = fopen(output_file_name, "w");
    if (out_file == NULL) {
        printf("Error: Failed to open file '%s'\n", output_file_name);
        return;
    }

    write_extern_list_sorted(extern_list, out_file);

    fclose(input_file);
    fclose(out_file);
    free(output_file_name);
}
/*===================================================================================================================================================================*/
void write_extern_list_sorted(ExternList* extern_list, FILE* out_file) {
    if (extern_list == NULL || out_file == NULL) {
        return;
    }

   
    ExternNode* current = extern_list->head;
    while (current != NULL) {
        if (current->address != 0) {
            break;
        }
        current = current->next;
    }
    if (current == NULL) {
        return;  
    }

    int all_written;
    do {
        all_written = 1;
        ExternNode* current = extern_list->head;
        ExternNode* min_node = NULL;

        while (current != NULL) {
            if (current->address != 0 && (min_node == NULL || current->address < min_node->address)) {
                min_node = current;
            }
            current = current->next;
        }

        if (min_node != NULL) {
            all_written = 0;
            fprintf(out_file, "%s  %d\n", min_node->label, min_node->address);
            min_node->address = 0;
        }
    } while (!all_written);
}
/*===================================================================================================================================================================*/

/*===================================================================================================================================================================*/
