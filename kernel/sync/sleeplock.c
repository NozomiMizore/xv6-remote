// Sleeping locks


#include "types.h"
#include "hal/riscv.h"
#include "param.h"
#include "memlayout.h"
#include "sync/spinlock.h"
#include "sched/proc.h"
#include "sync/sleeplock.h"

void
initsleeplock(struct sleeplock *lk, char *name)
{
	initlock(&lk->lk, "sleep lock");
	lk->name = name;
	lk->locked = 0;
	lk->pid = 0;
}

void
acquiresleep(struct sleeplock *lk)
{
	acquire(&lk->lk);
	while (lk->locked) {
		sleep(lk, &lk->lk);
	}
	lk->locked = 1;
	lk->pid = myproc()->pid;
	release(&lk->lk);
}

void
releasesleep(struct sleeplock *lk)
{
	acquire(&lk->lk);
	lk->locked = 0;
	lk->pid = 0;
	wakeup(lk);
	release(&lk->lk);
}

int
holdingsleep(struct sleeplock *lk)
{
	int r;
	
	acquire(&lk->lk);
	r = lk->locked && (lk->pid == myproc()->pid);
	release(&lk->lk);
	return r;
}

int trysleeplock(struct sleeplock *lk)
{
	int ret = 0;
	acquire(&lk->lk);
	if (lk->locked) {
		ret = -1;
	} else {
		lk->locked = 1;
		lk->pid = myproc()->pid;
	}
	release(&lk->lk);
	return ret;
}
