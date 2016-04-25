// Maintains a parts database (linked list version)

// Modify the inventory2.c program of Section 17.5 by adding the d (dump) and r
// (restore) operations described in Programming Project 8. Since the part structures aren't
// stored in an array, the d operation can't save them all by a signle call of fwrite. Instead, it
// will need to visit each node in the linked list, writing the part number, part name, and
// quantity on hand to a file. (Don't save the next pointer; it won't be valid once the program
// terminates) As it reads parts from a file, the r operation will rebuild the list one node at a time. 

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define NAME_LEN 25

struct part {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
	struct part *next;
};

struct part *inventory = NULL;                  // points to first part

int read_line(char str[], int n);
struct part *find_part(int number);
void insert(void);
void search(void);
void update(void);
void print(void);
void dump(void);
void restore(void);

// main: Prompts the user to enter an operation code, 
//       then calls a function to perform the requested
//       action. Repeats until the user enters the
//       command 'q'. Prints an error message if the user
//       enters an illegal code.

int main (void)
{
	char code;
	
	for (;;){
		printf("Enter operation code: ");
		scanf(" %c", &code);
		while (getchar() != '\n')                     // skips to end of line
		;
		switch (code) {
			case 'i': insert();
				        break;
		  case 's': search();
		  	        break;
		  case 'u': update();
		  	        break;
		  case 'p': print();
		  	        break;
		  case 'd': dump();
		  					break;
		  case 'r': restore();
		  					break;		  					
		  case 'q': return 0;
		  default: printf("Illegal code\n");
		}
		printf("\n");
	}
}

int read_line (char str[], int n)
{
	int ch, i = 0;
	
	while (isspace(ch = getchar()))
	;
	while (ch != '\n' && ch != EOF) {
		if (i < n)
			str[i++] = ch;
		ch = getchar();
	}
	str[i] = '\0';
	return i;
}

// find_part: Looks up a part number in the inventory
//            list. Returns a pointer to the node
//            containing the part number; if the part
//            number is not found, returns NULL.
struct part *find_part(int number)
{
	struct part *p;
	
	for (p = inventory;
	     p != NULL && number > p->number;
	     p = p->next)
	     ;
	if (p != NULL && number == p->number)
		return p;
	return NULL;
}

// insert: Prompts the user for information about a new
//         part and then inserts the part into the
//         inventory list; the list remains sorted by
//         part number. Prints an error message and
//         returns prematurely if the part already exists
//         or space could not be allocated for the part. 
void insert(void)
{
	struct part *cur, *prev, *new_node;
	
	new_node = malloc (sizeof(struct part));
	if (new_node == NULL) {
		printf("Database is full; can't add more parts.\n");
		return ;
	}
	
	printf("Enter part number: ");
	scanf("%d", &new_node->number);
	
	for (cur = inventory, prev = NULL;
	     cur != NULL && new_node->number > cur->number;
	     prev = cur, cur = cur->next)
	     ;
	if (cur != NULL && new_node->number == cur->number) {
		printf("Part already exists.\n");
		free(new_node);
		return;
	}
	
	printf("Enter part name: ");
	read_line(new_node->name, NAME_LEN);
	printf("Enter quantity on hand: ");
	scanf("%d", &new_node->on_hand);
	
	new_node->next = cur;
	if (prev == NULL)
		inventory = new_node;
	else
		prev->next = new_node;
}

// search: Prompts the user to enter a part number, then
//         looks up the part in the database. If the part
//         exists, prints the name and quantity on hand;
//         if not, prints an error message.
void search(void)
{
	int number;
	struct part *p;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL) {
		printf("Part name: %s\n", p->name);
		printf("Quantity on hand: %d\n", p->on_hand);
	} else
		printf("Part not found.\n");
}

// update: Prompts the user to enter a part number. 
//         Prints an error message if the part doesn't
//         exist; otherwise, prompts the user to enter
//         change in quantity on hand and updates the
//         database. 
void update(void)
{
	int number, change;
	struct part *p;
	
	printf("Enter part number: ");
	scanf("%d", &number);
	p = find_part(number);
	if (p != NULL) {
		printf("Enter change in quantity on hand: ");
		scanf("%d", &change);
		p->on_hand += change;
	} else
		printf("Part not found.\n");
}

// print: Prints a listing of all parts in the database, 
//        showing the part number, part name, and
//        quantity on hand. Part numbers will appear in 
//        ascending order. 
void print(void)
{
	struct part *p;
	
	printf("Part Number    Part Name                     "
	       "Quantity on Hand\n");
	for (p = inventory; p != NULL; p = p->next)
		printf("%7d        %-25s%11d\n", p->number, p->name, 
		       p->on_hand);
}


// dump: The d operation can't save them all by a single
//       call of fwrite. Instead, it will need to visit
//       each node in the linked list, writing the part
//       number, part name, and quantity on hand to a file
//       (Don't save the next pointer)
void dump(void)
{
	FILE *fp;
	char filename[NAME_LEN+1];
	struct part *p;
	
	struct part2 {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
	} temp;
	
	printf("Enter name of output file: ");
	scanf("%s", filename);
	
	if ((fp = fopen(filename, "wb")) == NULL) {
		fprintf(stderr, "Can't open inventory file\n");
		exit(EXIT_FAILURE);
	}
	
	for (p = inventory; p != NULL; p = p->next) {
		temp.number = p->number;
		strcpy(temp.name, p->name);
		temp.on_hand = p->on_hand;
		fwrite(&temp, sizeof(struct part2), 1, fp);
	}
	
	fclose(fp);
	
	return;

}

// restore: As it reads parts from a file, the r operation
//          will rebuild the list one node at a time. 
void restore(void)
{
	FILE *fp;
	char filename[NAME_LEN+1];
	int num_read;
	
	struct part2 {
	int number;
	char name[NAME_LEN+1];
	int on_hand;
	} temp;
	
	struct part *cur, *prev, *new_node;
	
	printf("Enter name of input file: ");
	scanf("%s", filename);

	if ((fp = fopen(filename, "rb")) == NULL) {
		fprintf(stderr, "Can't open inventory file\n");
		exit(EXIT_FAILURE);
	}
	
	num_read = fread(&temp, sizeof(struct part2), 1, fp);
	
	while (num_read == 1) {
		new_node = malloc(sizeof(struct part));
		if (new_node == NULL) {
			fprintf(stderr, "Database is full; can't restore.\n");
			return;
		}
		
		new_node->number = temp.number;
		
		for (cur = inventory, prev = NULL;
	     cur != NULL && new_node->number > cur->number;
	     prev = cur, cur = cur->next)
	     ;
	  
		strcpy(new_node->name, temp.name);
		new_node->on_hand = temp.on_hand;
		
		new_node->next = cur;
		if (prev == NULL)
			inventory = new_node;
		else
			prev->next = new_node;
		
		num_read = fread(&temp, sizeof(struct part2), 1, fp);
	}
	
	fclose(fp);
	
	return;
}

	  
