
#ifndef DRURandomEnergyGenerator_h
#define DRURandomEnergyGenerator_h

#include <iostream>
#include <cmath>
#include "G4SystemOfUnits.hh"
#include "globals.hh"
#include <fstream>
#include <vector>

class DRURandomEnergyGenerator {
public:
	DRURandomEnergyGenerator();
	void generate_energies();
	G4double get_energy();
private:
	G4double min_energy;
	G4double max_energy;
	G4int intervals_count;
	std::vector < G4double > energies;
};

#endif
