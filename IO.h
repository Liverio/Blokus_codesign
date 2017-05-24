#ifndef IO_H
#define IO_H

#include <stdio.h>
#include "types.h"

void printGameStatus(square board[][14], char *tiles_hero, char *tiles_rival);
void printAccessibilityMap(char *acc_map[][14]);

#endif
