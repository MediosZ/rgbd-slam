#include "utils.h"

int main(int argc, char** argv){
  //ParsePara
  Flags flags;
  parsePara(flags, argc, argv);
  
  if(flags.capture){
    pid_t pid = fork();
    if(pid<0){
      cout<<"error creating sub process"<<endl;
    }
    else if(pid == 0){
      cout<<"Capture successfully start"<<endl;
      if(execlp("../pics/readpic", "readpic", NULL) < 0){
        perror("execute error");
        return(1);
      }
    }
    else {
      wait(NULL);
      cout<<"Capture exited, main exit"<<endl;
    }

    return 0;
  }
  else if(flags.process){
    pid_t pid = fork();
    if(pid<0){
      cout<<"error creating sub process"<<endl;
    }
    else if(pid == 0){
      cout<<"Process successfully start"<<endl;
      if(execlp("../bin/slam", "slam", NULL) < 0){
        perror("execute error");
        return(1);
      }
    }
    else {
      wait(NULL);
      cout<<"Process exited, main exit"<<endl;
    }

    return 0;
  }
  else if(flags.octmap){

  }
  else {
    cout<<"try following commands"<<endl
    <<"capture -- capture rgb images and depth images and save them"<<endl
    <<"process -- process local pics and generate map"<<endl;
  }


  return 0;
}
