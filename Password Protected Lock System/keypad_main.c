sbit r0=P2^4;   
sbit r1=P2^5;
sbit r2=P2^6;
sbit r3=P2^7;

sbit c0=P2^0;   
sbit c1=P2^1;
sbit c2=P2^2;


char keypad_lut[4][3]={1,2,3,4,5,6,7,8,9,'*',0,'#'};

bit colscan()
{
return(c0&c1&c2);
}

unsigned char keyscan()
{
unsigned char rowval,colval;
c0=c1=c2=1;
r0=r1=r2=r3=0;
while(colscan());
r0=0;
r1=r2=r3=1;
if(!colscan())
{
rowval=0;
goto colcheck;
}
r1=0;
r0=r2=r3=1;
if(!colscan())
{
rowval=1;
goto colcheck;
}
r2=0;
r0=r1=r3=1;
if(!colscan())
{
rowval=2;
goto colcheck;
}
r3=0;
r0=r1=r2=1;
if(!colscan())
{
rowval=3;
}

colcheck:
			if(c0==0)
			colval=0;
			else if(c1==0)
			colval=1;
			else if(c2==0)
			colval=2;
			while(!(c0&&c1&&c2));
			return keypad_lut[rowval][colval];
}
