void analyser() {
  // Getting Single Scatter Tree ready
  TFile* output = new TFile("ssc_output.root", "recreate");
  TTree* SingleScatterCutTree = new TTree("SingleScatterCutTree", "Tree contains only the events which were single scatter");
  Double_t S_ParticleEnergy, S_CoinEnergyDep;
  SingleScatterCutTree->Branch("CoinEnergyDep", &S_CoinEnergyDep, "CoinEnergyDep/D");
  SingleScatterCutTree->Branch("ParticleEnergy", &S_ParticleEnergy, "ParticleEnergy/D");

  // Declaring variables
  Double_t
    ParticleEnergy,
    CoinEnergyDep,
    VetoEnergyDep,
    TopDonutEnergyDep,
    TopCylinderEnergyDep,
    BotDonutEnergyDep,
    BotCylinderEnergyDep;
  TTree* EDTree;


  // opening file
  TFile* f = new TFile("output1.root");
  // Getting input tree ready
  f->GetObject("EDTree", EDTree);
  EDTree->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  EDTree->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  EDTree->SetBranchAddress("VetoEnergyDep", &VetoEnergyDep);
  EDTree->SetBranchAddress("TopDonutEnergyDep", &TopDonutEnergyDep);
  EDTree->SetBranchAddress("TopCylinderEnergyDep", &TopCylinderEnergyDep);
  EDTree->SetBranchAddress("BotDonutEnergyDep", &BotDonutEnergyDep);
  EDTree->SetBranchAddress("BotCylinderEnergyDep", &BotCylinderEnergyDep);
  // Loop to filter input and put into ssc
  for (Int_t i=0; i< EDTree->GetEntries(); ++i) {
    EDTree->GetEntry(i);
    if (VetoEnergyDep + TopDonutEnergyDep + TopCylinderEnergyDep + BotDonutEnergyDep + BotCylinderEnergyDep == 0 && CoinEnergyDep != 0) {
      S_ParticleEnergy = ParticleEnergy;
      S_CoinEnergyDep = CoinEnergyDep;
      SingleScatterCutTree->Fill();
    }
  }



  // opening file
  f = new TFile("output2.root");
  // Getting input tree ready
  f->GetObject("EDTree", EDTree);
  EDTree->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  EDTree->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  EDTree->SetBranchAddress("VetoEnergyDep", &VetoEnergyDep);
  EDTree->SetBranchAddress("TopDonutEnergyDep", &TopDonutEnergyDep);
  EDTree->SetBranchAddress("TopCylinderEnergyDep", &TopCylinderEnergyDep);
  EDTree->SetBranchAddress("BotDonutEnergyDep", &BotDonutEnergyDep);
  EDTree->SetBranchAddress("BotCylinderEnergyDep", &BotCylinderEnergyDep);
  // Loop to filter input and put into ssc
  for (Int_t i=0; i< EDTree->GetEntries(); ++i) {
    EDTree->GetEntry(i);
    if (VetoEnergyDep + TopDonutEnergyDep + TopCylinderEnergyDep + BotDonutEnergyDep + BotCylinderEnergyDep == 0 && CoinEnergyDep != 0) {
      S_ParticleEnergy = ParticleEnergy;
      S_CoinEnergyDep = CoinEnergyDep;
      SingleScatterCutTree->Fill();
    }
  }

  // opening file
  f = new TFile("output3.root");
  // Getting input tree ready
  f->GetObject("EDTree", EDTree);
  EDTree->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  EDTree->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  EDTree->SetBranchAddress("VetoEnergyDep", &VetoEnergyDep);
  EDTree->SetBranchAddress("TopDonutEnergyDep", &TopDonutEnergyDep);
  EDTree->SetBranchAddress("TopCylinderEnergyDep", &TopCylinderEnergyDep);
  EDTree->SetBranchAddress("BotDonutEnergyDep", &BotDonutEnergyDep);
  EDTree->SetBranchAddress("BotCylinderEnergyDep", &BotCylinderEnergyDep);
  // Loop to filter input and put into ssc
  for (Int_t i=0; i< EDTree->GetEntries(); ++i) {
    EDTree->GetEntry(i);
    if (VetoEnergyDep + TopDonutEnergyDep + TopCylinderEnergyDep + BotDonutEnergyDep + BotCylinderEnergyDep == 0 && CoinEnergyDep != 0) {
      S_ParticleEnergy = ParticleEnergy;
      S_CoinEnergyDep = CoinEnergyDep;
      SingleScatterCutTree->Fill();
    }
  }


  // opening file
  f = new TFile("output4.root");
  // Getting input tree ready
  f->GetObject("EDTree", EDTree);
  EDTree->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  EDTree->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  EDTree->SetBranchAddress("VetoEnergyDep", &VetoEnergyDep);
  EDTree->SetBranchAddress("TopDonutEnergyDep", &TopDonutEnergyDep);
  EDTree->SetBranchAddress("TopCylinderEnergyDep", &TopCylinderEnergyDep);
  EDTree->SetBranchAddress("BotDonutEnergyDep", &BotDonutEnergyDep);
  EDTree->SetBranchAddress("BotCylinderEnergyDep", &BotCylinderEnergyDep);
  // Loop to filter input and put into ssc
  for (Int_t i=0; i< EDTree->GetEntries(); ++i) {
    EDTree->GetEntry(i);
    if (VetoEnergyDep + TopDonutEnergyDep + TopCylinderEnergyDep + BotDonutEnergyDep + BotCylinderEnergyDep == 0 && CoinEnergyDep != 0) {
      S_ParticleEnergy = ParticleEnergy;
      S_CoinEnergyDep = CoinEnergyDep;
      SingleScatterCutTree->Fill();
    }
  }


  // opening file
  f = new TFile("output5.root");
  // Getting input tree ready
  f->GetObject("EDTree", EDTree);
  EDTree->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  EDTree->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  EDTree->SetBranchAddress("VetoEnergyDep", &VetoEnergyDep);
  EDTree->SetBranchAddress("TopDonutEnergyDep", &TopDonutEnergyDep);
  EDTree->SetBranchAddress("TopCylinderEnergyDep", &TopCylinderEnergyDep);
  EDTree->SetBranchAddress("BotDonutEnergyDep", &BotDonutEnergyDep);
  EDTree->SetBranchAddress("BotCylinderEnergyDep", &BotCylinderEnergyDep);
  // Loop to filter input and put into ssc
  for (Int_t i=0; i< EDTree->GetEntries(); ++i) {
    EDTree->GetEntry(i);
    if (VetoEnergyDep + TopDonutEnergyDep + TopCylinderEnergyDep + BotDonutEnergyDep + BotCylinderEnergyDep == 0 && CoinEnergyDep != 0) {
      S_ParticleEnergy = ParticleEnergy;
      S_CoinEnergyDep = CoinEnergyDep;
      SingleScatterCutTree->Fill();
    }
  }


  // opening file
  f = new TFile("output6.root");
  // Getting input tree ready
  f->GetObject("EDTree", EDTree);
  EDTree->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  EDTree->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  EDTree->SetBranchAddress("VetoEnergyDep", &VetoEnergyDep);
  EDTree->SetBranchAddress("TopDonutEnergyDep", &TopDonutEnergyDep);
  EDTree->SetBranchAddress("TopCylinderEnergyDep", &TopCylinderEnergyDep);
  EDTree->SetBranchAddress("BotDonutEnergyDep", &BotDonutEnergyDep);
  EDTree->SetBranchAddress("BotCylinderEnergyDep", &BotCylinderEnergyDep);
  // Loop to filter input and put into ssc
  for (Int_t i=0; i< EDTree->GetEntries(); ++i) {
    EDTree->GetEntry(i);
    if (VetoEnergyDep + TopDonutEnergyDep + TopCylinderEnergyDep + BotDonutEnergyDep + BotCylinderEnergyDep == 0 && CoinEnergyDep != 0) {
      S_ParticleEnergy = ParticleEnergy;
      S_CoinEnergyDep = CoinEnergyDep;
      SingleScatterCutTree->Fill();
    }
  }

  // opening file
  f = new TFile("output7.root");
  // Getting input tree ready
  f->GetObject("EDTree", EDTree);
  EDTree->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  EDTree->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  EDTree->SetBranchAddress("VetoEnergyDep", &VetoEnergyDep);
  EDTree->SetBranchAddress("TopDonutEnergyDep", &TopDonutEnergyDep);
  EDTree->SetBranchAddress("TopCylinderEnergyDep", &TopCylinderEnergyDep);
  EDTree->SetBranchAddress("BotDonutEnergyDep", &BotDonutEnergyDep);
  EDTree->SetBranchAddress("BotCylinderEnergyDep", &BotCylinderEnergyDep);
  // Loop to filter input and put into ssc
  for (Int_t i=0; i< EDTree->GetEntries(); ++i) {
    EDTree->GetEntry(i);
    if (VetoEnergyDep + TopDonutEnergyDep + TopCylinderEnergyDep + BotDonutEnergyDep + BotCylinderEnergyDep == 0 && CoinEnergyDep != 0) {
      S_ParticleEnergy = ParticleEnergy;
      S_CoinEnergyDep = CoinEnergyDep;
      SingleScatterCutTree->Fill();
    }
  }

  // opening file
  f = new TFile("output8.root");
  // Getting input tree ready
  f->GetObject("EDTree", EDTree);
  EDTree->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  EDTree->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  EDTree->SetBranchAddress("VetoEnergyDep", &VetoEnergyDep);
  EDTree->SetBranchAddress("TopDonutEnergyDep", &TopDonutEnergyDep);
  EDTree->SetBranchAddress("TopCylinderEnergyDep", &TopCylinderEnergyDep);
  EDTree->SetBranchAddress("BotDonutEnergyDep", &BotDonutEnergyDep);
  EDTree->SetBranchAddress("BotCylinderEnergyDep", &BotCylinderEnergyDep);
  // Loop to filter input and put into ssc
  for (Int_t i=0; i< EDTree->GetEntries(); ++i) {
    EDTree->GetEntry(i);
    if (VetoEnergyDep + TopDonutEnergyDep + TopCylinderEnergyDep + BotDonutEnergyDep + BotCylinderEnergyDep == 0 && CoinEnergyDep != 0) {
      S_ParticleEnergy = ParticleEnergy;
      S_CoinEnergyDep = CoinEnergyDep;
      SingleScatterCutTree->Fill();
    }
  }

  // opening file
  f = new TFile("output9.root");
  // Getting input tree ready
  f->GetObject("EDTree", EDTree);
  EDTree->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  EDTree->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  EDTree->SetBranchAddress("VetoEnergyDep", &VetoEnergyDep);
  EDTree->SetBranchAddress("TopDonutEnergyDep", &TopDonutEnergyDep);
  EDTree->SetBranchAddress("TopCylinderEnergyDep", &TopCylinderEnergyDep);
  EDTree->SetBranchAddress("BotDonutEnergyDep", &BotDonutEnergyDep);
  EDTree->SetBranchAddress("BotCylinderEnergyDep", &BotCylinderEnergyDep);
  // Loop to filter input and put into ssc
  for (Int_t i=0; i< EDTree->GetEntries(); ++i) {
    EDTree->GetEntry(i);
    if (VetoEnergyDep + TopDonutEnergyDep + TopCylinderEnergyDep + BotDonutEnergyDep + BotCylinderEnergyDep == 0 && CoinEnergyDep != 0) {
      S_ParticleEnergy = ParticleEnergy;
      S_CoinEnergyDep = CoinEnergyDep;
      SingleScatterCutTree->Fill();
    }
  }

  // opening file
  f = new TFile("output10.root");
  // Getting input tree ready
  f->GetObject("EDTree", EDTree);
  EDTree->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  EDTree->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  EDTree->SetBranchAddress("VetoEnergyDep", &VetoEnergyDep);
  EDTree->SetBranchAddress("TopDonutEnergyDep", &TopDonutEnergyDep);
  EDTree->SetBranchAddress("TopCylinderEnergyDep", &TopCylinderEnergyDep);
  EDTree->SetBranchAddress("BotDonutEnergyDep", &BotDonutEnergyDep);
  EDTree->SetBranchAddress("BotCylinderEnergyDep", &BotCylinderEnergyDep);
  // Loop to filter input and put into ssc
  for (Int_t i=0; i< EDTree->GetEntries(); ++i) {
    EDTree->GetEntry(i);
    if (VetoEnergyDep + TopDonutEnergyDep + TopCylinderEnergyDep + BotDonutEnergyDep + BotCylinderEnergyDep == 0 && CoinEnergyDep != 0) {
      S_ParticleEnergy = ParticleEnergy;
      S_CoinEnergyDep = CoinEnergyDep;
      SingleScatterCutTree->Fill();
    }
  }

  // Saving into file
  output->cd();
  SingleScatterCutTree->Write();
  output->Write();
  output->Close();
}
