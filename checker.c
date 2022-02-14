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

void printOnConsole(char *(fpdisplaystring)(float))
{
  printf("%s\n", &fpdisplaystring);
}

/*check for temperature high or low and pass the print string*/
char* tempHighLow(float temp)
{
  char TEMPERATURE_H_L;
  if(temp < TEMPLOWTHRESHOLD)
  {
    TEMPERATURE_H_L = "tempisLow";
  }
  else if(temp > TEMPHIGHTHRESHOLD)
  {
    TEMPERATURE_H_L = "tempishigh";
  }
  else
  {
    TEMPERATURE_H_L = "tempisnormal";
  }
  return TEMPERATURE_H_L;
}

/*check for SOC high or low and pass the print string*/
char *socHighLow(float SOC)
{
  char SOC_H_L;
  if(SOC < SOCLOWTHRESHOLD)
  {
    SOC_H_L = "SOCislow";
  }
  else if(SOC > SOCHIGHTHRESHOLD)
  {
    SOC_H_L = "SOCishigh";
  }
  else
  {
    SOC_H_L = "SOCisnormal";
  }
  return SOC_H_L;
}

int tempCheck(float temperature)
{
    if(temperature < TEMPLOWTHRESHOLD || temperature > TEMPHIGHTHRESHOLD) 
    {
       printOnConsole(&tempHighLow);
       return 0;
    }
    return 1;        
}

int socCheck(float soc)
{
  if(soc < SOCLOWTHRESHOLD || soc > SOCHIGHTHRESHOLD) 
  {
    printOnConsole(&socHighLow);
    return 0;
  }
  return 1;    
}

int chargeRateCheck(float ChargeRate)
{
    if(ChargeRate > CHARGERATETHRESHOLD) 
    {
      printf("Charge Rate out of range!\n");
      return 0;
    }    
    return 1;     
}

/*Code under Test*/
int batteryIsOk(float temperature, float soc, float chargeRate, int (*fpTempcheck)(float temperature), int (*fpSOCcheck)(float soc), int (*fpChargeRatecheck)(float ChargeRate)) 
{
  int Temp = fpTempcheck(temperature);
  int SOC = fpSOCcheck(soc);
  int ChargeRate = fpChargeRatecheck(chargeRate);
  return (Temp && SOC && ChargeRate);
}

/*Testing environemt*/
int main() 
{
  assert(batteryIsOk(25, 70, 0.7, &tempCheck, &socCheck, &chargeRateCheck));
  assert(!batteryIsOk(50, 85, 0, &tempCheck, &socCheck, &chargeRateCheck));
}
