#include <Servo.h>
Servo myservo;
int Motor = 11;                 // entrada para el mosfest y control del motor de 12v
int entrada_analogica= A0;     //entrada de potenciometro
int sensor_entrada = 12;       //sensor de aproximidad de entrada a la mesa
int sensor_salida = 13;        //sensor de aproximidad de salida a a mesa
int estado_entrada;
int estado_salida;

void setup() {
  myservo.attach(10);                    //pin del servo motor
  pinMode (Motor, OUTPUT);               // designamos los pines como pines de salida y entrada
  pinMode (entrada_analogica, INPUT);    // entrada
}

void loop() {
  Motor_12v();
  SERVO();
}

// funcion para el control del motor de 12v
void Motor_12v(){
  int valor_entrada_analogica =0;                                //  declaramos  las variables de tipo entero
  int valor_salida_pwm=0;                                        //  declaramos  la variable de tipo entero para la ulizacion de la modulacion por ancho de pulso (pwm)
  valor_entrada_analogica = analogRead(entrada_analogica);       // Guardamos la lectura analogica en la variable (valor_entrada_analógica)
  valor_salida_pwm =map(valor_entrada_analogica,0, 1023,0,255);  // guardamos el mapeo en la variable (valor salida)
  analogWrite(Motor, valor_salida_pwm);                          // manifestamos en el led la lectura analogica que hemos reducido de( 0 - 255)
                                                                 // donde 0 es 0 voltios y 255 viene ser 5 voltios
}
//  funcion para el moviemieto del servo Prototipo
void SERVO(){
  estado_entrada=digitalRead(sensor_entrada);                    // conocer si el sensor de aproximacion detecta un objeto para ponerse en alto (HIGH)               
  estado_salida=digitalRead(sensor_salida);
  myservo.write(0);                                              //el servo inicia con un grado de 0
  if(estado_entrada == HIGH){                                    //pregunta si el sensor detecto un objeto
    myservo.write(30);                                           // el servo realiza un movimeinto de 30 grados
    delay(100);
  }
  if(estado_salida == HIGH){
    myservo.write(0);
    delay(100);
  }
}
