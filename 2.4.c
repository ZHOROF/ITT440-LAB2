#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void childTask(){
	char name[20];
	printf("Nama: ");
	scanf("%s",name);
	printf("Hello %s\n", name);
	//return name;
}

void parentTask(){
	//printf("waiting for child process to finish!!\n");
	//wait(NULL);
	printf("Job is done \n");
}


int main(void){

	for (int i=0; i<4; i++){
	   pid_t pid = fork();

		if (pid == 0){
		   childTask();
		 // childTask();
		 // fgets(name, 20, stdin);
		 // printf("%s", name);
		  exit(EXIT_SUCCESS);
		}
		
		else if (pid > 0){
		 // parentTask();
		  wait(NULL);
		}

		
	}

	parentTask();
	return 0;
}
