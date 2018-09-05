#include <cstddef>
#include "simpleCharManager.h"



simpleCharManager::simpleCharManager(){
	//initialize
	for (int i = 0 ; i < BUF_SIZE; i++){
		buffer[i] = '\0';
	}
}

simpleCharManager::~simpleCharManager(){}
             
char* simpleCharManager::alloc_chars(int n){
	//special case: cannot fit the size
	if (free_place + n > buffer + BUF_SIZE-1){
		return NULL;
	}

	//normal case: add char to buffer, move free_place
	free_place += n;

	return free_place-n;
}

void simpleCharManager::free_chars(char* p){
	if (buffer == NULL) return;

	//find the place and make everything after null
	for (int i = 0; i < BUF_SIZE; i++){
		p[i] = '\0';
	}
	//move free_place pointer
	free_place = p;
	
}    



