#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <vector>
#include <cinttypes>
#include "info.h"
#include "extract.h"
#include "field.h"

int main(int argc,char * argv[]){
	//Database file to be used	
	std::string f=argv[1];
	//Length to be extracted from file
	int len=atoi(argv[2]);
	//Used to determine what function to run
	int mode=atoi(argv[3]);
	//In the dump method, number is used to see if the entire file should be dumped
	int dump_num=atoi(argv[4]);
	//begining and end of cdx block to be dumped
	int r[]={atoi(argv[5]),atoi(argv[6])};

	std::vector<unsigned char> file = file_grab(f,-1);	
	std::vector<int> information=header_info(file,-1);

	//pass vector to field handler and get back array of fields.
	std::vector<field>* fields = get_fields(file,information);
	std::vector<records>* records = get_records(file,information,fields);
	
	field tmp=(*fields)[0];
	__int32_t d;
	memcpy(&d,tmp.displacement,4);
	printf("field name: %s, type: %d, displacement: %d, length: %d, decimal: %d\n",tmp.names,tmp.type,d,tmp.length,tmp.decimal);
	return 0;	
}
