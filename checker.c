#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate) 
{
  if(temperature < 0 || temperature > 45) {
    printf("Temperature out of range!\n");
    return 0;
  } else if(soc < 20 || soc > 80) {
    printf("State of Charge out of range!\n");
    return 0;
  } else if(chargeRate > 0.8) {
    printf("Charge Rate out of range!\n");
    return 0;
  }
  return 1;
}

int Tempcheck(float temperature)
{
    if(temperature < 0 || temperature > 45) 
    {
       printf("Temperature out of range!\n");
    }
    return 0;
}

int SOCcheck(float soc)
{
  if(soc < 20 || soc > 80) 
  {
    printf("State of Charge out of range!\n");
    return 0;
  }
}

int ChargeRatecheck(float ChargeRate)
{
    if(chargeRate > 0.8) 
    {
      printf("Charge Rate out of range!\n");
    }
    return 0;
}

void Printonconsole(char *(fpdisplaystring)(float))
{
  printf("%s\n", &fpdisplaystring);
}

/*check for temperature high or low and pass the print string*/
char* TempHIGHLOW(float temp)
{
  char TEMPERATURE_H_L;
  if(temp < 0)
  {
    TEMPERATURE_H_L = "tempisLow";
  }
  elseif(temp>45)
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
char *SOCHIGHLOW(float SOC)
{
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7));
  assert(!batteryIsOk(50, 85, 0));
}
