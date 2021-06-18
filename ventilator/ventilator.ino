
#include <dht_nonblocking.h>
#define DHTPIN 2
#define DHT_SENSOR_TYPE DHT_TYPE_11

#define POWER 5
#define DIR1 3
#define DIR2 4
#define FAN_MIN_POWER 90
#define FAN_MAX_POWER 255

#define UNBEARABLE_TEMPERATURE 22

#define DHT_SENSOR_TYPE DHT_TYPE_11

static const int DHT_SENSOR_PIN = 2;
DHT_nonblocking dht_sensor( DHT_SENSOR_PIN, DHT_SENSOR_TYPE );


void setup() {
  initialise();
}

void loop() {
  analogWrite(POWER, get_power_lv());
  float temperature;
  float humidity;

  if (measure_environment( &temperature, &humidity ) == true && temperature > UNBEARABLE_TEMPERATURE) {
    


    /* Measure temperature and humidity.  If the functions returns
       true, then a measurement is available. */
      Serial.print( "T = " );
      Serial.print( temperature, 1 );
      Serial.print( " deg. C, H = " );
      Serial.print( humidity, 1 );
      Serial.println( "%" );
  }
  else {
    digitalWrite(DIR1, LOW);
  }
}


//==============

void initialise() {
  pinMode(POWER, OUTPUT);
  pinMode(DIR1, OUTPUT);
  pinMode(DIR2, OUTPUT);
  digitalWrite(POWER, HIGH);
  digitalWrite(DIR1, HIGH);
  digitalWrite(DIR2, LOW);
  Serial.begin(9600);
}


int get_power_lv() {
  return map(analogRead(A0), 0, 1023, FAN_MIN_POWER, FAN_MAX_POWER);
}

static bool measure_environment( float *temperature, float *humidity )
{
  static unsigned long measurement_timestamp = millis( );

  /* Measure once every four seconds. */
  if ( millis( ) - measurement_timestamp > 3000ul )
  {
    if ( dht_sensor.measure( temperature, humidity ) == true )
    {
      measurement_timestamp = millis( );
      return ( true );
    }
  }

  return ( false );
}
