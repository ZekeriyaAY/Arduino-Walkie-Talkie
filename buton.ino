const int buton = 3; // BUTON PİNİ
int sayac = 0;
int butonDurumu = LOW;

void setup() { 
  pinMode(buton, INPUT); 
  Serial.begin(9600); 
} 
void loop() { 
  butonDurumu = digitalRead(buton); 
  if (butonDurumu == HIGH) {  
    sayac++;
    Serial.println(sayac);
  } 
}
