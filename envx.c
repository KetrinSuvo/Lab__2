#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib/lab2.h"

void usage()
{
	printf("Usage:\n pwdx [options] pid...\n\n Options:\n -h display this help and exit\n -V  output version information and exit\n\n");

}

int main(int argc, char const *argv[])
{

	char buff[81924]; //буфер на 8 кб
	// проверили на наличие аргументов. если их нет то вызвали usage()
	if (argc <=1 )
	{
		usage();
		return 0;
	}
	
	if (argc > 3 )
	{
		printf("Too many arguments\n");
		return 0;
	}
	
	if (strncmp(argv[1], "-h", 2) == 0)
	{
		usage();
		return 0;
	}
	
	if (strncmp(argv[1], "-V", 2) == 0)
	{
		printf("envx v0.01a by SuvorovaEA\n");
		return 0;
	}
	
	
	int result = get_env(argv[1], strlen(argv[1]), buff, sizeof(buff));

	
	if (result != 0)
		return 1;

	
	printf("%s\n",buff);


	return 0;
}

