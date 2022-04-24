#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

void runTask(char* input){
	int status;
	char* token;
	strtok(input, "\n");
	if(strcmp(input, "exit") == 0){
		exit(0);
	}
	token = strtok(input, " ");
	if (strcmp(token, "cd")==0){
		token = strtok(NULL, " ");
		chdir(token);
	} else {
		int pid = fork();
		if (pid < 0){
			//fail
			fprintf(stderr, "fork failed\n");
			exit(1);
		} else if (pid == 0){
			//child
			execlp(input,input,NULL);
			printf("Something went wrong\n");
			exit(1);
		} else {
			waitpid(pid, &status, 0);
			//parent
		}
	}
}

int main(int argc, char * argv[]){
	FILE* file;
	char* input;
	size_t len = 0;
	if (argc == 1){
		do {
			printf("wish> ");
			getline(&input, &len, stdin);
			//printf("%s", input);
			runTask(input);
		} while (1);
	} else {
		if((file = fopen(argv[1],"r")) == NULL){
			perror("Error: ");
			exit(1);
		}
		while(getline(&input, &len, file) != -1){
			runTask(input);
		}
	}
	return(0);
}
