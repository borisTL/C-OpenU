#ifndef LIST_NAMES_H
#define LIST_NAMES_H
/*======================================================================================================================================================================
						List filedeclaring names of lists and functions that work with them

Extern:list was created for exten names

  |struct extern_node{
  |char* label;
  |int address;
  |struct extern_node* next;
  |struct extern_node* prev;} ;

  |struct ExternList {
  |ExternNode* head;}
  
Entry :the list was created for operands of type entry and is used for ent file and symbol table

  |struct entry_node{
  |char* label;
  |struct entry_node* next;} ;

  |struct EntryList {
  |EntryNode* head;};

Jump list :the list has been created to collect the names of the operands of the jump link so that only jump functions can accept operands of this type (Method table)
             the main purpose of a list is to find invalid operands in functions other than jump.

  |struct jump_node{       
  |char* label;		     
  |struct jump_node* next;} ;
			     
  |struct JampList {       
  |JampNode* head;} ;  
   
	the implementation of lists was done in a C file lists.c 
  ======================================================================================================================================================================
*/
/*	Declaration name /node of list's	
*/	typedef struct extern_node ExternNode;
	typedef struct entry_node EntryNode;
	typedef struct jump_node JampNode;

	typedef struct EntryList EntryList;
	typedef struct ExternList ExternList;
	typedef struct JampList JampList;

/*	Function for creat extern list.
*/	ExternList* create_extern_list();
/*
	Function for add new node in list.
*/	void add_extern_node(ExternList* list, char* label);
/*
	Function for update adrees in extern list after first run for extern file.
*/	void update_address_in_list_by_name(ExternList* list, char* label, int address);
/*
	Helper function for buld prodject print extern list.
*/	void print_extern_list(ExternList* list);

/*	Function for free extern kist.
*/	void clear_extern_list(ExternList* list);

/*	Function for find node in list.
*/	ExternNode* find_extern_node(ExternNode* head, char* label);


/*	Function for short and print extern in file.
*/	void write_extern_list_sorted(ExternList* extern_list, FILE* out_file);

/*	Function for extern file if we do not used extern operand in file or only line .extern XXXX we do not creat ext file.
*/	void process_file(ExternList* extern_list, const char* input_file_name);


/*	Function for creat entry list. 
*/	EntryList* create_entry_list();

/*	Function for add new node in entry list. 
*/	void add_entry_label(EntryList* list, char* label);

/*	Helper function print entry list.
*/	void print_entry_list(EntryList* list);

/*	Function for free entry list.
*/	void free_entry_list(EntryList* list);

/*	Function for find entry node in list.
*/	EntryNode* find_entry_node(EntryNode* head, char* label);

/*	Function get entry label.
*/	char *get_label(EntryNode *node);

/*	Function for set label entry. 
*/	void set_label(EntryNode *node, char *label);

/*	Function for get next node enrty. 
*/	EntryNode *get_next_node(EntryNode *node);

/*	Function for set sext entry node.
*/	void set_next_node(EntryNode *node, EntryNode *next_node);

/*	Function dor Jump list. 
*/	JampList* create_jump_list();

/*	Function add new node in jump list.
*/	void add_jump_label(JampList* list, char* label);

/*	Helper function print jamp list.
*/	void print_jamp_list(JampList* list);

/*	Function for free jump list.
*/	void free_jamp_list(JampList* list);

/*	Function for find node in jamp list.
*/	JampNode* find_jamp_node(JampNode* head, char* label);


/*	Function for get head extern list. 
*/	ExternNode* get_extern_list_head(ExternList* list);

/*	Function for set head extern list.
*/	void set_extern_list_head(ExternList* list, ExternNode* new_head);

/*	Function for get entry head.
*/	EntryNode* get_entry_list_head(EntryList* list);

/*	Function for set entry list.
*/	void set_entry_list_head(EntryList* list, EntryNode* new_head);

/*	Function for get head jamp list.
*/	JampNode* get_jamp_list_head(JampList* list);

/*	Function for set jamp list head.
*/	void set_jamp_list_head(JampList* list, JampNode* new_head);
/*====================================================================================================================================================================*/
#endif /* LIST_NAMES_H */
