unsigned long previousTime = 0;
int outState = LOW;
int potVal = 0;
const int potPin = A6, gatePin = D2;
int noteValue = 0;

//1V/oct and 12 semi-tones/oct => 1 semi-tones = 1/12 V = 0.083 V
//DAC output 0=0.35V and 4094=4.5V => 4095 steps = 4,15V delta => 1 steps = 4,15 / 4095 V = 0.001 V = 1 mV
//Par mesure 1V = 815
const int semiTone = 68; //815/12
const int octave = 815;


/*const float minor[] = {0.0, //C
                      0.1666, //D
                      0.2499, //Eb,
                      0.4165, //F
                      0.5831, //G
                      0.6664, //Ab
                      0.833, //Bb
                      1 //C};*/

/*
  * *   * * *     1 3   6 8 10
 * * * * * * *   0 2 4 5 7 9  11 12
 */
//const int C=0, Db=1, D=2, Eb=3, E=4, F=5, Gb=6, G=7, Ab=8, A=9, Bb= 10, B=11;
const int minor[] = {0, 2, 3, 5, 7, 8, 10, 12};
const int major[] = {0, 2, 4, 5, 7, 9, 11, 12};

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  pinMode(gatePin, OUTPUT);
  pinMode(potPin, INPUT);
  analogWriteResolution(12);
}

void loop() {
  

  if(outState == LOW)
  {
    outState = HIGH;
    int dacValue = major[random(8)]*semiTone + 2*octave;
   
    analogWrite(DAC, dacValue);
  }
  else
  {
    outState = LOW;
  }

  digitalWrite(LED_BUILTIN, outState);
  digitalWrite(gatePin, outState);
  
  potVal = analogRead(potPin);
  delay(1023 - potVal);
}
