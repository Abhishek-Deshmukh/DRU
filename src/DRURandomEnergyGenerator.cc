#include "DRURandomEnergyGenerator.hh"
#include <iostream>
#include <random>
#include "globals.hh"

DRURandomEnergyGenerator::DRURandomEnergyGenerator() {
	// in keVs
	// DEBUG
	G4cout << "Fixing value" << G4endl;
	min_energy = 0;
	max_energy = 2500;
	intervals_count = 250;
	energies = {};
	this->generate_energies();
}

void DRURandomEnergyGenerator::generate_energies() {
	std::random_device rd;
	std::default_random_engine dre(rd());

    std::vector<int> weights;

    std::fstream hist_file;
    hist_file.open("./SNOLABBackgrounds/total-gamma.dat", std::ios::in);
    if(!hist_file.is_open()) {
        G4cout << "Error: couldn't open file (DRURandomEnergyGenerator.cc) [Most probably the file name is wrong]" << G4endl;
        // TODO: make this stop the damn thing
    }
    std::string line;
    G4double energy;
    int count;
    while(getline(hist_file, line)) {
        energy = stod(line.substr(0, line.find('\t'))) * 1000;
        count = stoi(line.substr(line.find('\t')+ 1));

        if (energy >= min_energy && energy <= max_energy) {
            weights.push_back(count);
        }
    }

    std::discrete_distribution<int> discrete_dist(weights.begin(), weights.end());
    // DEBUG
    G4cout << "random number Generator is ready" << G4endl;
    for(int n=0; n < 1000; ++n) {
		energy =
			min_energy + ((discrete_dist(dre) + 1) * (max_energy - min_energy) / intervals_count );
		energies.push_back(energy);
	}
}

G4double DRURandomEnergyGenerator::get_energy() {
	// if set of random energies is finished then generate another 1000
	if (energies.empty()) {
		this->generate_energies();
	}
	// pop out one and return
	energies.pop_back();
	return energies.back();
}
