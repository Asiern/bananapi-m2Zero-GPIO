#ifndef _BANANAPIM20_H
#define _BANANAPIM20_H

#define SUCCESS 0
#define ERROR -1

int exportIO(const char *id);
int setPortDirection(const char *id, unsigned int direction);
int unexportIO(const char *id);
char *readIO(const char *id, void *callback);
int writeIO(const char *id, const char *value);

#endif