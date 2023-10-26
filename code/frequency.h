#ifndef HEADER_FREQUENCY_H
#define HEADER_FREQUENCY_H
#include <string>
#include <vector>



struct note 
{
  int frequency;
  std::string name;
};

std::vector<note> listAllNotes;
std::vector <note> listGuitarNotes;


#endif
