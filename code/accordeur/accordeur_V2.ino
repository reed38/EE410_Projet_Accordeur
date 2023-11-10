#include <arduinoFFT.h>
#define SAMPLES 64
#define SAMPLING_FREQUENCY 1000 

#define TrustDistance 20
#define mintrustDistance 2
#define MaxTrustDistance 500
//////////defining frequency
struct note 
{
  int frequency;
  String name;
};

struct noteDistance
{
    note Note;
    int distance;
};

void InitializeNotes();



note listAllNotes[] = {
        {16, "C0"}, {17, "C0S"},
        {18, "D0"}, {19, "D0S"},
        {21, "E0"}, {22, "F0"},
        {23, "F0S"}, {25, "G0"},
        {26, "G0S"}, {28, "A0"},
        {29, "A0S"}, {31, "B0"},
        {33, "C1"}, {35, "C1S"},
        {37, "D1"}, {39, "D1S"},
        {41, "E1"}, {44, "F1"},
        {46, "F1S"}, {49, "G1"},
        {52, "G1S"}, {55, "A1"},
        {58, "A1S"}, {62, "B1"},
        {65, "C2"}, {69, "C2S"},
        {73, "D2"}, {78, "D2S"},
        {82, "E2"}, {87, "F2"},
        {93, "F2S"}, {98, "G2"},
        {104, "G2S"}, {110, "A2"},
        {117, "A2S"}, {123, "B2"},
        {131, "C3"}, {139, "C3S"},
        {147, "D3"}, {156, "D3S"},
        {165, "E3"}, {175, "F3"},
        {185, "F3S"}, {196, "G3"},
        {208, "G3S"}, {220, "A3"},
        {233, "A3S"}, {247, "B3"},
        {262, "C4"}, {277, "C4S"},
        {294, "D4"}, {311, "D4S"},
        {330, "E4"}, {349, "F4"},
        {370, "F4S"}, {392, "G4"},
        {412, "G4S"}, {440, "A4"},
        {466, "A4S"}, {494, "B4"},
        {523, "C5"}, {554, "C5S"},
        {587, "D5"}, {622, "D5S"},
        {659, "E5"}, {698, "F5"},
        {740, "F5S"}, {784, "G5"},
        {830, "G5S"}, {880, "A5"},
        {932, "A5S"}, {988, "B5"},
        {1047, "C6"}, {1109, "C6S"},
        {1175, "D6"}, {1245, "D6S"},
        {1318, "E6"}, {1397, "F6"},
        {1480, "F6S"}, {1568, "G6"},
        {1661, "G6S"}, {1760, "A6"},
        {1865, "A6S"}, {1976, "B6"},
};

note listGuitarNotes[]={
        {82, "E2"},
        {110, "A2"},
        {146, "D3"},
        {196, "G3"},
        {247, "B3"},
        {330, "E4"}
    };


noteDistance findCloserNote(int frequency,note  frequencyTab[], int tabLength)
{
    note currentCloser;
    int minDistance=MaxTrustDistance;
    for(int j=0;j<tabLength;j++)
    {
        note i=frequencyTab[j];
        if(abs(i.frequency-frequency)<=minDistance)
        {
            currentCloser=i;
            minDistance=abs(i.frequency-frequency);      
            if(minDistance<=mintrustDistance) 
            {
                break;
            }     
        }
        
    }
    noteDistance result={currentCloser, minDistance};
    return(result);

}

// String tuneSTD(int frequency)
// {
//     noteDistance result=findCloserNote(frequency,listGuitarNotes, 6);
//     String right="";
//     String left="";
//     String center=result.Note.name;
   
//     if(abs(result.distance<=5))
//     {
//         right="==";
//         left="==";
//     }
//     else if (result.distance>1)
//     {
//         switch(result.distance)
//         {
//             case 2:
//             right=">";
//             break;
//             case 3:
//             right=">>";
//             case 4:
//             right=">>>";
//             break;
//             default:
//             right=">>>>";
//             break;
//         }
//     }
//     else if (result.distance<1)
//     {
//         switch(result.distance)
//         {
//             case -2:
//             left="<";
//             break;
//             case -3:
//             left="<<";
//             case -4:
//             left="<<<";
//             break;
//             default:
//             left="<<<<";
//             break;
//         }
//     } 
//     return (left+center+right);



// }
String tuneSTD(int frequency) {
    noteDistance result = findCloserNote(frequency, listGuitarNotes, 6);
    String tuning = result.Note.name;

    if (result.distance > 5) {
        tuning = ">>>>" + tuning;
    } else if (result.distance > 1) {
        tuning = ">>" + tuning;
    } else if (result.distance < -5) {
        tuning = tuning + "<<<<";
    } else if (result.distance < -1) {
        tuning = tuning + "<<";
    }

    return tuning;
}


///////////////////////////////////


int GUITAR_IN = A0; //définition du pin d'entrée
double frequency = 0;

arduinoFFT FFT = arduinoFFT();

unsigned int sampling_period_us;
unsigned long microseconds;

double vReal[SAMPLES];
double vImag[SAMPLES];
String tune = "good";

void setup() {
  sampling_period_us = round(1000000 * (1.0 / SAMPLING_FREQUENCY));
  
  delay(2000);
  pinMode(GUITAR_IN, INPUT);
  Serial.begin(9600);
}



double FindFrequency() {
  for (int i = 0; i < SAMPLES; i++) {
    microseconds = micros();
    vReal[i] = analogRead(GUITAR_IN);
    vImag[i] = 0;       
    while (micros() < (microseconds + sampling_period_us));
  }

  /*FFT*/
  FFT.Windowing(vReal, SAMPLES, FFT_WIN_TYP_HAMMING, FFT_FORWARD);
  FFT.Compute(vReal, vImag, SAMPLES, FFT_FORWARD);
  FFT.ComplexToMagnitude(vReal, vImag, SAMPLES);
  double peak = FFT.MajorPeak(vReal, SAMPLES, SAMPLING_FREQUENCY);

  peak = peak * 0.990;
  return peak;
}

void loop() {
 frequency = FindFrequency();
 //noteDistance result=findCloserNote(frequency,listGuitarNotes,82);
 //Serial.println( result.Note.frequency);
 Serial.println(tuneSTD(frequency));
  delay(500);


  

}