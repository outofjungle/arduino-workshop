#define LED 9

String buffer = "";
int command = 0;

void setup() {
  Serial1.begin( 9600 );  
  pinMode( LED, OUTPUT );    
}

void loop() {
  if ( Serial1.available() ) {
    buffer = Serial1.readString();
    command = buffer.toInt();
    set_led_intensity( command );
  }
}

void set_led_intensity( int value ) {
  if ( value < 0 ) {
    value = 0;
  } else if ( value > 255 ) {
    value = 255;
  }
  analogWrite( LED, value );
}

