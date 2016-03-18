// Find the error in the following porgram fragment and show how to fix it. 

FILE *fp;

if (fp = fopen(filename, "r")) {
	read characters until end-of-file;
}
fclose (fp);

// Fix

FILE *fp;

if (fp = fopen("filename", "r")) {
	read characters until end-of-file;
}
fclose (fp);
