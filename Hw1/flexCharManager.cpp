#include "flexCharManager.h"

flexCharManager::flexCharManager(){
	//declare variables
	used_memory= new Mem_Block*[2];
	
	free_mem = BUF_SIZE;
	
	active_requests = 0;
	
	used_mem_size = 2;
}


flexCharManager::~flexCharManager(){
	//destructor
	delete[] used_memory;

}

char* flexCharManager::alloc_chars(int n){
	//check if theres enough memory to allocate
	if (free_mem < n ) return NULL;

	char* p;
	if (active_requests == 0) { //making the first MemBlock
		p = &buffer[0];
		used_memory[0] = new Mem_Block(n, p);
		active_requests++;
		return p;
	}

	for (int i = 0; i < active_requests; i++){
		
		if(used_memory[i+1] == NULL){ //case when second 
									//memblock is not yet declare
			p = used_memory[i]->physical_location + used_memory[i]->size;
			used_memory[i+1] = new Mem_Block(n,p);
			active_requests++;
			return p;
		}

		//use these two variables to find the free space in buffer
		char* prev = used_memory[i]->physical_location + used_memory[i]->size;
		char *next= used_memory[i+1]->physical_location;	

		//when there is enough space
		if (next - prev >= n){
			//update variable
			p = prev;
			free_mem -= n;
			active_requests++;

			if (used_mem_size == active_requests){ //need to duplicate memBlocks
				Mem_Block** temp = used_memory;
				used_memory = new Mem_Block*[used_mem_size*2];
				
				//loop thru temp and copy memblocks one by one
				for (int k = 0; k < used_mem_size; k++){
					used_memory[k]= temp[k];
					temp[k] = NULL;
					delete temp[k]; //delete temp
				}
				delete[] temp;
				//update variable
				used_mem_size = active_requests*2;
				
			}
			
			for (int j = active_requests-1; j >= i; j--){
				//shift the memblocks
				used_memory[j+1] = used_memory[j];
			}
			
			break;//when its done don't need to loop anymore
		}	

	}
	return p;
}

void flexCharManager::free_chars(char* p){
	
	int block_size = 0;

	for (int i = 0; i < active_requests; i++){
	
		if(used_memory[i]->physical_location == p){
			//find the memory address
			block_size = used_memory[i]->size;
			for (int k = 0; k < block_size; k++){
				p[k] = '\0'; //make everything null
			}
			for (int j = i; j < active_requests; j++){
				used_memory[j] = used_memory[j+1];
				//shift everything
			}
			break;
		}
		else {
				//do nothing
		}
		
	}

	//update variables
	free_mem += block_size;
	active_requests--;

	if (used_mem_size > 2){
		//check if need to resize the array
		if (used_mem_size/2 > active_requests){

			Mem_Block** temp = used_memory;
			used_memory= new Mem_Block*[used_mem_size/2];
			for (int i = 0; i < active_requests; i++){
				used_memory[i] = temp[i];
			}
			//delete temp

			for (int i = 0; i <used_mem_size; i++){
				temp[i] = NULL;
				delete temp[i];
			}
			delete[] temp;
			//update variable
			used_mem_size /= 2;
		}
	}

}         


