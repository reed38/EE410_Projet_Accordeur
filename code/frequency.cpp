#include <string>
#include <vector>
#include "frequency.h"

#define TrustDistance 20
#define mintrustDistance 2
#define MaxTrustDistance 500
void initializeFrequency()
{

    // Tableau de paires {fréquence, nom}
    std::pair<int, std::string> frequencies[] = {
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
        {2093, "C7"}, {2217, "C7S"},
        {2349, "D7"}, {2489, "D7S"},
        {2637, "E7"}, {2794, "F7"},
        {2960, "F7S"}, {3520, "A7"},
        {3729, "A7S"}, {3951, "B7"},
        {4186, "C8"}, {4435, "C8S"},
        {4699, "D8"}, {4978, "D8S"},
        {5274, "E8"}, {5588, "F8"},
        {5920, "F8S"}, {6272, "G8"},
        {6645, "G8S"}, {7040, "A8"},
        {7459, "A8S"}, {7902, "B8"}
    };

    // Ajout des valeurs à la liste de notes
    for (const auto& pair : frequencies) {
        listAllNotes.push_back({pair.first, pair.second});
    }
    std::pair<int, std::string> guitarFrequencies[] = {
        {82, "E2"},
        {110, "A2"},
        {146, "D3"},
        {196, "G3"},
        {247, "B3"},
        {330, "E4"}
    };

    for (const auto& pair : guitarFrequencies) {
        listGuitarNotes.push_back({pair.first, pair.second});
    }
}

    int main (void)
    {
    initializeFrequency();
        printf("salutation\n");

    }


std::pair<note,int> findCloserNote(int frequency,std::vector<note> frequencyTab)
{
    note currentCloser;
    int minDistance=MaxTrustDistance;
    for(auto i:frequencyTab)
    {
        
        if(abs(i.frequency-frequency)<=TrustDistance)
        {
            currentCloser=i;
            minDistance=abs(i.frequency-frequency);      
            if(minDistance<=mintrustDistance) 
            {
                break;
            }     
        }
        
    }
    return(std::pair<note,int> {currentCloser, minDistance});

}

std::string tuneSTD(int frequency)
{
    std::pair<note,int>  result=findCloserNote(frequency,listGuitarNotes);
    std::string left="";
    std::string right="";
    if(result.second<1)
    {

    }


}


