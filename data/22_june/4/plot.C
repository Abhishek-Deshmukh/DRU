void plot() {
  // getting data
  TFile* f = new TFile("ssc_output.root");
  TTree* SingleScatterCutTree;
  f->GetObject("SingleScatterCutTree", SingleScatterCutTree);

  // plotting all single scatter cut
  TH1F *h1 = new TH1F("h1", "Single Scatter cut", 260, 0, 2600);
  h1->SetTitle("Single-scatter cut");
  h1->GetXaxis()->SetTitle("Energy [KeV]");
  h1->GetYaxis()->SetTitle("Counts/KeV");
  TCanvas* c = new TCanvas("c1", "Single scatter cut", 1024, 768);
  c->cd();
  SingleScatterCutTree->Draw("CoinEnergyDep*1000>>h1");
  c->SetLogy();
  c->SaveAs("sscplt.png");

  // plotting input
  TH1F *h2 = new TH1F("h2", "Input gamma", 260, 0,2600);
  h2->SetTitle("Input gamma energy");
  h2->GetXaxis()->SetTitle("Energy [KeV]");
  h2->GetYaxis()->SetTitle("Counts/KeV");
  TCanvas* c2 = new TCanvas("c2", "Input gamma", 1024, 768);
  c2->cd();
  SingleScatterCutTree->Draw("ParticleEnergy*1000>>h2");
  c2->SetLogy();
  c2->SaveAs("input_gamma.png");

  // Making energy cuts
  TTree* SSCT_0_400kev = new TTree("SSCT_0_400KeV", ">0 and <400");
  TTree* SSCT_50_300kev = new TTree("SSCT_50_300KeV", ">50 and <300");
  Double_t ParticleEnergy, CoinEnergy;
  SSCT_0_400kev->Branch("CoinEnergyDep", &CoinEnergy, "CoinEnergyDep/D");
  SSCT_0_400kev->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
  SSCT_50_300kev->Branch("CoinEnergyDep", &CoinEnergy, "CoinEnergyDep/D");
  SSCT_50_300kev->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
  SingleScatterCutTree->SetBranchAddress("CoinEnergyDep", &CoinEnergy);
  SingleScatterCutTree->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  for (Int_t i=0; i<SingleScatterCutTree->GetEntries(); ++i) {
    SingleScatterCutTree->GetEntry(i);
    if (CoinEnergy*1000 >= 0 && CoinEnergy*1000 <= 400) {
      SSCT_0_400kev->Fill();
      if (CoinEnergy*1000 >= 50 && CoinEnergy*1000 <= 300) {
      SSCT_50_300kev->Fill();
      }
    }
  }
  SSCT_0_400kev->Print();

  // Plotting energy cuts
  TH1F *h3 = new TH1F("h3", "Single Scatter cut (0-400KeV)", 400, 0, 400);
  h3->SetTitle("Single-scatter cut (0-400KeV)");
  h3->GetXaxis()->SetTitle("Energy [KeV]");
  h3->GetYaxis()->SetTitle("Counts/KeV");
  TCanvas* c3 = new TCanvas("c3", "Single Scatter cut (0-400KeV)", 1024, 768);
  c3->cd();
  SSCT_0_400kev->Draw("CoinEnergyDep*1000>>h3");
  c3->SetLogy();
  c3->SaveAs("ssc_0_400.png");

  TH1F *h4 = new TH1F("h4", "Single Scatter cut (50-300KeV)", 250, 50, 300);
  h4->SetTitle("Single-scatter cut (50-300KeV)");
  h4->GetXaxis()->SetTitle("Energy [KeV]");
  h4->GetYaxis()->SetTitle("Counts/KeV");
  TCanvas* c4 = new TCanvas("c4", "Single Scatter cut (50-300KeV)", 1024, 768);
  c4->cd();
  SSCT_50_300kev->Draw("CoinEnergyDep*1000>>h4");
  c4->SetLogy();
  c4->SaveAs("ssc_50_300.png");

  // calculating DRU
  Double_t mass_g = 11.194698, ideal_DRU = 235, DRU = 0, days = 16.0346;
  SSCT_50_300kev->SetBranchAddress("CoinEnergyDep", &CoinEnergy);
  for (Int_t i=0; i< SSCT_50_300kev->GetEntries(); ++i) {
    SSCT_50_300kev->GetEntry(i);
    DRU += CoinEnergy;
  }
  DRU/=250; // per KeV
  DRU/=(mass_g/1000); //per kg
  DRU/=days; // per day

  cout << "DRU " << DRU << " /keV/Day/kg"; // 20.0482
}
