#include "VirtualWire.h"

void setup() {
  Serial.begin(9600);
  vw_set_ptt_inverted(true);
  vw_setup(2000);

}

void loop() {
  int number = 123;
  char symbol = 'c';

  String strMsg = "z ";
    strMsg += symbol;
    strMsg += " ";
    strMsg += number;
    strMsg += " ";

  char msg[255];
  strMsg.toCharArray(msg, 255);

  Serial.println(msg);

  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx();
  delay(1000);
}
