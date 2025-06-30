/*
TECNOLOGICO DE MONTERREY CAMPUS CIUDAD DE MÉXICO
RETO: BRAZO ROBOTICO CON PIC18F4550 + BLUETOOTH
VERSION 4.1 PWM + BLUETOOTH

Este Codigo corresponde a la parte de control de los brazos roboticos
mediante PWM, controlando la velocidad y direccion de los brazos
*/

void quieto(){
	PWM1_Set_Duty(0);
	PWM2_Set_Duty(0);
}

void arriba(){
	PWM1_Set_Duty(254);
	PWM2_Set_Duty(0);
}

void abajo(){
	PWM1_Set_Duty(0);
	PWM2_Set_Duty(254);
}

void arrancate() {
  ADCON0 = 0X00;
  ADCON1 = 0b0000; //puerto AN es entrada analogica
  delay_ms(100);
}

void main(void){
  delay_ms(100);
  arrancate();

  PWM1_Init(2000);
  PWM1_Start();
  PWM2_Init(2000);
  PWM2_Start();


  while(1){
    int valor1 = 0, valor2 = 0, valor3 = 0, valor4 = 0;
    //LECTURA DE VALORES ADC
    valor1 = ADC_Read(0);
    valor2 = ADC_Read(1);

    //Nota: El V3 debe imitar el V1, El V4 debe imitar el V1
    if(valor1 == valor2){
      //Quedate quieto
      quieto();
    }
    else if(valor1 > valor2){
      //Muevete para arriba
      arriba();
    }
    else if(valor3 < valor1){
      //Muevete para abajo
      abajo();
    }

    delay_ms(100);
  }
}






