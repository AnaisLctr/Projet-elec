#include <SoftwareSerial.h>

SoftwareSerial mySerial(11, 12); 
char caract;



//roue droite
int END=9;
int IN1=4;
int IN2=5;

//roue gauche
int ENG=10;
int IN3=6;
int IN4=7;

//roue droite canon
int ENA=36;
int IN5=38;
int IN6=40;


//roue gauche canon
int ENB=42;
int IN7=44;
int IN8=46;



void setup() {
  Serial.begin(9600);
  mySerial.begin(9600); //communication module bluetooth

  pinMode(END,OUTPUT);
  pinMode(ENG,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);

  //moteurs canon
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN5,OUTPUT);
  pinMode(IN6,OUTPUT);
  pinMode(IN7,OUTPUT);
  pinMode(IN8,OUTPUT);

  //les roues sont à l'arrêt 
  digitalWrite(END,LOW);
  digitalWrite(ENG,LOW);

  digitalWrite(END,LOW);
  digitalWrite(ENB,LOW);

  //direction des roues
  digitalWrite(IN1,LOW); //roue doite
  digitalWrite(IN2,HIGH);

  digitalWrite(IN3,LOW); //roue gauche
  digitalWrite(IN4,HIGH);
  
  //roues canon
  digitalWrite(IN5,LOW); 
  digitalWrite(IN6,HIGH);

  digitalWrite(IN7,LOW); 
  digitalWrite(IN8,HIGH);

  analogWrite(END,0); 
  analogWrite(ENG,0);
}

void loop() {
  while (mySerial.available()) {
    caract = mySerial.read();
    Serial.println(caract);
    switch(caract){
      case 'A':
        avancer();
        break;
      case 'R':
        reculer();
        break;
      case 'D':
        droit();
        break;
      case 'G':
        gauche();
        break;
      case '0':
        analogWrite(END,0); //la voiture s'arrête lorsque l'on appuie sur aucun bouton
        analogWrite(ENG,0);
        break;
      case 'L': //quand on appuie sur le bouton 'L', les roues du canon jettent la balle
        analogWrite(ENA,150); 
        analogWrite(ENB,150);
        break;
    }
  }
}


void avancer(){
  //Serial.println(caract);

  //direction roue droite
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  //direction roue gauche
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  analogWrite(END,150); //vitesse droit
  analogWrite(ENG,150); //vitesse gauche
}

void reculer(){
  //direction roue droite
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  //direction roue gauche
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

  analogWrite(END,150); //vitesse droit
  analogWrite(ENG,150); //vitesse gauche
}

void droit(){
  //direction roue droite
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
  //direction roue gauche
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  analogWrite(END,150); //vitesse droit
  analogWrite(ENG,150); //vitesse gauche
}

void gauche(){
  //direction roue droite
  digitalWrite(IN1,LOW);
  digitalWrite(IN2,HIGH);
  //direction roue gauche
  digitalWrite(IN3,LOW);
  digitalWrite(IN4,HIGH);

  analogWrite(END,150); //vitesse droit
  analogWrite(ENG,150); //vitesse gauche
}
