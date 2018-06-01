
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/stdio.h>
#include <sys/stdlib.h>

#define SHMSZ 27

int main(){
	char c;
	int shmid;
	key_t key;
	char *shm, *s;
	key = 5678; // name of the shared memory segment
	
	if(shmid = shmget(key, SHMSZ,IPC_CREATE | 0666)) < 0){
		printf("Shared memory error. Memory can't be created");
		exit(1);
	}
	// now attaching the memory segment to the data space
	
	if((shm = shmat(shmid, NULL,0))== (char *)-1){
		printf("memory attachment error.");
		exit(1);
		
	}
	//putting something to the memory for the other process to read
	
	for(c = 'a'; c <= 'z'; c++){
		*s++ = c;
		*s = '\0'
	}
	//we have to wait until the other process changes the first character of our memory to *, indicating that it has read what we put there
	while(*shm != '*'){
		sleep(1);
	}
	for(s = shm; *s != '\0'; s++){
		putchar(*s);
		putchar('\n');
	}
return 0;
	
}
