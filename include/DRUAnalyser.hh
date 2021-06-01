#ifndef DRUAnalyser_h
#define DRUAnalyser_h

#include "globals.hh"
#include "TROOT.h"
#include "TFile.h"
#include "TTree.h"
#include <fstream>
#include <vector>
#include "TDirectory.h"
#include "G4SystemOfUnits.hh"

class Analyser {
public:
    Analyser();
    ~Analyser();
    void SetFileName(G4String file_name);
    static Analyser* GetInstance();
    void AppendRow(G4double particleEnergy, G4double CoinEnergy, G4double VetoEnergy, G4double TopDonutEnergy, G4double TopCylinderEnergy, G4double BotDonutEnergy, G4double BotCylinderEnergy);
    void SaveToFile();
private:
    static Analyser* instance;
    TFile* rootFile;
    TTree* tree;
    G4double ParticleEnergy;
    G4double EdepCoin;
    G4double EdepVeto;
    G4double EdepTopDonut;
    G4double EdepTopCylinder;
    G4double EdepBotDonut;
    G4double EdepBotCylinder;
};

#endif
