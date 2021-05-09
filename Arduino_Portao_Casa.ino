
#define relay_pin_a 0
#define relay_pin_b 1
#define auto_pin 2
#define piri_pin 4
unsigned long minutos=300000; //5 minutos

bool ligar_bool=false;

unsigned long ligado_millis=0;
unsigned long start_millis = 0;

void setup() {                
  // initialize the digital pin as an output.
  pinMode(relay_pin_a, OUTPUT); 
  pinMode(relay_pin_b, OUTPUT); 
  pinMode(auto_pin, INPUT);
  pinMode(piri_pin, OUTPUT);
  digitalWrite(relay_pin_a, LOW);
  digitalWrite(relay_pin_b, LOW);
  digitalWrite(piri_pin, LOW);
}

void loop() {
  if(digitalRead(auto_pin)==LOW){
    digitalWrite(relay_pin_a, HIGH);
    digitalWrite(relay_pin_b, HIGH);

    while(ligado_millis < minutos){
      if(digitalRead(auto_pin)==LOW){
        start_millis=millis();
        digitalWrite(piri_pin, HIGH);  
        delay(500);
        digitalWrite(piri_pin, LOW);
        delay(500);       
      }
      ligado_millis= millis()-start_millis;       
    }
    digitalWrite(relay_pin_a, LOW);
    digitalWrite(relay_pin_b, LOW);
    digitalWrite(piri_pin, LOW);
    ligado_millis=0;         
  }
}
