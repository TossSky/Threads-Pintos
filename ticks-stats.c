#include <stdio.h>
#include "tests/threads/tests.h"
#include "threads/malloc.h"
#include "threads/thread.h"
#include "devices/timer.h"
#define Cnt 10
void inf(void *aux) 
{ 
	while(1);
} 

void test_ticks_stats(void) 
{
	for (int i = 1; i<Cnt+1; i++)
	{
		char name[16];
    snprintf (name, sizeof name, "thread %d", i);
  	thread_create(name, PRI_DEFAULT, inf, NULL);
	}
	
	for (int i = 1;i<Cnt+1;i++)
	{
		timer_sleep(100);
		
		msg("iteration %d\n",i);
		StatsRunning();
		msg("-------------------");
	}
}
