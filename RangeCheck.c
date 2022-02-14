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

int tempCheck(float temperature)
{
    if(temperature <= TEMPLOWTHRESHOLD || temperature >= TEMPHIGHTHRESHOLD) 
    {
      printOnConsole(&OutOfRange);      
      return 0;
    }
    else if( (temperature >= TEMPLOWTHRESHOLD_WARNING) || (temperature >= TEMPHIGHTHRESHOLD_WARNING) )
    {
      printOnConsole(&WarningOutOfRange);
    }
    else
    {
      printOnConsole(&BMS_Normal);
    }
    return 1;        
}

int socCheck(float soc)
{
  if(soc <= SOCLOWTHRESHOLD || soc >= SOCHIGHTHRESHOLD) 
  {
    printOnConsole(&OutOfRange);
    return 0;
  }
  else if( (soc >= SOCLOWTHRESHOLD_WARNING) || (soc >= SOCHIGHTHRESHOLD_WARNING) )
  {
    printOnConsole(&WarningOutOfRange);
  }
  else
  {
    printOnConsole(&BMS_Normal);
  }
  return 1;    
}

int chargeRateCheck(float ChargeRate)
{
    if(ChargeRate >= CHARGERATETHRESHOLD) 
    {
      printOnConsole(&OutOfRange);
      return 0;
    }
    else if(ChargeRate >= CHARGERATETHRESHOLD_WARNING)
    {
      printOnConsole(&WarningOutOfRange);
    }
    else
    {
      printOnConsole(&BMS_Normal);
    }
    return 1;     
}
