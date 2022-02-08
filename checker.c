#include <stdio.h>
#include <assert.h>

int batteryIsOk(float temperature, float soc, float chargeRate, int (*fpTempcheck)(float temperature), int (*fpSOCcheck)(float soc), int (*fpChargeRatecheck)(float ChargeRate)) 
{
  int Temp = fpTempcheck(temperature);
  int SOC = fpSOCcheck(soc);
  int ChargeRate = fpChargeRatecheck(chargeRate);
  return (Temp && SOC && ChargeRate);
}

int Tempcheck(float temperature)
{
    if(temperature < 0 || temperature > 45) 
    {
       Printonconsole(&TempHIGHLOW);
       return 0;
    }
    return 1;
}

int SOCcheck(float soc)
{
  if(soc < 20 || soc > 80) 
  {
    Printonconsole(&SOCHIGHLOW);
    return 0;
  }
   return 1;
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
  char SOC_H_L;
  if(SOC < 20)
  {
    SOC_H_L = "SOCislow";
  }
  elseif(SOC > 80)
  {
    SOC_H_L = "SOCishigh";
  }
  else
  {
    SOC_H_L = "SOCisnormal";
  }
  return SOC_H_L;
}

int main() 
{
  assert(batteryIsOk(25, 70, 0.7, &Tempcheck, &SOCcheck, &ChargeRatecheck));
  assert(!batteryIsOk(50, 85, 0, &Tempcheck, &SOCcheck, &ChargeRatecheck));
}
