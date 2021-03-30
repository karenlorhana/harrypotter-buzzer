#define  Bb    2146
#define  b     2024 
#define  c     1912     
#define  db    1805  
#define  d     1703   
#define  eb    1608 
#define  e     1517      
#define  f     1432     
#define  gb    1351      
#define  g     1276     
#define  ab    1233 
#define  a     1136
#define  bb    1073  
#define  B     1012
#define  C     956 
#define  Db    902 
#define  D     851


// define uma nota especial
#define  R     0

int speakerOut = 9;
int ledPin1=12;
int ledPin2=13;

void setup() { 
  pinMode(speakerOut, OUTPUT);
  pinMode(ledPin1, OUTPUT);
 pinMode(ledPin2, OUTPUT);
  } 


int melody[] = {  b,  e,  g, gb,  e,  B,  a, gb,  e,  g, gb, eb,  f,  b,  b,  e,  g,  gb,  e,  B,  D,  Db,  C,  ab,  C,  B,  bb,  gb,  g,  e,   g,  B,  g,  B,  g,  C,  B,  bb,  gb,  g,  B,  bb,  Bb,  c,   B,  g,  B,  g,  B,  g,  D,  Db,  C,  ab,  C,  B,  bb,  gb,  g,   e, R };
int beats[]  = { 32, 64, 16, 32, 64, 32, 64, 64, 64, 16, 32, 64, 32, 64, 32, 64, 16,  32, 64, 32, 64,  32, 64,  32, 64, 32,  64,  32, 32, 128, 32, 64, 32, 64, 32, 64, 32,  64,  32, 64, 16,  32,  64, 32, 128, 32, 64, 32, 64, 32, 64,  32, 64,  32, 64, 32,  64,  32, 32, 128, 8 }; 
int MAX_COUNT = sizeof(melody) / 2; // tamanho da musica p/ loop

// define o tempo
long tempo = 10000;
// define a pausa entre as notas
int pause = 1000;
int rest_count = 100; 

int tone_ = 0;
int beat = 0;
long duration  = 0;

void playTone() {
  long elapsed_time = 0;
  if (tone_ > 0) { 
    while (elapsed_time < duration) {

      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ / 2);

      // DOWN
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ / 2);

      // Keep track of how long we pulsed
      elapsed_time += (tone_);
    } 
  }
  
  else {
    for (int j = 0; j < rest_count; j++) { 
      delayMicroseconds(duration);  
    }                                
  }                                 
}

void loop() {
  // adiciona um contador de melody[] e beats[]
  for (int i=0; i<MAX_COUNT; i++) {
    tone_ = melody[i];
    beat = beats[i];

    duration = beat * tempo; // definir o tempo
    

if (duration>=340000){
    digitalWrite(ledPin1,HIGH);
    digitalWrite(ledPin2,LOW);
  }else{
digitalWrite(ledPin1,LOW);
    digitalWrite(ledPin2,HIGH);
  }
    playTone(); 
    // A pause between notes...
    delayMicroseconds(pause);
    }
  }
