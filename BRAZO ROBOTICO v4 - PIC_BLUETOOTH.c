/*
TECNOLOGICO DE MONTERREY CAMPUS CIUDAD DE MÉXICO
RETO: BRAZO ROBOTICO CON PIC18F4550 + BLUETOOTH
VERSION 4.1 PWM + BLUETOOTH

Este Codigo corresponde a la parte de control del modulo bluetooth.
Se encarga de recabar los valores de entradas analogicas de los
goniometros y convertir los valores correspondientes a grados
para finalmente enviar los datos por bluetooth a un dispositivo movil
*/

void arrancate() {
  // Configura los pines como salidas
  TRISB = 0;
	PORTB = 0;
	ADCON0 = 0X00;
	ADCON1 = 0b0000; //entrada AN0 es analoga
  delay_ms(100);
}

float conversion(int dato){
  float grados = (((dato*5.0)/1023)*55.3);
  return grados;
}

void bluetooth(char dato[10], char dato_dos[10], char dato_tres[10], char dato_cuatro[10]){
  UART1_Write_Text("Grados en el GONIOMETRO MAESTRO 1:");
  UART1_Write(10);
  UART1_Write(13);
  UART1_Write_Text(dato);
  UART1_Write(10);
  UART1_Write(13);
  UART1_Write_Text("Grados en el GONIOMETRO ESCLAVO 1:");
  UART1_Write(10);
  UART1_Write(13);
  UART1_Write_Text(dato_dos);
  UART1_Write(10);
  UART1_Write(13);
  UART1_Write_Text("Grados en el GONIOMETRO MAESTRO 2:");
  UART1_Write(10);
  UART1_Write(13);
  UART1_Write_Text(dato_tres);
  UART1_Write(10);
  UART1_Write(13);
  UART1_Write_Text("Grados en el GONIOMETRO ESCLAVO 2:");
  UART1_Write(10);
  UART1_Write(13);
  UART1_Write_Text(dato_cuatro);
  UART1_Write(10);
  UART1_Write(13);
  delay_ms(100);
}

void main(void){
  char bt_uno[10], bt_dos[10], bt_tres[10], bt_cuatro[10];
  
  //INICIA EL PROGRAMA
  UART1_Init(9600);
  delay_ms(100);
  arrancate();
  
  while(1){
    //DEFINICION DE VARIABLES
    float goniometro_uno = 0, goniometro_dos = 0, art_uno = 0, art_dos = 0;
    //INICIA LECTURA DE VALORES
    int valor1 = ADC_Read(0);
    int valor2 = ADC_Read(1);
    int valor3 = ADC_Read(2);
    int valor4 = ADC_Read(3);
    
    //PROCESAMIENTO DE DATOS PARA SU ENVIO X BLUETOOTH
    goniometro_uno = conversion(valor1);
    goniometro_dos = conversion(valor2);
    art_uno = conversion(valor3);
    art_uno = conversion(valor4);
    
  	//MODULO BLUETOOTH
    floatToStr(goniometro_uno,bt_uno);
    floatToStr(goniometro_dos,bt_dos);
    floatToStr(art_uno,bt_tres);
    floatToStr(art_dos,bt_cuatro);
    
    bluetooth(bt_uno, bt_dos, bt_tres, bt_cuatro);
    delay_ms(1000);
  }
}







