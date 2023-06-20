int puts(const char *);
int grantpt(int);
int unlockpt(int);
char *ptsname(int);

int main(int argc, char *argv[]){
	if(argc != 1) puts(
		"unlockpt  Grant and unlock stdin slave PTY\n"
		"USAGE: unlockpt <&UNGRATND_AND_LOCKED_PTY_FD\n"
		"NOTE: This is useful after a `exec 3<>/dev/ptmx`"
	); else
		return (grantpt(0) || unlockpt(0)) ? 1 : (ptsname(0) ? 0 : 0);
	return 1;
}
