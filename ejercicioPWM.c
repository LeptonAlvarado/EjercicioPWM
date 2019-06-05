#include<18LF4620.h>
#FUSES NOWDT                    //No Watch Dog Timer
#FUSES NOFCMEN                  //Fail-safe clock monitor disabled
#FUSES NOIESO                   //Internal External Switch Over mode disabled
#FUSES PUT                      //Power Up Timer
#FUSES NOBROWNOUT               //No brownout reset
#FUSES NOPBADEN                 //PORTB pins are configured as digital I/O on RESET
#FUSES NOLPT1OSC                //Timer1 configured for higher power operation
#FUSES NOLVP                    //No low voltage prgming, B3(PIC16) or B5(PIC18) used for I/O
#FUSES NOXINST                  //Extended set extension and Indexed Addressing mode disabled (Legacy mode)
#device ADC = 10

#use delay(clock=16000000)

void aumentarCT();
void disminuirCT();

int16 cicloTrabajo=0;
void main(){
    set_tris_a(0xFF);
    setup_timer_2(T2_DIV_BY_16,249,1); // Preescaler, Timer 2, Poscaler
    setup_ccp1(CCP_PWM);
    //setup_adc_ports(ALL_ANALOG); // Deja todos los puertos en analogos
   // setup_adc(ADC_CLOCK_INTERNAL); // Utiliza el Osc inerno
    while(TRUE){
        //set_adc_channel(0); // Se utiliza canal 0
        //set_adc_channel(3); // Se utiliza canal 0
        //delay_ms(100);
        if(input(PIN_A0) == 1){
            aumentarCT();
            set_pwm1_duty(cicloTrabajo);
        }
        if(input(PIN_A3) == 1){
            disminuirCT();
            set_pwm1_duty(cicloTrabajo);
            }
        
    }
}

void aumentarCT()
{
    cicloTrabajo +=51;
}

void disminuirCT()
{
    cicloTrabajo -=51;
}
