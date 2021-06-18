#define BLUE 3
#define GREEN 5
#define RED 6
#define RGB_MIN 0
#define RGB_MAX 255
#define delayTime 5

// Custom types for HOF
typedef bool (*IntPred)(int);
typedef int (*UniFun)(int*);

void setup() {
  initialise();
}

void loop() {
  fade(RED);
  fade(BLUE);
  fade(GREEN);
}


//==================================



void initialise() {
  pinMode(BLUE, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(RED, OUTPUT);
  digitalWrite(RED, LOW);
  digitalWrite(BLUE, LOW);
  digitalWrite(GREEN, LOW);
}


void fade(int led) {
  fadeIn(led);
  fadeOut(led);
}


void fadeIn(int led) {
  fadeLoop(led, RGB_MIN, isLessThanRgbMax , incr);
  }

void fadeOut(int led) {
  fadeLoop(led, RGB_MAX, isMoreThanRGBMin , decr);
  }

void fadeLoop(int led, int value, IntPred pred, UniFun cons) {
  for (; pred(value) ;) {
    analogWrite(led, cons(&value));
    delay(delayTime);
    }
}


bool isMoreThanRGBMin(int n) {return n > RGB_MIN;}
int decr(int *n) {return --*n;}
bool isLessThanRgbMax(int n) {return n < RGB_MAX;}
int incr(int *n) {return ++*n;}
