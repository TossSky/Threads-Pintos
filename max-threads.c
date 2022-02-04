#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/thread.h"
#include "threads/vaddr.h"
void wait(void *aux) 
{ 
	while(1);
} 

void test_max_threads(void) 
{
  int cnt=0; 
  
  while(1) 
  { 
		tid_t a=thread_create("MThread",PRI_DEFAULT,wait,NULL); 
		if(a!=TID_ERROR) 
			cnt++; 
		else break;
	} 
	msg("%d - last thread number", cnt); 
}
