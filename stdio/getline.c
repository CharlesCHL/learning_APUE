

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv)
{
	if(argc < 2)
	{
		fprintf(stderr, "Usage...");
		exit(1);
	}

	FILE* fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		perror("fopen()");
		exit(2);
	}

	char* linebuf = NULL;
	size_t linesize = 0;
	

	while(1)
	{
		if(getline(&linebuf, &linesize, fp) < 0)
			break;
		printf("%ld\n", strlen(linebuf));
		printf("%ld\n", linesize);	
	}


	fclose(fp);

	exit(0);

}




