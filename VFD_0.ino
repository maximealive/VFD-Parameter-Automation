#define BT_START_PLANER     2
#define BT_START_SANDER     3
#define BT_START_TOUPIE     4

#define RELAY_RUN          12
#define RELAY_STOP         11
#define RELAY_SET          10
#define RELAY_UP            9
#define RELAY_REV_FWD       8
#define RELAY_LEFT          7
#define RELAY_DOWN          6
#define RELAY_RIGHT         5

#define LED_PLANER         54
#define LED_SANDER         55

#define PLANER              0
#define SANDER              1
#define TOUPIE              2

#define t_com     80
#define t_idle   450
#define t_long  1300
#define t_func   500

#define DEBOUNCE_DELAY  50

bool bool_bt_planer = false;
bool bool_bt_sander = false;
bool bool_bt_toupie = false;
bool stop_bt = false;

int lastSteadyStatePlaner = LOW;       // the previous steady state from the input pin
int lastFlickerableStatePlaner = LOW;  // the previous flickerable state from the input pin
int currentStatePlaner;                // the current reading from the input pin
unsigned long lastDebounceTimePlaner = 0;  // the last time the output pin was toggled

int lastSteadyStateSander = LOW;
int lastFlickerableStateSander = LOW;
int currentStateSander;
unsigned long lastDebounceTimeSander = 0;

int lastSteadyStateToupie = LOW;
int lastFlickerableStateToupie = LOW;
int currentStateToupie;
unsigned long lastDebounceTimeToupie = 0;

uint8_t menu_state;

unsigned long mytime;

void motor_selection();

void setup() {
  Serial.begin(9600);

  pinMode(BT_START_PLANER, INPUT);
  pinMode(BT_START_SANDER, INPUT);
  pinMode(BT_START_TOUPIE, INPUT);
  //pinMode(BT_STOP, INPUT);
  pinMode(RELAY_RUN, OUTPUT);
  pinMode(RELAY_STOP, OUTPUT);
  pinMode(RELAY_SET, OUTPUT);
  pinMode(RELAY_UP, OUTPUT);
  pinMode(RELAY_REV_FWD, OUTPUT);
  pinMode(RELAY_LEFT, OUTPUT);
  pinMode(RELAY_DOWN, OUTPUT);
  pinMode(RELAY_RIGHT, OUTPUT);

  digitalWrite(RELAY_RUN, HIGH);
  digitalWrite(RELAY_STOP, HIGH);
  digitalWrite(RELAY_SET, HIGH);
  digitalWrite(RELAY_UP, HIGH);
  digitalWrite(RELAY_REV_FWD, HIGH);
  digitalWrite(RELAY_LEFT, HIGH);
  digitalWrite(RELAY_DOWN, HIGH);
  digitalWrite(RELAY_RIGHT, HIGH);
}

void loop() {
  // caso PLANER
  currentStatePlaner = digitalRead(BT_START_PLANER);
  if (!bool_bt_planer & !bool_bt_sander & !bool_bt_toupie) {
    if (currentStatePlaner != lastFlickerableStatePlaner) {
      lastDebounceTimePlaner = millis();
      lastFlickerableStatePlaner = currentStatePlaner;
    }

    if ((millis() - lastDebounceTimePlaner) > DEBOUNCE_DELAY) {
      if (lastSteadyStatePlaner == HIGH && currentStatePlaner == LOW) {
        if (!stop_bt) {
          stop_bt = true;
          bool_bt_planer = true;
          menu_state = PLANER;
          motor_selection();
        }
        else {
          stop();
          stop_bt = false;
        }
      }
      lastSteadyStatePlaner = currentStatePlaner;
    }
  }

  // caso SANDER
  currentStateSander = digitalRead(BT_START_SANDER);
  if (!bool_bt_planer & !bool_bt_sander & !bool_bt_toupie) {
    if (currentStateSander != lastFlickerableStateSander) {
      lastDebounceTimeSander = millis();
      lastFlickerableStateSander = currentStateSander;
    }

    if ((millis() - lastDebounceTimeSander) > DEBOUNCE_DELAY) {
      if (lastSteadyStateSander == HIGH && currentStateSander == LOW) {
        if (!stop_bt) {
          stop_bt = true;
          bool_bt_sander = true;
          menu_state = SANDER;
          motor_selection();
        }
        else {
          stop();
          stop_bt = false;
        }
      }
      lastSteadyStateSander = currentStateSander;
    }
  }

  // caso TOUPIE

  currentStateToupie = digitalRead(BT_START_TOUPIE);
  if (!bool_bt_planer & !bool_bt_sander & !bool_bt_toupie) {
    if (currentStateToupie != lastFlickerableStateToupie) {
      lastDebounceTimeToupie = millis();
      lastFlickerableStateToupie = currentStateToupie;
    }

    if ((millis() - lastDebounceTimeToupie) > DEBOUNCE_DELAY) {
      if (lastSteadyStateToupie == HIGH && currentStateToupie == LOW) {
        if (!stop_bt) {
          stop_bt = true;
          bool_bt_toupie = true;
          menu_state = TOUPIE;
          motor_selection();
        }
        else {
          stop();
          stop_bt = false;
        }
      }
      lastSteadyStateToupie = currentStateToupie;
    }
  }

}

void motor_selection() {
  switch (menu_state) {
    case PLANER:
      Serial.println("caso PLANER");
      if (!bool_bt_sander & !bool_bt_toupie) {
        // set pn_32 -> #6 //
        pn_32();
        // set pn_01 -> value 2840
        delay(t_func);
        pn_01();
        delay(t_func);
        // set pn_03 -> #2 + set pn_06
        pn_03_06();
        delay(t_func);
        // set pn_08 -> value 30
        pn_08();
        delay(t_func);
        // set pn_08 -> value 1.5
        pn_13();
      }

      bool_bt_planer = false;
      stop_bt = true;
      break;

    case SANDER:
      Serial.println("caso SANDER");
      if (!bool_bt_planer & !bool_bt_toupie) {
        // set pn_32 -> #6 //
        pn_32();
        // set pn_01 -> value 2840
        delay(t_func);
        pn_01();
        delay(t_func);
        // set pn_03 -> #2 + set pn_06
        pn_03_06();
        delay(t_func);
        // set pn_08 -> value xx
        pn_08();
        delay(t_func);
        // set pn_08 -> value x.x
        pn_13();
      }
      bool_bt_sander = false;
      break;

    case TOUPIE:
      Serial.println("caso TOUPIE");
      if (!bool_bt_planer & !bool_bt_sander) {
        // set pn_32 -> #6 //
        pn_32();
        // set pn_01 -> value 1435
        delay(t_func);
        pn_01();
        delay(t_func);
        // set pn_03 -> #2 + set pn_06
        pn_03_06();
        delay(t_func);
        // set pn_08 -> value xx
        pn_08();
        delay(t_func);
        // set pn_08 -> value x.x
        pn_13();
        delay(t_func);
      }
      bool_bt_toupie = false;
      break;
  }
}

void pn_32() {
  // set pn32 -> #6 //

  set();
  left();
  // UP  -> Pn35
  upLong();
  left();
  // DOWN -> Pn32
  for (int i = 0; i < 3; i++) {
    down();
  }
  set();
  // UP -> value 6
  upLong();
  set();

  delay(t_func);
}

void pn_01() {

  // LEFT
  left();
  // DOWN -> pn01
  downLong();
  set();
  right();
  upLong();
  down();
  // Value = 2840
  if (bool_bt_planer) {
    right();
    for (int i = 0; i < 2; i++) {
      up();
    }
    right();
    for (int i = 0; i < 8; i++) {
      up();
    }
    right();
    for (int i = 0; i < 4; i++) {
      up();
    }
    for (int i = 0; i < 2; i++) {
      right();
    }
    for (int i = 0; i < 2; i++) {
      down();
    }
  }
  // Value 1420
  else if (bool_bt_sander) {
    right();
    // UP (1)
    up();
    right();
    // UP (4)
    for (int i = 0; i < 4; i++) {
      up();
    }
    right();
    // UP (2)
    for (int i = 0; i < 2; i++) {
      up();
    }
    for (int i = 0; i < 2; i++) {
      right();
    }
    for (int i = 0; i < 2; i++) {
      down();
    }
  }
  else if (bool_bt_toupie) {
    // Value 1435
    right();
    // UP (1)
    up();
    right();
    // UP (4)
    for (int i = 0; i < 4; i++) {
      up();
    }
    right();
    // UP (3)
    for (int i = 0; i < 3; i++) {
      up();
    }
    right();
    // UP (5)
    for (int i = 0; i < 5; i++) {
      up();
    }
    right();
    for (int i = 0; i < 2; i++) {
      down();
    }
  }
  set();

  delay(t_func);
}

void pn_03_06() {
  // pn_03

  up();
  set();
  up();
  set();

  delay(t_func);
  delay(t_func);

  // pn_06

  for (int i = 0; i < 2; i++) {
    up();
  }
  set();
  down();
  set();

  delay(t_func);
}

void pn_08() {
  up();
  set();
  for (int i = 0; i < 2; i++) {
    right();
  }
  for (int i = 0; i < 2; i++) {
    up();
  }
  set();

  delay(t_func);
}

void pn_13 () {
  for (int i = 0; i < 4; i++) {
    up();
  }
  set();
  for (int i = 0; i < 5; i++) {
    up();
  }
  left();
  up();
  set();

  delay(t_func);

  // STOP
  for (int i = 0; i < 2; i++) {
    stop();
  }

  delay(t_func);

  // START
  digitalWrite(RELAY_RUN, LOW);
  delay(t_com);
  digitalWrite(RELAY_RUN, HIGH);
}

void set() {
  digitalWrite(RELAY_SET, LOW);
  delay(t_com);
  digitalWrite(RELAY_SET, HIGH);
  delay(t_idle);
}

void up() {
  digitalWrite(RELAY_UP, LOW);
  delay(t_com);
  digitalWrite(RELAY_UP, HIGH);
  delay(t_idle);
}

void down() {
  digitalWrite(RELAY_DOWN, LOW);
  delay(t_com);
  digitalWrite(RELAY_DOWN, HIGH);
  delay(t_idle);
}

void upLong() {
  digitalWrite(RELAY_UP, LOW);
  delay(t_long);
  digitalWrite(RELAY_UP, HIGH);
  delay(t_idle);
}

void downLong() {
  digitalWrite(RELAY_DOWN, LOW);
  delay(t_long);
  digitalWrite(RELAY_DOWN, HIGH);
  delay(t_idle);
}

void left() {
  digitalWrite(RELAY_LEFT, LOW);
  delay(t_com);
  digitalWrite(RELAY_LEFT, HIGH);
  delay(t_idle);
}

void right() {
  digitalWrite(RELAY_RIGHT, LOW);
  delay(t_com);
  digitalWrite(RELAY_RIGHT, HIGH);
  delay(t_idle);
}

void stop() {
  digitalWrite(RELAY_STOP, LOW);
  delay(t_com);
  digitalWrite(RELAY_STOP, HIGH);
  delay(t_idle);
}
 
