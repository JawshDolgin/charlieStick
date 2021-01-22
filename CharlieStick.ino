// PROJECT  :SimonStickRegisterLevelUNO
// PURPOSE  :Register-level demonstration of ACES’ Charlieplexed SimonStick
// DEVICE   :UNO + SimonStick
// AUTHOR   :J. Dolgin, C. D'Arcy
// DATE     :2020 01 30
// MCU      :328P
// COURSE   :ICS4U
// STATUS   :Not Working

#define PORT  PORTB
#define DDR   DDRB
#define pinA  1<<PB5
#define pinB  1<<PB4
#define pinC  1<<PB3
#define pinD  1<<PB2
uint8_t pinMask = pinA | pinB | pinC | pinD;    //compose a convenient mask
struct LED {            //TIGHT binding of related GPIO registers
  uint8_t port;
  uint8_t ddr;
};

LED stick [] = {
  {pinA, pinA | pinB},  //this should get only LED1 to turn on
  {pinB, pinA | pinB},
  {pinB, pinB | pinC},
  {pinC, pinB | pinC},
  {pinC, pinC | pinD},
  {pinD, pinC | pinD},
  {pinA, pinA | pinC},
  {pinC, pinA | pinC},
  {pinB, pinB | pinD},
  {pinD, pinB | pinD},
  {pinA, pinA | pinD},
  {pinD, pinA | pinD},
};
uint8_t ledCount = sizeof(stick) / sizeof(LED);

void setup() {}

void loop() {
  for (uint8_t i = 0; i < ledCount; i++) {
    PORT |= stick[i].port;
    DDR |= stick[i].ddr;
    delay(100);
    PORT &= ~pinMask;
    DDR &= ~pinMask;
  }
}
