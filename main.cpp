#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cinttypes>
#include "records.h"
#include "fields.h"
#include "info.h"
std::vector<int> header_info(std::string s,int len){
	std::vector<unsigned char> file= file_grab(s,len);
	unsigned char sub[2];
	sub[0]=file[8];
	sub[1]=file[9];

	unsigned int sub_start=*((int*)sub);
	unsigned char record_num[4];	

	for( int i =4;i<8;i++) {record_num[i-4]= file[i];}

	unsigned char record_length[2];
	record_length[0]=file[10];
	record_length[1]=file[11];
	int r_length=*record_length;
	printf("Number of Records: %"PRIu32"\nRecord Start: %d\nNumber of bytes in record: %d\n",*((__int32_t*)record_num),sub_start,r_length);

	std::vector<int> numbers(2,0);
	numbers[0]=sub_start;
	numbers[1]=r_length;	 
	return numbers;
}

std::vector<unsigned char> record_proc(std::vector<unsigned char> file,int* r){
	std::vector<unsigned char> record(r[1]-r[0],0);	
	return record;	
}

void read(std::string s, int len,int* r,int range){
	std::vector<unsigned char> file=file_grab(s,len);

	std::vector<unsigned char> record(r[1]-r[0],0);
	
	if(range==1) record=record_proc(file,r);
	
	if(len==-1) len=file.size();
	int i=0;
	while(i<len){
		for (int j=i;j<i+10;j++) printf("%6d ",j);
		printf("\n");
		for (int j=i;j<i+10;j++) printf("------ ");
		printf("\n");
		for (int j=i;j<i+10;j++) printf("%6x ",file[j]);
		i+=10;
		printf("\n");
		printf("\n");
	}		
}

void dump(std::string s,int num){
	std::vector<unsigned char> file=file_grab(s,-1);
	printf("Dumping file %s contents\n---------------------------------------",s.c_str());
	if(num==-1) for(int i=0;i<file.size();i++) printf("%c ",char(file[i]));
	else for(int i=0;i<num;i++) printf("%c ",char(file[i]));
	printf("\n");
}

void id_dump(std::string s){
	std::vector<unsigned char> file = file_grab(s,-1);
	int offset = 698;
	int id_count=0;
	while(offset<file.size()){
		//for (int i =0;i <8;i++) printf("%c",file[i+offset]);
		//printf("\n");
		id_count++;
		offset+=153;
	}
	printf("\nTotal id's: %d \n",id_count);
	printf("Final id position: %d\n",offset-153);
}

std::vector<unsigned char> file_grab(std::string f,int len){
	std::ifstream in(f,std::ios::binary);
	//grab length of file
	in.seekg(0,in.end);
	int length= in.tellg();
	in.seekg(0,in.beg);
	//holder for information, first param is size, the second is the value of elemtns to be intiated
	std::vector<unsigned char> buff(length,0);

	if(len==-1) in.read((char*)&buff[0],length);	
	//Reads bytes [0-100] and outputs them
	else in.read((char *)&buff[0],len);
	
	in.close();
	return buff;
}

int main(int argc,char* argv[]){

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
	
	//NOT USED
	int range=atoi(argv[7]);
	switch (mode){
		case 1: {
			header_info(f,len);
			break;
		}
		case 2:{
			std::vector<unsigned char> file=file_grab(f,len);	
			//seek_byte(file);
			break;
		}
		case 3:
			dump(f,dump_num);
			break;
		case 4:
			read(f,len,r,range);
			break;
		case 5:
			id_dump(f);
			break;
	}
		
	return 0;
}
