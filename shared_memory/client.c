
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stdio.h>
#include <sys/stdlib.h>

#define SHMSZ 27

int main(){
	int shmid;
	key_t key;
	char *shm, *s;
	
	// getting the segment 55678, created by the server
	key = 5678;
	if(shmid = shmget(key, SHMSZ,066) < 0){
		printf("Shared memory error. Memory can't be created");
		exit(1);
	}
	//attaching the segment to the data space
	if((shm = shmat(shmid, NULL,0))==(char *) -1){
		printf("Memory attachment error. Memory can't be attached");
		exit(1);
	}
	// Now reading what the server put on the memory
	for(s = shm; *s != NULL,s++){
		putchar(*s);
		putchar('\n');
		*shm = '*';
		
	}
	
	return 0;
	
}
