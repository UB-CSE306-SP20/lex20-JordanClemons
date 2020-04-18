#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>
#include "counts.h"

void clearBuffer(char * buffer, int s) {
  for (int i=0; i<s+1; i++) {
    buffer[i] = '\0';
  }
}

void shiftBuffer(char * buffer, int size){
  
  int offset = size;
  while(buffer[offset] != ' ' && offset != EOF){
    offset = offset + 1;
  }
  
  if(offset == EOF){ clearBuffer(buffer,size); return;}
  
  for (int j = 0; j < size; j++){
    buffer[j] = buffer[j+ offset];
  }


}

int lowerCase(int ch){
  if ('A' <= ch && ch <= 'Z') {
    ch = ch - 'A' + 'a';
  }
  return ch;
} 

/* Counts the number of times the target word
 * appears in the file whose name is filename.
 *
 * A word is a sequence of characters delimited
 * by whitespace (as determined by the library
 * function isspace, or the start of the file,
 * or the end of the file.
 *
 * Words match whether they are upper case or 
 * lower case.  For example, 'As' and 'as' match.
 *
 * https://www.tutorialspoint.com/c_standard_library/c_function_isspace.htm
 */
int countWord(char * filename, char * word) {
  int size = strlen(word)+2;
  char buffer[size+1];
  clearBuffer(buffer, size);

  char target[size+1];
  target[0] = ' ';
  target[size-1] = ' ';
  target[size] = '\0';
  for (int i=1; i<size-1; i++) { target[i] = word[i-1]; }

  FILE *fp;
  fp = fopen(filename, "r");
  int ch;
  int count = 0;  /* Initialize count to zero */
  buffer[0] = ' ';
  int k = 1;
  while ( (ch = fgetc(fp)) != EOF ) {
    // >>>> TASK STEP 11.2
    //if ('A' <= ch && ch <= 'Z') {
    //ch = ch - 'A' + 'a';
    //}
    // >>>> TASK STEP 11.2
    ch = lowerCase(ch);
    if (isspace(ch)) { ch = ' '; }
    if (k < size) {
      buffer[k++] = ch;
    }
    else {
      if (strcmp(buffer,target) == 0) {
	count++;
	clearBuffer(buffer, size);
	buffer[0] = ' ';
	k = 1;
      }
      else {
	// >>>> TASK STEP 11.1
	//for (int j=0; j<size-1; j++) {  /* change upper bound of loop from size to size-1 */
	//buffer[j] = buffer[j+1];
	//}
	// <<<< TASK STEP 11.1
	shiftBuffer(buffer, size -1);
	buffer[size-1] = ch; /* change index here to match upper bound of loop */
      }
    }
  }
  fclose(fp);
  return count;
}

