const int button = 3; // BUTTON PIN
int counter = 0;
int state = LOW;

void setup() { 
  pinMode(button, INPUT); 
  Serial.begin(9600); 
} 
void loop() { 
  state = digitalRead(button); 
  if (state == HIGH) {  
    counter++;
    Serial.println(counter);
  } 
}
