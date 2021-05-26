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
    static Analyser* GetInstance();
//    void SetParticleEnergy(G4double energy) { ParticleEnergy = energy;}
//    void SetEdepCoin(G4double edep) {EdepCoin = edep;}
//    void SetEdepVeto(G4double edep) {EdepVeto = edep;}
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