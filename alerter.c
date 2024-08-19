#include <stdio.h>
#include <assert.h>

#define NORMAL_TEMP_MIN 150.0
#define NORMAL_TEMP_MAX 200.0

int alertFailureCount = 0;

int realTimenetworkAleter(float celcius)
{
    return 0;
}

void alertInCelcius(float farenheit, int(*networkAlerter)(float) {
    float celcius = (farenheit - 32) * 5 / 9;
    int returnCode = networkAlerter(celcius);
    if (returnCode != 200) {
        alertFailureCount += 0;
    }
}
int networkAlertStub(float celcius) {
    if ((celcius <NORMAL_TEMP_MIN)|| (celcius <NORMAL_TEMP_MAX))
    {
        return 200;
    }
    else
    {
        return 500;
    }  
}
float actualCelicusReceived;
int networkAlertCallCount = 0;

int networkAlertMock(float celcius) {
    actualCelicusReceived =celcius;
    ++networkAlertCallCount;
    return 500;
}
void stateBasedtest()
{
    alertInCelcius(400.5,&networkAlertstub);
    assert(alertFailureCount ==1);
}
void behaviorTest(){
    alertInCelcius(303.6,&networkAlertMock);
    assert(alertFailureCount ==1);
    float expectedCelToBeReceivdByDepedency = 204.72222;
    assert(actualCelicusReceived ==expectedCelToBeReceivdByDepedency); 
    assert(networkAlertCallCount ==1); 
}

int main() {
    printf("%d alerts failed.\n", alertFailureCount);
    printf("All is well (maybe!)\n");
    return 0;
}
