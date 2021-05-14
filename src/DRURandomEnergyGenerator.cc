#include "DRURandomEnergyGenerator.hh"
#include <fstream>
#include <iostream>
#include <random>
#include <map>
#include "globals.hh"

DRURandomEnergyGenerator::DRURandomEnergyGenerator() {
	// in keVs
	min_energy = 0;
	max_energy = 400;
	intervals_count = 40;
}

void DRURandomEnergyGenerator::generate_energies() {
	// generated new 10**3 energies
	std::random_device rd;
	std::default_random_engine dre(rd());

	// TODO: read the file and get weights for given energy range

    std::discrete_distribution<int> discrete_dist({10, 20, 30, 40});
	G4double energy = 0;
	for(int n=0; n < 1000; ++n) {
		energy =
			min_energy + ((discrete_dist(dre) + 1) * (max_energy - min_energy) / intervals_count );
		energies->push_back(energy);
	}
}

G4double DRURandomEnergyGenerator::get_energy() {
	// if set of random energies is finished then generate another 1000
	if (energies->size() == 0) {
		this->generate_energies();
	}
	// pop out one and return
	energies->pop_back();
	return energies->back();
}
