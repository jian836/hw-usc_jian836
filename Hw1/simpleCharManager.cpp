#include <cstddef>
#include "simpleCharManager.h"



simpleCharManager::simpleCharManager(){

}

simpleCharManager::~simpleCharManager(){}
             
char* simpleCharManager::alloc_chars(int n){
	if (free_place + n > buffer + BUF_SIZE-1){
		return NULL;
	}

	free_place += n;

	return free_place-n;
}

void simpleCharManager::free_chars(char* p){
	if (buffer == NULL) return;

	for (int i = 0; i < BUF_SIZE; i++){
		p[i] = '\0';
		p+=i;
	}
	free_place = p;
	
}    



