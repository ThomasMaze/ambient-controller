void setup() {
  analogWriteResolution(12);
}

void loop() {
  /*
    DAC output 0=0.35V and 4094=4.5V => 4095 steps = 4,15V delta => 1 steps = 4,15 / 4095 V = 0.001 V = 1 mV
    Output voltage = (value / 4095) * Vref
    value = (output voltage / Vref) * 4095
    Vref = (4095 / value) * output voltage

    si on veut 1V alors value = (1 / 5) + 4095 = 815

  with USB

  1V environ 815 (1,015 V)
  */
  analogWrite(DAC, 1630);
}
