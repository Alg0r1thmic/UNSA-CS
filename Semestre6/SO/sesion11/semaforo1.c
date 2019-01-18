#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <stdlib.h>
#include <stdio.h>

union semun {
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
	struct seminfo *_buf;

};

void esperaSemaforo(int idSemaforo, int indice){
	struct sembuf operacion;
	operacion.sem_num = indice;
	operacion.sem_op = -1;
	operacion.sem_flg = 0;
	semop(idSemaforo,&operacion,1);
}

int main() {
	key_t clave;
	int idSemaforo;	
	union semun arg;
	int i=0;
	clave = ftok("/bin/ls",32);
	if (clave == (key_t)-1) {
		printf("No puedo conseguir la clave de semaforo\n");
		exit(0);
	}
	idSemaforo=semget(clave,10,IPC_CREAT|0600);
	if (idSemaforo == -1) {
		printf("No puedo crear el semaforo\n");
		exit(0);
	}
	arg.val = 0;
	semctl(idSemaforo,1,SETVAL,0);
	while(1) {
		printf("Esperando semaforo %d\n",i);
		esperaSemaforo(idSemaforo,1);
		printf("Salgo del semaforo %d\n",i);
		i++;
	}
}