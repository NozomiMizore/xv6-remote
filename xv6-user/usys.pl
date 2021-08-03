#!/usr/bin/perl -w

# Generate usys.S, the stubs for syscalls.

print "# generated by usys.pl - do not edit\n";

print "#include \"sysnum.h\"\n";

sub entry {
    my $name = shift;
    print ".global $name\n";
    print "${name}:\n";
    print " li a7, SYS_${name}\n";
    print " ecall\n";
    print " ret\n";
}
	
entry("fork");
entry("exit");
entry("wait");
entry("pipe2");
entry("read");
entry("write");
entry("close");
entry("kill");
entry("exec");
entry("openat");
entry("fstat");
entry("mkdirat");
entry("chdir");
entry("dup");
entry("dup3");
entry("getpid");
entry("brk");
entry("sbrk");
entry("sleep");
entry("uptime");
entry("test_proc");
entry("getdents");
entry("getcwd");
entry("unlinkat");
entry("trace");
entry("sysinfo");
entry("renameat2");
entry("execve");
entry("mount");
entry("umount");
entry("uname");
entry("mmap");
entry("munmap");
entry("sync");
