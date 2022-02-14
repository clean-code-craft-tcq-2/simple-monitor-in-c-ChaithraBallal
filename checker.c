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

char OutOfRange[100] = "Out Of Range";
char WarningOutOfRange[100] = "Approaching Out of Range";
char BMS_Normal[100] = "Battery is normal";

void printOnConsole(char* fpDisplay)
{  
  printf("%s\n", &fpDisplay);
}

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

/*Code under Test*/
int batteryIsOk(float temperature, float soc, float chargeRate, int (*fptempCheck)(float temperature), int (*fpsocCheck)(float soc), int (*fpchargeRateCheck)(float ChargeRate)) 
{
  int Temp = fptempCheck(temperature);
  int SOC = fpsocCheck(soc);
  int ChargeRate = fpchargeRateCheck(chargeRate);
  return (Temp && SOC && ChargeRate);
}

/*Testing environemt*/
int main() 
{
  assert(batteryIsOk(25, 70, 0.7, &tempCheck, &socCheck, &chargeRateCheck));
  assert(!batteryIsOk(50, 85, 0, &tempCheck, &socCheck, &chargeRateCheck));
}
