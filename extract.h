#ifndef FIELDS_H
#define FIELDS_H

#include "field.h"
#include "records.h"
std::vector<field>* get_fields(std::vector<unsigned char> file, std::vector<int> info);

std::vector<records>*  get_records(std::vector<unsigned char> file,std::vector<int> info, std::vector<field>* fields);

#endif
