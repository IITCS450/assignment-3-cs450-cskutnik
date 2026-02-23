#include "types.h"
#include "stat.h"
#include "user.h"

#define NCHILD 3	
#define RUNTIME 200000000

int main(void){
  int tickets[NCHILD] = {1, 2, 7};

  for(int i = 0;i < NCHILD;i++){
    int pid = fork();

    if(pid == 0){
      settickets(tickets[i]);

      int count = 0;
      while(count < RUNTIME) count++;

      printf(1, "Child %d (tickets = %d) done\n", getpid(), tickets[i]);
      exit();
    }
  }
  for(int i = 0;i < NCHILD;i++) wait();

  exit();
}
