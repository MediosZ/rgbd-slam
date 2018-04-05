#include"utils.h"
using namespace std;

void parsePara(Flags& flags, int argc, char** argv){
  if(argc == 1){
    return;
  }
  for(int i=1; i<argc; i++){
      flags.process = argv[i][1] == 'r' ? true : false;
      flags.capture = argv[i][1] == 'a' ? true : false;
      flags.octmap  = argv[i][1] == 'c' ? true : false;
      flags.cloud   = argv[i][1] == 'l' ? true : false;
  }
}
