#include <stdio.h>
#include <stdlib.h>

int main()
{
	int max = 10;
	char *buffer;
	buffer = (char*)malloc( (max+1)* sizeof(char));
	if(buffer != NULL) {
		for(int i = 0; i < max; i++) 
			buffer[i] = 'a'+ i;

		buffer[max] = '\0';

                  // This will print out "buffer=abcdefghij"
		printf("buffer=%s\n",buffer);   

		free (buffer);
		return 0;
	}
	else {
		printf("Not enough memory\n");
		return 1;
	}
}