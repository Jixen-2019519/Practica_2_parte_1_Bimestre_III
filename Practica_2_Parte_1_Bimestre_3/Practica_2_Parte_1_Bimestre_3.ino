 /*
 * Fundacion Kinal
 * Centro educativo tecnico laboral Kinal
 * Electronica
 * Grado: Quinto
 * Sección: A
 * Curso: Taller de electronica digital y reparación de computadoras I
 * Nombre: Juan Manuel Sebastián Ixen Coy
 * Carnet: 2019519
 * Proyecto: Práctica 2, parte 1
 */ 

 #define LED 6
 #define Potenciometro A0

int Intensidad;
int Posicion;

 void setup() {
pinMode(LED,OUTPUT);
pinMode(Potenciometro,INPUT);
}

void loop() {
Intensidad = analogRead (Potenciometro);
Posicion = map(Intensidad, 0, 1023, 0, 255);
analogWrite(LED, Posicion);
}
