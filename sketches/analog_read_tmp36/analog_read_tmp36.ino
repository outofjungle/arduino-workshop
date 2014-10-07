#define SENSOR A0

float temp = 0;
long input_sum = 0;
int input_count = 0;

void setup() {
  Serial1.begin(9600);
}

void loop() {
  float current_temp = get_temp();
  
  if (current_temp != temp ) {
    temp = current_temp;
    
    Serial1.print( "temp: " );
    Serial1.print( temp );
    Serial1.print( " C" );
  }

  delay( 500 );
}

float get_temp() {
  int sensor_reading = analogRead( SENSOR );
  int average = calculate_average( sensor_reading );  
  float voltage = (average * 5.0)/1024.0;
  float temp = (voltage - 0.5) * 100 ;
  return temp;
}

int calculate_average( int value ) {
  input_sum += value;
  input_count++;
  int average =  input_sum / input_count;  

  if (input_count > 10) {
    input_sum -= average;
    input_count = 10;
  }
  return average;
}
