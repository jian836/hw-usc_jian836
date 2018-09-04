#include <iostream>
#include <stdlib.h>
#include "flexCharManager.h"
using namespace std;

int main(int argc, char *argv[])
{
  flexCharManager simplest_mem_manager;

/*replace with driver code as specificed in the assignment*/
  char* c1 = simplest_mem_manager.alloc_chars(13);
  c1[0] = 'H';
  c1[1] = 'e';
  c1[2] = 'l';
  c1[3] = 'l';
  c1[4] = 'o';
  c1[5] = ' ';
  c1[6] = 'w';
  c1[7] = 'o';
  c1[8] = 'r';
  c1[9] = 'l';
  c1[10] = 'd';
  c1[11] = '!';
  c1[12] = '\n';

  cout << c1[0] << c1[1] << c1[2] << c1[3] << c1[4]<< c1[5] << c1[6]
  << c1[7] << c1[8] << c1[9] << c1[10] << c1[11] << c1[12] << endl;

  simplest_mem_manager.free_chars(&c1[0]);

  //cout << "after freechars" << endl;
  for (int i = 0; i < 30; i++){
  	cout << c1[i];
  }

  char* c2 = simplest_mem_manager.alloc_chars(10);
  c2[0] = 'm';
  c2[1] = 'o';
  c2[2] = 'o';
  c2[3] = 'n';
  c2[4] = '!';
  c2[5] = ' ';
  c2[6] = 'B';
  c2[7] = 'y';
  c2[8] = 'e';
  c2[9] = '.';
  c2[10] = '\n';
	
  for (int i = 0; i < 30; i++){
  	cout << c1[i];
  }
	//cout << c2[0] << c2[1] << c2[2] << c2[3] << c2[4]<< c2[5] << c2[6]
 // << c2[7] << c2[8] << c2[9] << c2[10] << endl;
  
  return 0;
}

