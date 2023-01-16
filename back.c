# include <reg52.h>

typedef unsigned char u8;
typedef unsigned int u16;

void delay()
{
	u8 a, b;
	for(a = 0; a < 200; a++)
		for(b = 0; b < 200; b++);
}

int main(void)
{
	u8 LED = 0x01;
	while(1)
	{
		P0 = 0xff;
		delay();
		P0 = 0;
	    delay();
	}		
}

//hot_fix
