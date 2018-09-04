#include "flexCharManager.h"

flexCharManager::flexCharManager(){
	used_memory= new Mem_Block*[2];
	/* memory available in the buffer */
	free_mem = BUF_SIZE;
	/* memory blocks in use */
	active_requests = 0;
	/* memory blocks available in array of memory blocks*/
	used_mem_size = 2;
}


flexCharManager::~flexCharManager(){
	delete[] used_memory;

}

char* flexCharManager::alloc_chars(int n){
	if (free_mem < n ) return NULL;

	char* p;
	if (active_requests == 0) {
		p = &buffer[0];
		used_memory[0] = new Mem_Block(n, p);
		active_requests++;
		return p;
	}
	for (int i = 0; i < active_requests; i++){
		
		char* prev = used_memory[i]->physical_location + used_memory[i]->size;
		char *next=  used_memory[i+1]->physical_location;	

		
		if (next - prev >= n){
			p = prev;
			free_mem -= n;
			active_requests++;

			if (used_mem_size == active_requests){
				Mem_Block** temp = used_memory;
				used_memory = new Mem_Block*[used_mem_size*2];
				//loop thru temp and copy memblocks one by one, delete temp
				for (int i = 0; i < used_mem_size; i++){
					used_memory[i]= temp[i];
					delete temp[i];
				}
				delete[] temp;
				used_mem_size = active_requests*2;
			}
			for (int j = active_requests-1; j >= i; j--){
				used_memory[j+1] = used_memory[j];
			}
			break;
		}
	}


	return p;
}

void flexCharManager::free_chars(char* p){
	
	int block_size = 0;

	for (int i = 0; i < active_requests; i++){
		
		if(used_memory[i]->physical_location == p){
			block_size = used_memory[i]->size;
			for (int k = 0; k < block_size; k++){
				p[k] = '\0';
			}
			for (int j = i; j < active_requests; j++){
				used_memory[j] = used_memory[j+1];
			}
			break;
		}
		else {
				//do nothing
		}
		
	}
	free_mem += block_size;//is this right
	active_requests--;
	if (used_mem_size/2 > active_requests){

		Mem_Block** temp = used_memory;
		used_memory= new Mem_Block*[used_mem_size/2];
		for (int i = 0; i < active_requests; i++){
			used_memory[i] = temp[i];
		}
		for (int i = 0; i <used_mem_size; i++){
			delete temp[i];
		}
		delete[] temp;
		used_mem_size /= 2;
	}

}         


