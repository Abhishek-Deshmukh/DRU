#include "DRUAnalyser.hh"
#include <string>

Analyser* Analyser::instance=nullptr;

Analyser::Analyser(){
    // TODO: get this file name dynamically
    rootFile = new TFile("output.root", "recreate");
    tree = new TTree("EDTree", "EventData");

    tree->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
    tree->Branch("CoinEnergyDep", &EdepCoin, "CoinEnergyDep/D");
    tree->Branch("VetoEnergyDep", &EdepVeto, "VetoEnergyDep/D");
    tree->Branch("TopDonutEnergyDep", &EdepTopDonut, "TopDonutEnergyDep/D");
    tree->Branch("TopCylinderEnergyDep", &EdepTopCylinder, "TopCylinderEnergyDep/D");
    tree->Branch("BotDonutEnergyDep", &EdepBotDonut, "BotDonutEnergyDep/D");
    tree->Branch("BotCylinderEnergyDep", &EdepBotCylinder, "BotCylinderEnergyDep/D");

    ParticleEnergy = 0;
    EdepCoin = 0;
    EdepVeto = 0;
    EdepTopDonut = 0;
    EdepTopCylinder = 0;
    EdepBotDonut = 0;
    EdepBotCylinder = 0;
}

Analyser* Analyser::GetInstance() {
    if (instance == nullptr) instance = new Analyser;
    return instance;
}

void Analyser::SaveToFile() {
    rootFile->cd();
    rootFile->Write();
    rootFile->Close();
}

void Analyser::AppendRow(G4double particleEnergy, G4double CoinEnergy, G4double VetoEnergy, G4double TopDonutEnergy,
                         G4double TopCylinderEnergy, G4double BotDonutEnergy, G4double BotCylinderEnergy) {

    ParticleEnergy = particleEnergy;
    EdepCoin = CoinEnergy;
    EdepVeto = VetoEnergy;
    EdepTopDonut = TopDonutEnergy;
    EdepTopCylinder = TopCylinderEnergy;
    EdepBotDonut = BotDonutEnergy;
    EdepBotCylinder = BotCylinderEnergy;
    tree->Fill();
}
