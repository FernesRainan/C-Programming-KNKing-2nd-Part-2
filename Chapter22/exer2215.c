// Write calls of fseek that perform the following file-positioning operations on a binary file
// whose data is arranged in 64-byte "records". use fp as the file pointer in each case. 

// Move to beginning of record n. (Assume that the first record in the file is record 0)
fseek(fp, n * 64L, SEEK_SET);

// Move to the beginning of the last record in the file
fseek(fp, -64L, SEEK_END);

// Move forward one record. 
fseek(fp, 64L, SEEK_CUR);

// Move backweard two records.
fseek(fp, -128L, SEEK_CUR);

