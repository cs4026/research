#include <iostream>
#include "extract.h"
#include <vector>

std::vector<field>* get_fields(std::vector<unsigned char> file,std::vector<int> info){
	int sub_start= info[0];
	int f_length=32;
	int travler=f_length;
	int i;
	std::vector<field> f; 
	//while(travler<(sub_start-1)){
		field tmp;
		//grab name
		for(int i =0;i<11;i++){ tmp.names[i]=file[travler+i];}
		//field type
		tmp.type= (char) file[travler+11];
		for(int i=12;i<16;i++){ tmp.displacement[i]=file[travler+i];}
		tmp.lengths= file[travler+16];
		tmp.decimal = (int) file[travler+17];
		f.push_back(tmp);	
	//}
	
	std::vector<field>* fields=&f;
	return fields;
}

std::vector<records>*  get_records(std::vector<unsigned char> file,std::vector<int> info, std::vector<field>* fields){
	return NULL;
}

