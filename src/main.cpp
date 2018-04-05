#include <iostream>
using namespace std;
struct Flags{
  bool process;
  bool capture;
  bool octmap;
  bool cloud;
} flags;

int main(int argc, char** argv){
  //ResolvePara
  for(int i=1; i<argc; i++){
    if(argv[i][1] == 'r'){
      flags.process = true;
      cout<<"process"<<endl;
    }
    if(argv[i][1] == 'a'){
      flags.capture = true;
      cout<<"capture"<<endl;
    }
    if(argv[i][1] == 'l'){
      flags.cloud = true;
      cout<<"cloud"<<endl;
    }
    if(argv[i][1] == 'c'){
      flags.octmap = true;
      cout<<"octmap"<<endl;
    }
  }

  if(flags.capture){
  }

}
