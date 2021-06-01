#include "DRUAnalyser.hh"
#include <string>

Analyser* Analyser::instance=nullptr;

void Analyser::SetFileName(G4String file_name) {
    ROOT::EnableThreadSafety();
    rootFile = new TFile(file_name, "recreate");
    ROOT::EnableThreadSafety();
    tree = new TTree("EDTree", "EventData");
    tree->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
    tree->Branch("CoinEnergyDep", &EdepCoin, "CoinEnergyDep/D");
    tree->Branch("VetoEnergyDep", &EdepVeto, "VetoEnergyDep/D");
    tree->Branch("TopDonutEnergyDep", &EdepTopDonut, "TopDonutEnergyDep/D");
    tree->Branch("TopCylinderEnergyDep", &EdepTopCylinder, "TopCylinderEnergyDep/D");
    tree->Branch("BotDonutEnergyDep", &EdepBotDonut, "BotDonutEnergyDep/D");
    tree->Branch("BotCylinderEnergyDep", &EdepBotCylinder, "BotCylinderEnergyDep/D");
}

Analyser::Analyser(){

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
    ROOT::EnableThreadSafety();
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
    ROOT::EnableThreadSafety();
    tree->Fill();
}
