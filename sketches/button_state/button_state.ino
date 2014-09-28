
#define BUTTON 7
#define LED 9

int led_state = LOW;
int button_state;
int last_button_state = LOW;

long debounce_time = 0;
long debounce_delay = 50;
char msg[32];

void setup() {
  Serial1.begin( 9600 );
  pinMode( BUTTON, INPUT );
  pinMode( LED, OUTPUT );
  digitalWrite( LED, led_state );
}

void loop() {
  int current_button_state = digitalRead( BUTTON );
  if ( current_button_state != last_button_state ) {
    debounce_time = millis();
  } 
  
  if ( (millis() - debounce_time) > debounce_delay ) {
    if ( current_button_state != button_state ) {
      button_state = current_button_state;
      sprintf( msg, "Button state: %d", button_state );
      Serial1.print( msg );
      if ( button_state == HIGH ) {
        led_state = !led_state;
      }
    }
  }
  
  digitalWrite( LED, led_state );
  last_button_state = current_button_state;
}

