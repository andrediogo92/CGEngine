#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <fstream>
#include <iostream>
#include "generator.h"
using namespace generator;

int main(int argc, char* argv[]){

  if(argc > 7){
    cerr << "Invalid number of arguments provided.";
    exit(EXIT_FAILURE);
  }

  else {
    ofstream fp;

    if(!strcmp(argv[1],"plane")){
      if((argc == 5)){
        try{
          float length = std::stof(argv[3]), width = std::stof(argv[4]);
          fp.open(argv[2], ios::trunc);
          generatePlane(fp, length, width);
          fp.close();
        }
        catch(invalid_argument e){
          cerr << "Invalid type of arguments provided.";
          exit(EXIT_FAILURE);
        }
      }
      else {
	cerr << "Invalid number of arguments provided.";
        exit(EXIT_FAILURE);
      }
    }

    else if(!strcmp(argv[1],"box")){
      if((argc == 6)){
        try{
          float length = std::stof(argv[3]), height = std::stof(argv[4]);
          float width = std::stof(argv[5]);
          fp.open(argv[5], ios::trunc);
          generateBox(fp, length, height, width, 0);
          fp.close();
        }
        catch(invalid_argument e){
          cerr << "Invalid type of arguments provided.";
          exit(EXIT_FAILURE);
        }
      }
      else if((argc == 7)){
        try{
          float length = std::stof(argv[3]), height = std::stof(argv[4]);
          float width = std::stof(argv[5]), divisions = std::stof(argv[6]);
          fp.open(argv[6], ios::trunc);
          generateBox(fp, length, height, width, divisions)
          fp.close();
        }
        catch(invalid_argument e){
          cerr << "Invalid type of arguments provided.";
          exit(EXIT_FAILURE);
        }
      }
      else {
        cerr << ("Invalid number of arguments provided.");
        exit(EXIT_FAILURE);
      }
    }

    else if(!strcmp(argv[1],"sphere")){
      if((argc == 6)){
        try{
          float radius = std::stof(argv[3]), slices = std::stof(argv[4]);
          float stacks = std::stof(argv[5]);
          fp.open(argv[5], ios::trunc);
          generateSphere(fp, radius, slices, stacks);
          fp.close();
        }
        catch(invalid_argument e){
          cerr << "Invalid type of arguments provided.";
          exit(EXIT_FAILURE);
        } 
      }
      else {
        cerr << ("Invalid number of arguments provided.");
        exit(EXIT_FAILURE);
      }
    }

    else if(!strcmp(argv[1],"cone")){
      if((argc == 7)){
	try{
          float radius = std::stof(argv[3]), height = std::stof(argv[4]);
          float slices = std::stof(argv[5]), stacks = std::stof(argv[6]);
          fp.open(argv[6], ios::trunc);
          generateCone(fp, radius, height, slices, stacks);
          fp.close();
        }
        catch(invalid_argument e){
          cerr << "Invalid type of arguments provided.";
          exit(EXIT_FAILURE);
        }
      }
      else {
        cerr << ("Invalid number of arguments provided.");
        exit(EXIT_FAILURE);
      }
    }
    
    else {
      cerr << ("Available graphical primitives: plane box sphere cone");
      exit(EXIT_FAILURE);
    }
  }
  return 0;
}
