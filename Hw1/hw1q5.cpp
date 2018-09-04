#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstdlib>

using namespace std;

void reverse_line(ifstream &file){
	string word;
	//base case
	if(!(file >> word)){	
		return;
	}

	reverse_line(file); //recursive call
	cout << word << endl; //print out the words in reverse
	
}

int main(int argc, char *argv[]){
	//if the user didnt input the file in the command line
	if(argc < 2){
    	cout << "Please enter the name of the file to read as an argument" << endl;
    	return 1;
  	}

	int n;

	//using ifstream to read in the file
	ifstream myfile(argv[1]);
	if (myfile.is_open()){
		myfile >> n; //read in the number of words
		
		//call function to reverse the line
		reverse_line(myfile);
	}



	return 0;
}