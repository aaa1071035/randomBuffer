#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void randBuffer(int* buf, int len)
{
    srand(time(NULL));

    for(int i=0; i<len; i++)
    {
        buf[i]=i;
    }

    for(int i=0; i<len; i++)
    {
        int choose;
        int bTemp;

        choose=(rand() % len);
        bTemp=buf[i];
        buf[i]=buf[choose];
        buf[choose]=bTemp;
    }
}

int main()
{
    uint8_t bBuf[10];
    uint8_t bBufLength;

    bBufLength=sizeof(bBuf)/sizeof(uint8_t);
    memset(bBuf, 0, sizeof(bBuf));
    randBuffer(bBuf, bBufLength);

    for(int i=0; i<bBufLength; i++)
    {
        printf("%d ", bBuf[i]);
    }
    printf("\n");
    return 0;
}
