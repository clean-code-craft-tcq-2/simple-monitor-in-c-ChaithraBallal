#include <stdio.h>
#include <assert.h>
#include <RangeCheck.h>

void printOnConsole(char* fpDisplay)
{  
  printf("%s\n", &fpDisplay);
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
