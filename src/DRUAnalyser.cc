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

    ParticleEnergy = 0;
    EdepCoin = 0;
    EdepVeto = 0;
}

Analyser* Analyser::GetInstance() {
    if (instance == nullptr) instance = new Analyser;
    return instance;
}

void Analyser::AppendRow(G4double particleEnergy, G4double CoinEnergy, G4double VetoEnergy) {
    ParticleEnergy = particleEnergy;
    EdepCoin = CoinEnergy;
    EdepVeto = VetoEnergy;
    tree->Fill();
}

void Analyser::SaveToFile() {
    rootFile->cd();
    rootFile->Write();
    rootFile->Close();
}
