int puts(const char*);
int grantpt(int);
int unlockpt(int);
char *ptsname(int);
int perror(const char*);

#define NULL (void*)0

#define errif(cond,errmsg) if(cond){ perror(#errmsg); return 1;}

int main(int argc, char *argv[]){
	if(argc != 1){
		puts(
			"unlockpt  Grant and unlock stdin slave PTY\n"
			"USAGE: unlockpt <&UNGRATND_AND_LOCKED_PTY_FD\n"
			"NOTE: This is useful after a `exec 3<>/dev/ptmx`"
		);
		return 1;
	}

	errif(grantpt(0) == -1, grantpt)
	errif(unlockpt(0) == -1, unlockpt)

	char *f = ptsname(0);
	errif(f == NULL, ptsname)
	puts(ptsname(0));
}
