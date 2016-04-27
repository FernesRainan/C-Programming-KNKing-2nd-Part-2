// Modify Programming Project 2 from Chapter 3 so that the program reads a series of items
// from a file and displays the data in columns. Each line of the file will have the following
// form:
// item, price, mm/dd/yyyy
// for example, suppose that the file contains the following lines:
// 583,13.5,10/24/2005
// 3912,599.99,7/27/2008
// The output of the program should have the following appearance:
// Item            Unit              Purchase
//                 Price             Date
// 583             $  13.50          10/24/2005
// 3912            $ 599.99          7/27/2008
// Have the program obtain the file name from the command line.

#include <stdio.h>
#include <stdlib.h>

#define NAME_LEN 25
#define DATA_LEN 100

int main (void)
{
    int item_number, month, day, year;
    float price;
    
    FILE *fp;
    char filename[NAME_LEN+1];
    char str[DATA_LEN+1];
    
    printf("Enter file name of item list: ");
    scanf("%s", filename);
    
    if ((fp = fopen(filename, "r")) == NULL) {
    	fprintf(stderr, "Can't open item list file.\n");
    	exit(EXIT_FAILURE);
    }
    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
    
    while (fgets(str, sizeof(str), fp)){
    	sscanf(str, "%d,%f,%d/%d/%d", &item_number, &price, 
    	                              &month, &day, &year);
	    printf("%d\t\t$%7.2f\t%d/%d/%d\n", item_number, price, month, day, year);
		}
		
    return 0;
}
