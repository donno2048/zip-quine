#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define small_delay() usleep(100000)
#define delay() usleep(1000000)
// generated on my system using:
// echo | bash --rcfile <(echo "PS1='$PS1'") -i 2>&1 | head -n1 | sed -n l | sed 's/\$$//'
#define PS1 "\033[01;32mroot\033[00m@\033[01;34m/root/zip-quine\033[00m$ "

int shell(const char *command) {
    static const char *bash = "/bin/bash -c \"%s;%s\"";
    static const char *envs = "gcc(){ $(which gcc) -Wall -Wextra -Wpedantic \\$@; }";
    char *buf = malloc(strlen(bash) + strlen(envs) + strlen(command));
    sprintf(buf, bash, envs, command);
    fflush(stdout);
    delay();
    while (*command) {
        printf("%c", *(command++));
        fflush(stdout);
        small_delay();
    }
    delay();
    puts("");
    int status = system(buf);
    free(buf);
    printf(PS1);
    return status || !WIFEXITED(status) || WEXITSTATUS(status);
}

int main() {
    printf(PS1);
    shell("gcc gen.c");
    shell("./a.out > main.c");
    for (int i = 0; i < 3; i++)
        if (shell("cat main.c")         ||
            shell("gcc main.c")         ||
            shell("rm main.c")          ||
            shell("./a.out > main.zip") ||
            (shell("unzip main.zip") > 1)) return -1;
    return 0;
}
