#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>

using namespace std;

void reverse_line(ifstream &file){
	string word;
	if(!(file >> word)){
		
		return;
	}
	reverse_line(file);
	cout << word << endl;
	
}

int main(int argc, char *argv[]){
	if(argc < 2){
    	cout << "Please enter the name of the file to read as an argument" << endl;
    	return 1;
  	}

	int n;

	ifstream myfile(argv[1]);
	if (myfile.is_open()){
		myfile >> n;
		
		reverse_line(myfile);
	}



	return 0;
}