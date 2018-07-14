#include<reg51.h>
#include"lcd_main.h"
#include"keypad_main.h"
#include<stdio.h>
//unsigned char* tostring(int);
sbit Dmotor=P3^0;
sbit swtch=P0^0;
sbit mb=P0^1;
void main()
{

unsigned char count[4]="\0";
unsigned char j,k=0,read_pwd[4];
unsigned char password[4]="5641";
Dmotor=0;
	init_lcd();
	there:	
	if(swtch==1)
while(1)
	{if(mb==1)
		{
			i++;
		cmd_lcd(0x80);
	  str_lcd("Do not disturb!!");
		delay_ms(3000);}
		else
		cmd_lcd(0x01);

	
if(swtch==0)
goto here;  }           

here:
if(swtch==0)
{
{int x, rem, len = 0, n;
 
    n = i;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (x = 0; x < len; x++)
    {
        rem = i % 10;
        i = i / 10;
        count[len - (x + 1)] = rem ;
    }
    count[len] = '\0';	}

	cmd_lcd(0x80);
str_lcd("Count is");
cmd_lcd(0x80);		
	str_lcd(count);	
delay_ms(5000);
	while(1)
	{if(mb==1)

	{
		cmd_lcd(0x80);
	str_lcd("enter password");
		cmd_lcd(0xc0);
	str_lcd("          ");
		
		cmd_lcd(0xc0);
		for(j=0;j<4;j++)
		{
			read_pwd[j]=0x30+keyscan();
			disp_lcd('*');
			delay_ms(10);
		}	
		//str_lcd(read_pwd);
		for(j=0;j<4;j++)
		{
			if(read_pwd[j]==password[j])
			k++;
		}
		cmd_lcd(0x80);
		if(k==4)
		{
			
			str_lcd("pwd is correct");
			cmd_lcd(0xc0);
			str_lcd("opening.....");
			Dmotor=1;
			delay_ms(500);
			Dmotor=0;
			cmd_lcd(0xc0);
			str_lcd("opened       ");
	cmd_lcd(0x01);	}
		else
		{
			str_lcd("pwd is wrong  ");
				Dmotor=0;
			cmd_lcd(0x01);
		}
		delay_ms(5000);
			
	}
if(swtch==1)
	goto there;}
}
}
/*unsigned char* tostring(int num)
{unsigned char str[10];
    int x, rem, len = 0, n;
 
    n = num;
    while (n != 0)
    {
        len++;
        n /= 10;
    }
    for (x = 0; x < len; x++)
    {
        rem = num % 10;
        num = num / 10;
        str[len - (x + 1)] = rem ;
    }
    str[len] = '\0';
		return str;
}*/