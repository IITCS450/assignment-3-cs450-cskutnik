#include "types.h"
#include "stat.h"
#include "user.h"

#define NCHILD 3
#define DURATION 1000

int main(void){
  int tickets[NCHILD] = {1, 2, 7};
  int pipes[NCHILD][2];

  int start = uptime() + 20;
  
  for(int i = 0;i < NCHILD;i++){
    pipe(pipes[i]);

    int pid = fork();
 
    if(pid == 0){
      close(pipes[i][0]);
      settickets(tickets[i]);

      while(uptime() < start);

      int count = 0;
      int end = start + DURATION;

      while(uptime() < end) count++;

      write(pipes[i][1], &count, sizeof(count));
      close(pipes[i][1]);
      exit();
    }
    close(pipes[i][1]);
  }
  int counts[NCHILD];

  for(int i = 0;i < NCHILD;i++){
    read(pipes[i][0], &counts[i], sizeof(counts[i]));
    close(pipes[i][0]);
    wait();
  }
  int total = 0;
  for(int i = 0;i < NCHILD;i++) total += counts[i];

  for(int i = 0;i < NCHILD;i++){
    long percent = ((long)counts[i] * 100) / total;
    printf(1, "Tickets = %d Work = %d Share = %d%%\n", tickets[i], counts[i], percent);
  }
  exit();
}
