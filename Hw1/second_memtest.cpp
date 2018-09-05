#include <iostream>
#include <stdlib.h>
#include "flexCharManager.h"
using namespace std;

int main(int argc, char *argv[])
{
  flexCharManager simplest_mem_manager;

/*replace with driver code as specificed in the assignment*/
  char* c1 = simplest_mem_manager.alloc_chars(6);
  c1[0] = 'H';
  c1[1] = 'e';
  c1[2] = 'l';
  c1[3] = 'l';
  c1[4] = 'o';
  c1[5] = ' ';

  
  char* c3 = simplest_mem_manager.alloc_chars(7);
  c3[0] = 'w';
  c3[1] = 'o';
  c3[2] = 'r';
  c3[3] = 'l';
  c3[4] = 'd';
  c3[5] = '!';
  c3[6] = '\n';

  for (int i = 0; i < 30; i++){
  	cout << c1[i];
  }

  simplest_mem_manager.free_chars(c3);

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

  
  return 0;
}

