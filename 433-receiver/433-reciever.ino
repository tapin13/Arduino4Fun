#include <VirtualWire.h>

void setup() {
  Serial.begin(9600);
  vw_set_ptt_inverted(true);
  vw_setup(2000);
  vw_rx_start();

}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if(vw_get_message(buf, &buflen)) {
    Serial.println("Got Message");
    int i;
    
    if(buf[0] != 'z') {
      Serial.print("Not our message");
      return;
    }

    char command = buf[2];

    i = 4;
    int number = 0;
    
    while(buf[i] != ' ') {
      number *= 10;
      number += buf[i] - '0';
      i++;
    }
    Serial.print(command);
    Serial.print("");
    Serial.println(number);
  }

}
