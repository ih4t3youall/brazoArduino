const int LED = 2; 
int LEDSTATE=LOW;

int inByte = 0;

int M1_Izq = 12; //Direccion
int M1_Derecha = 13; //Direccion
int M1 =12;

int M2_Izq = 10; //Direccion
int M2_Derecha = 11; //Direccion
int M2 =10;




void setup(){
    Serial.begin(9600); //Open the serial port
    pinMode(LED, OUTPUT); //Set the digital pin as output
    pinMode(M1_Izq, OUTPUT);
    pinMode(M1_Derecha, OUTPUT);
    pinMode(M2_Izq, OUTPUT);
    pinMode(M2_Derecha, OUTPUT);
}

void loop(){

    if(Serial.available() > 0){

        inByte = Serial.read(); //read the incoming byte

      

        if(inByte == '1'){

            girar(1,M1);
            delay(1000);
            stop(M1);

         }
        if(inByte == '2'){

            girar(2,M1);
            delay(1000);
            stop(M1);
        }
       if(inByte == '3'){

            girar(2,M2);
            delay(1000);
            stop(M2);
        }
        if(inByte == '4'){

            girar(1,M2);
            delay(1000);
            stop(M2);
        }
        
        if(inByte == '9'){

          if(LEDSTATE == HIGH){
            LEDSTATE = LOW;
          
          }else {
          LEDSTATE =HIGH;
          }
          
          digitalWrite(LED,LEDSTATE);

        }
        
        
    }
    
    

}

void girar(int direccion,int motor){

  String motorFinal1 = motor+"_Izq";
  String motorFinal2 = motor+"Derecha";
   boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if(direccion == 1){
    inPin1 = HIGH;
    inPin2 = LOW;
  }
  
    digitalWrite(motor, inPin1);
    digitalWrite(motor+1, inPin2);
  

}



void stop(int motor){
    digitalWrite(motor, LOW);
    digitalWrite(motor+1, LOW);
} 

