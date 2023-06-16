 /*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Juan Manuel Sebastián Ixen Coy
 * Carnet: 2019519
 * Proyecto: Práctica 2, parte 2
 */

#include <Ticker.h>

#define R 3
#define G 4
#define B 5
#define Potenciometro A0

int  Control_Brilo();
void Lectura();

int Brillo;
int Escala;
int Tiempo;

Ticker ISR_tiempo(Lectura, 10);

void setup() 
{
  pinMode(Potenciometro, INPUT);
  ISR_tiempo.start();
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

void loop() 
{
    //Configuración de la led RGB
    analogWrite(R, 174);
    analogWrite(G, 92);
    analogWrite(B, 230);
    delay(Tiempo);

    analogWrite(R, 255);
    analogWrite(G, 255);
    analogWrite(B, 255);
    delay(Tiempo);
 
    analogWrite(R, 0);
    analogWrite(G, 255);
    analogWrite(B, 255);
    delay(Tiempo);
    
    analogWrite(R, 189);
    analogWrite(G, 174);
    analogWrite(B, 20);
    delay(Tiempo);

    analogWrite(R, 255);
    analogWrite(G, 87);
    analogWrite(B, 35);
    delay(Tiempo);
    //Actualización    
    ISR_tiempo.update();
}

int Control_Brilo()
{
  Brillo = analogRead(Potenciometro);
  Escala = map (Brillo, 0 , 1023, 100, 1000);
  return Escala;
}

 void Lectura()
{
  Tiempo = Control_Brilo();
}    
