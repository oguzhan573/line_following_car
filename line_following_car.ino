const int sag_enable = 11;  // ENABLE A
const int sag_ileri = 10;   // INPUT 1
const int sag_geri = 9;     // INPUT 2
const int sol_ileri = 8;    // INPUT 3
const int sol_geri = 7;     // INPUT 4
const int sol_enable = 6;   // ENABLE B
#define sag 5
#define sagic 4
#define solic 3
#define sol 2
int sagsensor = 0, sagicsensor = 0, solsensor = 0, solicsensor = 0;

void setup()
{
   pinMode(sag_ileri, OUTPUT);
  pinMode(sag_geri, OUTPUT);
  pinMode(sol_ileri, OUTPUT);
  pinMode(sol_geri, OUTPUT);
  pinMode(sag_enable, OUTPUT);
  pinMode(sol_enable, OUTPUT);
  Serial.begin(9600);
  pinMode(sag, INPUT);
  pinMode(sagic, INPUT);
  pinMode(solic, INPUT);
  pinMode(sol, INPUT);
}

void loop()
{
  sagsensor = digitalRead(sag);
  Serial.print("Sağ sensör:");
  Serial.print(sagsensor);
  sagicsensor = digitalRead(sagic);
  Serial.print("Sağiç sensör:");
  Serial.print(sagicsensor);
  solsensor = digitalRead(sol);
  Serial.print("Sol sensör:");
  Serial.print(solsensor);
  solicsensor = digitalRead(solic);
  Serial.print("Sol iç sensör:");
  Serial.println(solicsensor);
  if(sagsensor==0 && sagicsensor==1 && solicsensor==0 && solsensor==0)
  {
    ileri();
  }
    if(sagsensor==0 && sagicsensor==0 && solicsensor==1 && solsensor==0)
  {
    ileri();
  }
    if(sagsensor==0 && sagicsensor==0 && solicsensor==1 && solsensor==1)
  {
   soldon();
  }
    if(sagsensor==0 && sagicsensor==0 && solicsensor==0 && solsensor==1)
  {
   soldon();
  } 
    if(sagsensor==1 && sagicsensor==1 && solicsensor==0 && solsensor==0)
  {
   sagdon();
  }
    if(sagsensor==1 && sagicsensor==0 && solicsensor==0 && solsensor==0)
  {
   sagdon();
  } 
   
}

void ileri()
{
  digitalWrite(sag_ileri, HIGH);
  digitalWrite(sag_geri, LOW);
  digitalWrite(sol_ileri, HIGH);
  digitalWrite(sol_geri, LOW);
  analogWrite(sag_enable, 125);  // motor hızları 255 PWM
  analogWrite(sol_enable, 125);
  
}

void soldon()
{
 digitalWrite(sag_ileri, HIGH);
  digitalWrite(sag_geri, LOW);
  digitalWrite(sol_ileri, LOW);
  digitalWrite(sol_geri, HIGH);
  analogWrite(sag_enable, 125);  // motor hızları 200 PWM
  analogWrite(sol_enable, 125);
}
void sagdon()
{
  digitalWrite(sag_ileri, LOW);
  digitalWrite(sag_geri, HIGH);
  digitalWrite(sol_ileri, HIGH);
  digitalWrite(sol_geri, LOW);
  analogWrite(sag_enable, 125);  // motor hızları 200 PWM
  analogWrite(sol_enable, 125);
}

void dur()
{
  
  digitalWrite(sag_ileri, LOW);
  digitalWrite(sag_geri, LOW);
  digitalWrite(sol_ileri, LOW);
  digitalWrite(sol_geri, LOW);
}
