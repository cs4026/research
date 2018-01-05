#ifndef INFO_h
#define INFO_h
std::vector<int> header_info(std::vector<unsigned char>  file,int len);

std::vector<int> header_info(std::string f,int len);



void read(std::string s, int len,int* r,int range);

void dump(std::string s);

std::vector<unsigned char> file_grab(std::string f,int len);
std::vector<unsigned char> file_grab(std::vector<unsigned char> f,int len);

unsigned int seek_byte(int range,int offset,int offset_end,std::vector<unsigned char> file);

//std::vector<unsigned char> record_proc(std::vector<unsigned char> file,int* r);

#endif
