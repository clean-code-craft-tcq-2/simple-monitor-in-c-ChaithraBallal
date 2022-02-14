#include <stdio.h>
#include <assert.h>
#include "RangeCheck.h"

char OutOfRange[100] = "Außer Reichweite";
char WarningOutOfRange[100] = "Annäherung außerhalb der Reichweite";
char BMS_Normal[100] = "Batterie ist normal";

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
