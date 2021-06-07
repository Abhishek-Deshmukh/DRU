void analyser() {
  TFile* f = new TFile("output_100000000.root");
  f->ls();

  // Getting input tree ready
  TTree* EDTree;
  f->GetObject("EDTree", EDTree);
  Double_t
    ParticleEnergy,
    CoinEnergyDep,
    VetoEnergyDep,
    TopDonutEnergyDep,
    TopCylinderEnergyDep,
    BotDonutEnergyDep,
    BotCylinderEnergyDep;
  EDTree->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  EDTree->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  EDTree->SetBranchAddress("VetoEnergyDep", &VetoEnergyDep);
  EDTree->SetBranchAddress("TopDonutEnergyDep", &TopDonutEnergyDep);
  EDTree->SetBranchAddress("TopCylinderEnergyDep", &TopCylinderEnergyDep);
  EDTree->SetBranchAddress("BotDonutEnergyDep", &BotDonutEnergyDep);
  EDTree->SetBranchAddress("BotCylinderEnergyDep", &BotCylinderEnergyDep);

  // Getting Single Scatter Tree ready
  TTree* SingleScatterCutTree = new TTree("SingleScatterCutTree", "Tree contains only the events which were single scatter");
  Double_t S_ParticleEnergy, S_CoinEnergyDep;
  SingleScatterCutTree->Branch("CoinEnergyDep", &S_CoinEnergyDep, "CoinEnergyDep/D");
  SingleScatterCutTree->Branch("ParticleEnergy", &S_ParticleEnergy, "ParticleEnergy/D");

  // DEBUG
  /* for (Int_t i=0; i<100; ++i) { */
  /*   EDTree->GetEntry(i); */
  /*   cout << ParticleEnergy << "\t" */
  /*     << CoinEnergyDep << "\t" */
  /*     << VetoEnergyDep << "\t" */
  /*     << TopDonutEnergyDep << "\t" */
  /*     << TopCylinderEnergyDep << "\t" */
  /*     << BotDonutEnergyDep << "\t" */
  /*     << BotCylinderEnergyDep << endl; */
  /* } */

  /* cout << EDTree->GetEntries() << endl; */

  Int_t total_event_count = EDTree->GetEntries();

  for (Int_t i=0; i< total_event_count; ++i) {
    EDTree->GetEntry(i);
    if (VetoEnergyDep + TopDonutEnergyDep + TopCylinderEnergyDep + BotDonutEnergyDep + BotCylinderEnergyDep == 0 && CoinEnergyDep != 0) {
      S_ParticleEnergy = ParticleEnergy;
      S_CoinEnergyDep = CoinEnergyDep;
      SingleScatterCutTree->Fill();
    }
  }
  SingleScatterCutTree->Print();
  SingleScatterCutTree->Scan("*");

  TFile* output = new TFile("ssc_output_100000000.root", "recreate");
  SingleScatterCutTree->Write();
  output->cd();
  output->Write();
  output->Close();
}
