#ifndef __SLEEPLOCK_H
#define __SLEEPLOCK_H

#include "types.h"
#include "sync/spinlock.h"

struct spinlock;

// Long-term locks for processes
struct sleeplock {
	uint locked;       // Is the lock held?
	struct spinlock lk; // spinlock protecting this sleep lock
	
	// For debugging:
	char *name;        // Name of lock.
	int pid;           // Process holding lock
};

void            acquiresleep(struct sleeplock*);
void            releasesleep(struct sleeplock*);
int             holdingsleep(struct sleeplock*);
void            initsleeplock(struct sleeplock*, char*);
int				trysleeplock(struct sleeplock *lk);

#endif
