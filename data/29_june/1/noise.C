void noise() {
  TFile* output = new TFile("ssc_output.root");
  TTree* SingleScatterCutTree;
  output->GetObject("SingleScatterCutTree", SingleScatterCutTree);
  Double_t
    ParticleEnergy,
    CoinEnergyDep,
    CoinEnergyDepWithNoise;
  SingleScatterCutTree->SetBranchAddress("ParticleEnergy",&ParticleEnergy);
  SingleScatterCutTree->SetBranchAddress("CoinEnergyDep",&CoinEnergyDep);

  TFile* output_W_noise = new TFile("ssc_output_w_noise.root", "recreate");
  TTree* SingleScatterCutTreeWithNoise = new TTree("SingleScatterCutTreeWithNoise", "Tree contains only single scatter cut events with noise");
  SingleScatterCutTreeWithNoise->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
  SingleScatterCutTreeWithNoise->Branch("CoinEnergyDepWithNoise", &CoinEnergyDepWithNoise, "CoinEnergyDepWithNoise/D");

  auto* randgen = new TRandom();
  for (Int_t i=0; i<SingleScatterCutTree->GetEntries(); i++) {
    SingleScatterCutTree->GetEntry(i);
    CoinEnergyDepWithNoise = randgen->Gaus(CoinEnergyDep, 0.112);
    /* cout << CoinEnergyDep << " " << CoinEnergyDepWithNoise << endl; */
    SingleScatterCutTreeWithNoise->Fill();
  }

  // Making energy cuts
  TTree* SSCT_0_400kev = new TTree("SSCT_0_400KeV", ">0 and <400");
  TTree* SSCT_100_300kev = new TTree("SSCT_100_300KeV", ">100 and <300");
  Double_t CoinEnergy;
  SSCT_0_400kev->Branch("CoinEnergyDep", &CoinEnergy, "CoinEnergyDep/D");
  SSCT_0_400kev->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
  SSCT_100_300kev->Branch("CoinEnergyDep", &CoinEnergy, "CoinEnergyDep/D");
  SSCT_100_300kev->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
  SingleScatterCutTreeWithNoise->SetBranchAddress("CoinEnergyDepWithNoise", &CoinEnergy);
  SingleScatterCutTreeWithNoise->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  for (Int_t i=0; i<SingleScatterCutTreeWithNoise->GetEntries(); ++i) {
    SingleScatterCutTreeWithNoise->GetEntry(i);
    if (CoinEnergy >= 0 && CoinEnergy <= 400) {
      SSCT_0_400kev->Fill();
      if (CoinEnergy >= 100 && CoinEnergy <= 300) {
      SSCT_100_300kev->Fill();
      }
    }
  }
  SSCT_0_400kev->Print();

  // Plotting energy cuts
  TH1F *h3 = new TH1F("h3", "Single Scatter cut (0-400KeV) with noise", 40, 0, 400);
  h3->SetTitle("Single-scatter cut (0-400KeV) with noise");
  h3->GetXaxis()->SetTitle("Energy [KeV]");
  h3->GetYaxis()->SetTitle("Counts/10KeV");
  TCanvas* c3 = new TCanvas("c3", "Single Scatter cut (0-400KeV) with noise", 1024, 768);
  c3->cd();
  SSCT_0_400kev->Draw("CoinEnergyDep>>h3");
  c3->SetLogy();
  c3->SaveAs("ssc_0_400_with_noise.png");

  TH1F *h4 = new TH1F("h4", "Single Scatter cut (100-300KeV) with noise", 20, 100, 300);
  h4->SetTitle("Single-scatter cut (100-300KeV) with noise");
  h4->GetXaxis()->SetTitle("Energy [KeV]");
  h4->GetYaxis()->SetTitle("Counts/10KeV");
  TCanvas* c4 = new TCanvas("c4", "Single Scatter cut (100-300KeV) with noise", 1024, 768);
  c4->cd();
  SSCT_100_300kev->Draw("CoinEnergyDep>>h4");
  c4->SetLogy();
  c4->SaveAs("ssc_100_300_with_noise.png");
}
