#include <Proyecto.h>
#define LCD_ENABLE_PIN PIN_C6
#define LCD_RS_PIN PIN_C4
#define LCD_RW_PIN PIN_C5
#define LCD_DATA4 PIN_C0
#define LCD_DATA5 PIN_C1
#define LCD_DATA6 PIN_C2
#define LCD_DATA7 PIN_C3
#define disminuir PIN_A0
#define aumentar PIN_A1
#include <lcd.c>

void main()
{
   set_tris_b(0xFF);
   set_tris_c(0xFF);
   set_tris_e(0x00);
   lcd_init();
   unsigned int8 entrada;
  
   
   float salida;
   float salidadef;
   int ref=50;
   while(TRUE)
   {
      entrada=input_b();
      salida=entrada;
      salidadef=salida*5/(255*0.049);
      if(input(disminuir)==0){
         ref--;
      }else if(input(aumentar)==0){
         ref++;
      }
      if(ref>salidadef){
         output_low(PIN_C7);
      }else{
         output_high(PIN_C7);
      }
      printf(lcd_putc,"\fT: %f %cC",salidadef,223);
      lcd_gotoxy(1,2);
      printf(lcd_putc,"Trf: %i %cC",ref,223);
      delay_ms(300);
      //TODO: User Code
   }

}
