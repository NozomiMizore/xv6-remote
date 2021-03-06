#ifndef __STAT_H
#define __STAT_H

#include "types.h"

#define T_DIR     1   // Directory
#define T_FILE    2   // File
#define T_DEVICE  3   // Device

#define S_IFMT				0170000
#define S_IFSOCK			0140000		// socket
#define S_IFLNK				0120000		// symbolic link
#define S_IFREG				0100000		// regular file
#define S_IFBLK				0060000		// block device
#define S_IFDIR				0040000		// directory
#define S_IFCHR				0020000		// character device
#define S_IFIFO				0010000		// FIFO
#define ST_MODE_DIR			S_IFDIR

#define S_ISLNK(m)			(((m) & S_IFMT) == S_IFLNK)
#define S_ISREG(m)			(((m) & S_IFMT) == S_IFREG)
#define S_ISDIR(m)			(((m) & S_IFMT) == S_IFDIR)
#define S_ISCHR(m)			(((m) & S_IFMT) == S_IFCHR)
#define S_ISBLK(m)			(((m) & S_IFMT) == S_IFBLK)
#define S_ISFIFO(m)			(((m) & S_IFMT) == S_IFIFO)
#define S_ISSOCK(m)			(((m) & S_IFMT) == S_IFSOCK)

#define DIRENT_MAX_NAME 255

// struct kstat {
// 	uint32    dev;
// 	uint64    ino;
// 	uint16    mode;
// 	uint32    nlink;
// 	uint32    uid;
// 	uint32    gid;
// 	uint32    rdev;
// 	uint64    __pad;
// 	uint64    size;
// 	uint32    blksize;
// 	int       __pad2;
// 	uint64    blocks;
// 	long      atime_sec;
// 	long      atime_nsec;
// 	long      mtime_sec;
// 	long      mtime_nsec;
// 	long      ctime_sec;
// 	long      ctime_nsec;
// 	uint32    __unused[2];
// };

struct kstat {
	uint64    dev;
	uint64    ino;
	uint32    mode;
	uint32    nlink;
	uint32    uid;
	uint32    gid;
	uint64    rdev;
	uint64    __pad;
	uint64    size;
	uint32    blksize;
	int       __pad2;
	uint64    blocks;
	long      atime_sec;
	long      atime_nsec;
	long      mtime_sec;
	long      mtime_nsec;
	long      ctime_sec;
	long      ctime_nsec;
	uint32    __unused[2];
};

struct dirent {
	uint64    ino;
	int64     off;
	uint16    reclen; // Length of name
	uint8     type;
	char      name[DIRENT_MAX_NAME + 1];
};

// struct stat {
//   int dev;     // File system's disk device
//   uint ino;    // Inode number
//   short type;  // Type of file
//   short nlink; // Number of links to file
//   uint64 size; // Size of file in bytes
// };

#endif