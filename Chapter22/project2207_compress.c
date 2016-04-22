// Of the many techniques for compressing the contents of a file, one of the simplest and 
// fastest is known as run-length encoding. This technique compresses a file by replacing
// sequences of identical bytes by a pair of bytes: a repetition count followed by a byte to be
// repeated. For example, suppose that the file to be compressed begins with the following
// sequence of bytes (shown in hexadecimal):
// 46 6F 6F 20 62 61 72 21 21 21 20 20 20 20 20
// The compresssed file will contain the following bytes:
// 01 46 02 6F 01 20 01 62 01 61 01 72 03 21 05 20
// Run-length encoding works well if the original file contains many long sequences of 
// idetical bytes. In the worst case (a file with no repeated bytes), run-length encoding can
// actually double the length of the file. 
// (a) Write a program named compress_file that uses run-length encoding to compress a file
// To run compress_file, we'd use a command of the form
// compress_file original-file
// compress_file will write the compressed version of original-file to original-file.rle.
// For example, the command
// compress_file foo.txt
// will cause copress_file to write a compressed version of foo.txt to a file named
// foo.txt.rle. Hint: The program described in Programming Project 6 could be useful
// for debugging. 

#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>

#define BUFFER_SIZE BUFSIZ
#define MAX_RUN UCHAR_MAX

///////////// error.c /////////////////
void invocation_error(char *program, char *usage)
{
	fprintf(stderr, "Usage: %s %s\n", program, usage);
	exit(1);
}

void memory_error(char *file, unsigned int line, const char *func)
{
	fprintf(stderr, "Memory Allocation Failure: %s: %d in function %s()\n", file, line, func);
	exit(EXIT_FAILURE);
}

void print_error(char *program, char *s2)
{
	fprintf(stderr, "%s: %s: %s\n", program, s2, strerror(errno));
}

void exit_error(char *program, char *s2)
{
	print_error(program, s2);
	exit(EXIT_FAILURE);
}

int is_file_name_error(int e)
{
	if ((strcmp(strerror(e), "No such file or directory") == 0) ||
		  (strcmp(strerror(e), "Is a directory") == 0) ||
		  (strcmp(strerror(e), "File name too long") == 0))
		return 1;
	return 0;
}

////// run-length-encoding.c //////////
static void mem_error(int line, const char *func)
{
	fprintf(stderr, "Memory Allocation Failure: %s:%d in function %s()\n", __FILE__, line, func);
}

static int resize_buffer(unsigned char **buffer, size_t *n)
{
	*n *= 2;
	unsigned char *temp = realloc(*buffer, (*n * sizeof(buffer[0])));
	if (!temp) {
		mem_error(__LINE__, __func__);
		return -1;
	}
	*buffer = temp;
	return 0;
}

static void 
process_buffers(FILE *in, FILE *out, 
	unsigned int (*process)(unsigned char *, size_t, unsigned char *, size_t))
{
	unsigned char inbuffer[BUFFER_SIZE] = {0};
	size_t outbuffer_size = BUFFER_SIZE * 2;
	
	unsigned char *outbuffer = malloc(sizeof(unsigned char) * outbuffer_size);
	if(!outbuffer) {
		mem_error(__LINE__, __func__);
		return ;
	}
	
	size_t n_read = 0, n_written = 0;
	unsigned int n_processed;
	
	for ( ; ; ) {
		if ((n_read = fread(inbuffer, sizeof(inbuffer[0]), BUFFER_SIZE, in)) < BUFFER_SIZE) {
			if(ferror(in)) {
				print_error(__FILE__, "fread(in)");
				free(outbuffer);
				return;
			}
			if(feof(in) && n_read == 0)
				break;
		}
		
		if ((n_processed = process(inbuffer, n_read, outbuffer, outbuffer_size)) <= 0) {
			free(outbuffer);
			return;
		}
		
		n_written = fwrite(outbuffer, sizeof(outbuffer[0]), n_processed, out);
		if (n_written < n_processed || ferror(out)) {
			print_error(__FILE__, "fwrite(out)");
			free(outbuffer);
			return;
		}
	}
	free(outbuffer);
}

static unsigned int
encode(unsigned char *inbuffer, size_t n_read, unsigned char *outbuffer, size_t outbuffer_size)
{
	unsigned int n_encoded;
	unsigned char previous, occurrences = 0;
	size_t i;
	previous = inbuffer[0];
	for (n_encoded = 0, i = 0; i < n_read; i++) {
		if (previous == inbuffer[i] && occurrences < MAX_RUN) {
			occurrences++;
		}
		else {
			if (n_encoded + 2 >= outbuffer_size) {
				if(resize_buffer(&outbuffer, &outbuffer_size) != 0) {
					return -1;
				}
			}
			outbuffer[n_encoded++] = occurrences;
			outbuffer[n_encoded++] = previous;
			occurrences = 1;
		}
		previous = inbuffer[i];
	}
	
	if (i) {
		outbuffer[n_encoded++] = occurrences;
		outbuffer[n_encoded++] = previous;
	}
	
	return n_encoded;
}

static unsigned int
decode(unsigned char *inbuffer, size_t n_read, unsigned char *outbuffer, size_t outbuffer_size)
{
	unsigned int n_decoded;
	size_t run_count, i, byte;
	
	for(n_decoded = 0, run_count = 0, byte = 1; 
		byte < n_read;
		run_count += 2, byte += 2) {
			for(i = 0; i < inbuffer[run_count]; i++) {
				if (n_decoded + 1>= outbuffer_size) {
					if (resize_buffer(&outbuffer, &outbuffer_size) != 0) {
						return -1;
					}
				}
				outbuffer[n_decoded++] = inbuffer[byte];
			}
	}
	
	return n_decoded;
}

void encode_rle(FILE *in, FILE *out) 
{
	process_buffers(in, out, encode);
}
void decode_rle(FILE *in, FILE *out)
{
	process_buffers(in, out, decode);
}

#define EXT ".rle"
#define EXT_LEN strlen(EXT)

bool is_rle_file(char *filename)
{
	if (strcmp((filename + strlen(filename)) - EXT_LEN, EXT) == 0)	
		return true;
	return false;
}

char *build_output_file_name(char *input)
{
	char *output = malloc(sizeof(char) * (strlen(input) + EXT_LEN + 1));
	if(!output)
		memory_error(__FILE__, __LINE__, __func__);
		
	if(is_rle_file(input))
		strncpy(output, input, strlen(input) - EXT_LEN);
	else {
		strcpy(output, input);
		strncat(output, EXT, EXT_LEN + 1);
	}
	return output;
}

int main(int argc, char *argv[])
{
	char *program = argv[0];
	if(argc != 2)
		invocation_error(program, "[file]");
		
	char *iname = argv[1];
	FILE *istream;
	if((istream = fopen(iname, "rb")) == NULL)
		exit_error(program, iname);
		
	char *oname = build_output_file_name(iname);
	FILE *ostream;
	if ((ostream = fopen(oname, "wb")) == NULL) {
		print_error(program, oname);
		free(oname);
		if (fclose(istream) == EOF)
			exit_error(program, iname);
		exit(EXIT_FAILURE);
	}
	
	if (is_rle_file(oname))
		encode_rle(istream, ostream);
	else 
		decode_rle(istream, ostream);
		
	free(oname);
	
	if (fclose(istream) == EOF)
		print_error(program, iname);
	
	if (fclose(ostream) == EOF)
		exit_error(program, oname);
	
	return 0;
}
