#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

#define SIZE_T 255

int main(int argc, char* argv[]){
	
	char line[SIZE_T];

	if(argc > 2){
		char msg[] = "Use: mycat namefile\n";
		write(STDOUT_FILENO, msg, sizeof(msg));
		return 0;
	}
	if(argc == 1){
		int tam;
		while((tam = read(STDIN_FILENO, line, SIZE_T))>0){
			write(STDOUT_FILENO, line, tam);
		}
	}
	else{
		int fd = open(argv[1], O_RDONLY);
		int tam;
		if(fd == -1){
			char errorf[] = "Error al abrir el archivo\n";
			write(STDOUT_FILENO, errorf, sizeof(errorf));
		}
		while((tam = read(fd, line, SIZE_T)) > 0){
			write(STDOUT_FILENO, line, tam);
		}
		close(fd);
	}
	return 0;
}
