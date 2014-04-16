/*
 Copyright (C) 1997, Alexander Pukhov 
*/

#include <unistd.h>
#include <sys/file.h>
#include <sys/utsname.h>
#include <signal.h>
#include"syst.h"



char *  trim(char* p)
{  int n1=0, n2, k=-1;
   n2=(int)strlen(p)-1;
   while(!isgraph(p[n1]) && n1 <= n2) n1++;
   while(!isgraph(p[n2]) && n1 <  n2) n2--;
   while(++k < n2-n1+1)  p[k] = p[k+n1];
   p[k] = '\0';
   return p;
}


void  (*diskerror)(void) = NULL;

int f_printf(FILE *fp,char * format, ... )
{ va_list args;
  char dump[STRSIZ];
  int  r;
  va_start(args, format);

        vsprintf(dump,format,args);
	va_end(args);
	r = fputs(dump,fp);
	if (r == EOF)
	{ if(diskerror)(*diskerror)(); else sortie(65); }
	return r;
}


size_t f_write(void* ptr,  size_t size,  size_t n,  FILE * fp)
{ size_t nn;
   if ((size == 0)||(n == 0)) return 0;
   nn= fwrite(ptr,size,n,fp);
   if (nn != n) {if(diskerror) (*diskerror)() ; else sortie(65);}
   return nn;
}

void  unLockFile(int fd) 
{ 
  int ret;  
lseek(fd,SEEK_SET,0);  
#ifdef FLOCK
  ret = flock(fd,LOCK_UN);
#else
  ret = lockf(fd,F_ULOCK,10);
#endif
  close(fd);
}

int setLockFile(char * fname)
{ int fd,ret;
  char lockTxt[100]; 
  
  fd=open(fname,O_WRONLY|O_CREAT,0666);
  if(fd<0) return fd;
  lseek(fd,SEEK_SET,0);    
#ifdef FLOCK  
  ret=flock(fd,LOCK_EX|LOCK_NB);   
#else
  ret = lockf(fd, F_TLOCK, 10);
#endif  
  if(ret) { close(fd); return 0;}
  {
      struct utsname buff;
      uname(&buff);
      sprintf(lockTxt," process %d on %s\n",getpid(),buff.nodename);
  }                       
  write(fd,lockTxt,strlen(lockTxt));
  lseek(fd,SEEK_SET,0);
  return fd;
}

static char * lockFileName=NULL;
static int   lockFileFD=0;

int writeLockFile(char * fname)
{   
  if(lockFileFD) return lockFileFD;
  lockFileFD=setLockFile(fname);
  if(lockFileFD<0) lockFileFD=0; else 
  { lockFileName=malloc(strlen(fname)+1);
    strcpy(lockFileName,fname);
  }
  return lockFileFD;
}

void sortie(int code) 
{ 
  if(lockFileFD)
  {  unLockFile(lockFileFD);
     unlink(lockFileName);
  }   
  exit(code);
}

