
#define BUTTON 7

String buffer = "";
int command = 0;

int button_state;
int last_button_state = LOW;
int send_temp = 0;

long debounce_time = 0;
long debounce_delay = 50;
char msg[32];

void setup() {
  Serial1.begin( 9600 );
  pinMode( BUTTON, INPUT );
}

void loop() {
  int current_button_state = digitalRead( BUTTON );
  if ( current_button_state != last_button_state ) {
    debounce_time = millis();
  } 
  
  if ( (millis() - debounce_time) > debounce_delay ) {
    if ( current_button_state != button_state ) {
      button_state = current_button_state;
      if ( button_state == HIGH ) {
        led_state = !led_state;
        sprintf( msg, "LED state: %d", led_state );
        Serial1.print( msg );
      }
    }
  }

  if ( Serial1.available() ) {
    buffer = Serial1.readString();
    command = buffer.toInt();
    if ( command ) {
      led_state = !led_state;
      sprintf( msg, "LED state: %d", led_state );
      Serial1.print( msg );
    } 
  }
  
  digitalWrite( LED, led_state );
  last_button_state = current_button_state;
}

float get_temp() {
  int sensor_reading = analogRead( SENSOR ) 
  int average = calculate_average( sensor_reading );  
  float voltage = (average * 5.0)/1024.0;
  float temp = (voltage - 0.5) * 100 ;
  return temp;
}

