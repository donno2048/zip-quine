#include <stdio.h>
#include <string.h>
#define f4 "%c%c%c%c"
#define f3 "%c%c%c"
#define f10 f3 f3 f4
#define PK "PK" f10 f10
#define z4 z,z,z,z
#define z3 z,z,z
#define z7 z3,z4
#define z10 z3,z7
#define fna {'m','a','i','n','.','c',0}
#define fns "main.c"
#define fnlen 6,z
#define fake 0x11111111
#define s(i,j) (s##i>>j)&255
#define ss(i) s(i,0),s(i,8),s(i,16),s(i,24)
#define fmt(fun, ...) fun(__VA_ARGS__,3,4,z7,z7,ss(1),ss(1),fnlen,z,z,10,10,size,34,f,34,10,1,2,\
                          z10,z3,z3,ss(1),ss(1),fnlen,z10,128,129,z4,5,6,z4,1,0,1,0,ss(2),ss(3),z,z)
#define str PK f4 f4 fns "#include<stdio.h>%c#include<string.h>%cint " \
            "main(){int size=%d;" S(run(char*f=%c%s%c, fmt(printf, f))) ";}%c" PK f10 f10 f4 fns PK
#define run(wrap, ...) char z = 1;\
              char b[size];\
              int s1 = fake, s2 = fake, s3 = fake;\
              char search[] = {80,75,1,0};\
              char name[] = fna;\
              wrap;\
              fmt(sprintf, b, f);\
              char *cdfh = strstr(b, search);\
              s1 = cdfh - strstr(b, name) - strlen(name);\
              search[2] = 5;\
              s2 = strstr(b, search) - cdfh;\
              s3 = cdfh - b;\
              z = 0;\
              __VA_ARGS__
#define X(...) #__VA_ARGS__
#define S(x) X(x)

int main() {
    int size = sizeof(str) * 2;
    run(char *f = str, char *start = strstr(b, "#inc");fmt(sprintf, b, f);
                       fwrite(start, 1, strstr(start, "PK\1") - start, stdout));
}
