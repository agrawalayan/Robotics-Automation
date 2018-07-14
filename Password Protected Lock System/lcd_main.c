
#define lcd_data P1

sbit rs=P3^7;
sbit rw=P3^6;
sbit en=P3^5;

void str_lcd(unsigned char[]);
void delay_ms(unsigned int n)
{
int i,j;
for(i=0;i<n;i++)
for(j=0;j<124;j++);
}


void write_lcd(unsigned char dat)
{
lcd_data=dat;
rw=0;
en=1;
delay_ms(2);
en=0;
}

void cmd_lcd(unsigned char cmd)
{
rs=0;
write_lcd(cmd);
}

void disp_lcd(unsigned char c)
{
rs=1;
write_lcd(c);
}

void init_lcd(void)
{
cmd_lcd(0x02);
cmd_lcd(0x38);
cmd_lcd(0x01);
cmd_lcd(0x0c);
cmd_lcd(0x06);
cmd_lcd(0x80);
//delay_ms(2);
}

void str_lcd(unsigned char *s)
{
  while(*s)
  disp_lcd(*s++);
}



