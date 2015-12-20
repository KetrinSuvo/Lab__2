#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
// хранит значение PATH_MAX - максимальное значение пути / имени файла
#include <linux/limits.h>
#include "lib/lab2.h"
// функция выводящая на экран хелп сообщение
void usage()
{
	printf("Usage:\n pwdx [options] pid...\n\n Options:\n -h display this help and exit\n -V  output version information and exit\n\n");

}

int main(int argc, char const *argv[])
{
	//выделили буфер под значение каталога. PATH_MAX означает что это максимальная длинна пути в данном дистрибутиве Linux
	char buff[PATH_MAX];

	// проверили на наличие аргументов. если их нет то вызвали usage()
	if (argc <=1 )
	{
		usage();
		return 0;
	}
	// если их слишком много напихали то сказали об этом
	if (argc > 3 )
	{
		printf("Too many arguments\n");
		return 0;
	}
	// если в роли аргумента выпал -h тогда опять вызываем usage()
	if (strncmp(argv[1], "-h", 2) == 0)
	{
		usage();
		return 0;
	}
	// если -V - тогда выводим версию
	if (strncmp(argv[1], "-V", 2) == 0)
	{
		printf("pwdx v0.01a by SyvorovaEA\n");
		return 0;
	}
	
	// и наконец если нам все же скормили PID передаем его нашей функции и пусть она его обрабатывает
	int result=get_pwd(argv[1], strlen(argv[1]), buff);

	// если вернула ошику- молча завершаем программуу
	if (result != 0)
		return 1;

	// если все ок- выводим содержимое буфера
	printf("%s: %s\n",argv[1], buff);


	return 0;
}

