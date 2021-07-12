void plot() {
  // getting data
  TFile* f = new TFile("ssc_output.root");
  TTree* SingleScatterCutTree;
  TTree* TotalTree;
  f->GetObject("SingleScatterCutTree", SingleScatterCutTree);
  f->GetObject("TotalTree", TotalTree);

  // plotting all single scatter cut
  TH1F *h1 = new TH1F("h1", "Single Scatter cut", 260, 0, 2600);
  h1->SetTitle("Single-scatter cut");
  h1->GetXaxis()->SetTitle("Energy [keV]");
  h1->GetYaxis()->SetTitle("Counts/10keV");
  TCanvas* c = new TCanvas("c1", "Single scatter cut", 1024, 768);
  c->cd();
  SingleScatterCutTree->Draw("CoinEnergyDep>>h1");
  c->SetLogy();
  c->SaveAs("sscplt.png");

  // plotting input
  TH1F *h2 = new TH1F("h2", "Input gamma", 260, 0,2600);
  h2->SetTitle("Input gamma energy");
  h2->GetXaxis()->SetTitle("Energy [keV]");
  h2->GetYaxis()->SetTitle("Counts/10keV");
  TCanvas* c2 = new TCanvas("c2", "Input gamma", 1024, 768);
  c2->cd();
  SingleScatterCutTree->Draw("ParticleEnergy>>h2");
  c2->SetLogy();
  c2->SaveAs("input_gamma.png");

  // Making energy cuts
  TTree* SSCT_0_400kev = new TTree("SSCT_0_400keV", ">0 and <400");
  TTree* SSCT_100_300kev = new TTree("SSCT_100_300keV", ">100 and <300");
  Double_t ParticleEnergy, CoinEnergy;
  SSCT_0_400kev->Branch("CoinEnergyDep", &CoinEnergy, "CoinEnergyDep/D");
  SSCT_0_400kev->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
  SSCT_100_300kev->Branch("CoinEnergyDep", &CoinEnergy, "CoinEnergyDep/D");
  SSCT_100_300kev->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
  SingleScatterCutTree->SetBranchAddress("CoinEnergyDep", &CoinEnergy);
  SingleScatterCutTree->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  for (Int_t i=0; i<SingleScatterCutTree->GetEntries(); ++i) {
    SingleScatterCutTree->GetEntry(i);
    if (CoinEnergy >= 0 && CoinEnergy <= 400) {
      SSCT_0_400kev->Fill();
      if (CoinEnergy >= 50 && CoinEnergy <= 300) {
      SSCT_100_300kev->Fill();
      }
    }
  }
  SSCT_0_400kev->Print();

  // Plotting energy cuts
  TH1F *h3 = new TH1F("h3", "Single Scatter cut (0-400keV)", 40, 0, 400);
  h3->SetTitle("Single-scatter cut (0-400keV)");
  h3->GetXaxis()->SetTitle("Energy [keV]");
  h3->GetYaxis()->SetTitle("Counts/10keV");
  TCanvas* c3 = new TCanvas("c3", "Single Scatter cut (0-400keV)", 1024, 768);
  c3->cd();
  SSCT_0_400kev->Draw("CoinEnergyDep>>h3");
  c3->SetLogy();
  c3->SaveAs("ssc_0_400.png");

  TH1F *h4 = new TH1F("h4", "Single Scatter cut (100-300keV)", 20, 100, 300);
  h4->SetTitle("Single-scatter cut (100-300keV)");
  h4->GetXaxis()->SetTitle("Energy [keV]");
  h4->GetYaxis()->SetTitle("Counts/10keV");
  TCanvas* c4 = new TCanvas("c4", "Single Scatter cut (100-300keV)", 1024, 768);
  c4->cd();
  SSCT_100_300kev->Draw("CoinEnergyDep>>h4");
  c4->SetLogy();
  c4->SaveAs("ssc_100_300.png");

  // plotting all single scatter cut
  TH1F *h5 = new TH1F("h5", "No Cut (All Events)", 260, 0, 2600);
  h5->SetTitle("No Cut (All Events)");
  h5->GetXaxis()->SetTitle("Energy [keV]");
  h5->GetYaxis()->SetTitle("Counts/10keV");
  TCanvas* c5 = new TCanvas("c5", "No Cut (All Events)", 1024, 768);
  c5->cd();
  TotalTree->Draw("CoinEnergyDep>>h5");
  c5->SetLogy();
  c5->SaveAs("no_cut.png");

  // calculating DRU
  Double_t mass_g = 11.194698, ideal_DRU = 302.989, DRU = 0, days = 280.192;
  SSCT_100_300kev->SetBranchAddress("CoinEnergyDep", &CoinEnergy);
  DRU = SSCT_100_300kev->GetEntries();
  DRU/=200; // per keV
  DRU/=(mass_g/1000); //per kg
  DRU/=days; // per day

  cout << "DRU " << DRU << " /keV/Day/kg"; // 31.1318 counts/keV/Day/kg
}
