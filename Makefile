.POSIX:
PREFIX = /usr/local

install: unlockpt
	cp -f -- unlockpt ${PREFIX}/bin

unlockpt: unlockpt.c

uninstall:
	rm -f -- ${PREFIX}/bin/unlockpt

clean:
	rm unlockpt
