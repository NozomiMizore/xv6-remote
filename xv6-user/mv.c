#include "types.h"
#include "fs/stat.h"
#include "fs/fcntl.h"
#include "param.h"
#include "user.h"

int main(int argc, char *argv[])
{
    if (argc < 3) {
        fprintf(2, "Usage: mv old_name new_name\n");
        exit(1);
    }

    char src[MAXPATH];
    char dst[MAXPATH];
    strcpy(src, argv[1]);
    strcpy(dst, argv[2]);
    struct kstat st;
    if (stat(dst, &st) == 0) {
        if (st.mode & ST_MODE_DIR) {
            char *ps, *pd;
            for (ps = src + strlen(src) - 1; ps >= src; ps--) { // trim '/' in tail
                if (*ps != '/') {
                    *(ps + 1) = '\0';
                    break;
                }
            }
            for (; ps >= src && *ps != '/'; ps--);
            ps++;
            pd = dst + strlen(dst);
            *pd++ = '/';
            while (*ps) {
                *pd++ = *ps++;
                if (pd >= dst + MAXPATH) {
                    fprintf(2, "mv: fail! final dst path too long (exceed MAX=%d)!\n", MAXPATH);
                    exit(-1);
                }
            }
        } else {
            fprintf(2, "mv: fail! %s exists!\n", dst);
            exit(-1);
        }
    }
    // printf("moving [%s] to [%s]\n", src, dst);
    if (rename(src, dst) < 0) {
        fprintf(2, "mv: fail to rename %s to %s!\n", src, dst);
        exit(-1);
    }
    exit(0);
}