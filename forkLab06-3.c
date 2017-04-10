 #include<stdio.h>
  #include<unistd.h>

  int main()
  {
     pid_t pid;
     int stat, exit_stat;

     if (( pid = fork()) < 0)
     {
        perror("fork failed");
        exit(1);
     }

     if (pid == 0)
     {
        printf("Child is sleeping..\n". getpid());
        sleep(4);
        _exit(5);
     }

     while (waitpid(pid, &stat, WHOHANG) == 0)
     {
        printf("still waiting..\n");
        sleep(1);
      }

      if(WIFEXITED(stat))
      {
        exit_stat = WEXITSTATUS(stat);
        printf("exit stat from process %d = %d\n", pid, exit_stat;);
       }
      else if (WIFSIGNALED(stat))
      {
        exit_stat = WTERMISG(stat)
        printf("abnormal termination from process %d = %d\n", pid, exit_stat);
      }
      exit(0);
}



