#include <stdio.h>
#include <assert.h>

#define SOCLOWTHRESHOLD               20
#define SOCHIGHTHRESHOLD              80
#define SOCLOWTHRESHOLD_WARNING       24
#define SOCHIGHTHRESHOLD_WARNING      76
#define TEMPLOWTHRESHOLD              0
#define TEMPHIGHTHRESHOLD             45
#define TEMPLOWTHRESHOLD_WARNING     -2.25
#define TEMPHIGHTHRESHOLD_WARNING     42.25
#define CHARGERATETHRESHOLD           0.8
#define CHARGERATETHRESHOLD_WARNING   0.76

extern int tempCheck(float temperature);
extern int socCheck(float soc);
extern int chargeRateCheck(float ChargeRate);
extern void printOnConsole(char* fpDisplay);
