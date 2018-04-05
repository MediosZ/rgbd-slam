//standard libs
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <queue>

//multi process
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

using namespace std;

class Flags{
public:
  Flags():process(false), capture(false), octmap(false), cloud(false){}
  
  bool process;
  bool capture;
  bool octmap;
  bool cloud;
};

void parsePara(Flags& flags, int argc, char** argv);
