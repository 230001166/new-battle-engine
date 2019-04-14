#include <stdlib.h>
#include <time.h>
#include "utilityFunctions.h"

int utilityFunctions::random (int min, int max) {

    int randomNumber = rand () % (max - min + 1) + min;

    return randomNumber;
}
