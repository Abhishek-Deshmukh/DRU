void combined_plot() {
  gStyle->SetOptStat(0);
  gStyle->SetOptTitle(0);
  gStyle->SetLegendBorderSize(0);
  Double_t
    ParticleEnergy,
    CoinEnergyDep,
    CoinEnergy,
    CoinEnergyDepNoise;
  auto* randgen = new TRandom();

  /* lmao */
  /* output1 */
  /* lmao */
  TFile* output1 = new TFile("./1/ssc_output.root");
  /* setting up the input tree */
  TTree* SSCT1;
  output1->GetObject("SingleScatterCutTree", SSCT1);
  SSCT1->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  SSCT1->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  /* defining the noise tree */
  TTree* SSCT1N = new TTree("SSCT1N", "Single scatter cut with noise");
  SSCT1N->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
  SSCT1N->Branch("CoinEnergyDep", &CoinEnergyDepNoise, "CoinEnergyDep/D");
  /* adding noise */
  for (int i=0; i<SSCT1->GetEntries(); i++) {
    SSCT1->GetEntry(i);
    CoinEnergyDepNoise = randgen->Gaus(CoinEnergyDep, 0.112);
    SSCT1N->Fill();
  }
  /* setting range to 100 to 300 */
  SSCT1N->SetBranchAddress("CoinEnergyDep", &CoinEnergy);
  SSCT1N->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  TH1F* histo1 = new TH1F ("histo1", "histo1", 20, 100, 300);
  for (int i=0; i<SSCT1N->GetEntries(); i++) {
    SSCT1N->GetEntry(i);
    if (CoinEnergy >= 100 && CoinEnergy <= 300) {
      histo1->Fill(CoinEnergy);
    }
  }


  /* lmao */
  /* output2 */
  /* lmao */
  TFile* output2 = new TFile("./2/ssc_output.root");
  /* setting up the input tree */
  TTree* SSCT2;
  output2->GetObject("SingleScatterCutTree", SSCT2);
  SSCT2->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  SSCT2->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  /* defining the noise tree */
  TTree* SSCT2N = new TTree("SSCT2N", "Single scatter cut with noise");
  SSCT2N->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
  SSCT2N->Branch("CoinEnergyDep", &CoinEnergyDepNoise, "CoinEnergyDep/D");
  /* adding noise */
  for (int i=0; i<SSCT2->GetEntries(); i++) {
    SSCT2->GetEntry(i);
    CoinEnergyDepNoise = randgen->Gaus(CoinEnergyDep, 0.112);
    SSCT2N->Fill();
  }
  /* setting range to 100 to 300 */
  SSCT2N->SetBranchAddress("CoinEnergyDep", &CoinEnergy);
  SSCT2N->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  TH1F* histo2 = new TH1F ("histo2", "histo2", 20, 100, 300);
  for (int i=0; i<SSCT2N->GetEntries(); i++) {
    SSCT2N->GetEntry(i);
    if (CoinEnergy >= 100 && CoinEnergy <= 300) {
      histo2->Fill(CoinEnergy);
    }
  }


  /* lmao */
  /* output3 */
  /* lmao */
  TFile* output3 = new TFile("./3/ssc_output.root");
  /* setting up the input tree */
  TTree* SSCT3;
  output3->GetObject("SingleScatterCutTree", SSCT3);
  SSCT3->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  SSCT3->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  /* defining the noise tree */
  TTree* SSCT3N = new TTree("SSCT3N", "Single scatter cut with noise");
  SSCT3N->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
  SSCT3N->Branch("CoinEnergyDep", &CoinEnergyDepNoise, "CoinEnergyDep/D");
  /* adding noise */
  for (int i=0; i<SSCT3->GetEntries(); i++) {
    SSCT3->GetEntry(i);
    CoinEnergyDepNoise = randgen->Gaus(CoinEnergyDep, 0.112);
    SSCT3N->Fill();
  }
  /* setting range to 100 to 300 */
  SSCT3N->SetBranchAddress("CoinEnergyDep", &CoinEnergy);
  SSCT3N->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  TH1F* histo3 = new TH1F ("histo3", "histo3", 20, 100, 300);
  for (int i=0; i<SSCT3N->GetEntries(); i++) {
    SSCT3N->GetEntry(i);
    if (CoinEnergy >= 100 && CoinEnergy <= 300) {
      histo3->Fill(CoinEnergy);
    }
  }


  /* lmao */
  /* output4 */
  /* lmao */
  TFile* output4 = new TFile("./4/ssc_output.root");
  /* setting up the input tree */
  TTree* SSCT4;
  output4->GetObject("SingleScatterCutTree", SSCT4);
  SSCT4->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  SSCT4->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  /* defining the noise tree */
  TTree* SSCT4N = new TTree("SSCT4N", "Single scatter cut with noise");
  SSCT4N->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
  SSCT4N->Branch("CoinEnergyDep", &CoinEnergyDepNoise, "CoinEnergyDep/D");
  /* adding noise */
  for (int i=0; i<SSCT4->GetEntries(); i++) {
    SSCT4->GetEntry(i);
    CoinEnergyDepNoise = randgen->Gaus(CoinEnergyDep, 0.112);
    SSCT4N->Fill();
  }
  /* setting range to 100 to 300 */
  SSCT4N->SetBranchAddress("CoinEnergyDep", &CoinEnergy);
  SSCT4N->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  TH1F* histo4 = new TH1F ("histo4", "histo4", 20, 100, 300);
  for (int i=0; i<SSCT4N->GetEntries(); i++) {
    SSCT4N->GetEntry(i);
    if (CoinEnergy >= 100 && CoinEnergy <= 300) {
      histo4->Fill(CoinEnergy);
    }
  }


  /* lmao */
  /* output5 */
  /* lmao */
  TFile* output5 = new TFile("./5/ssc_output.root");
  /* setting up the input tree */
  TTree* SSCT5;
  output5->GetObject("SingleScatterCutTree", SSCT5);
  SSCT5->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  SSCT5->SetBranchAddress("CoinEnergyDep", &CoinEnergyDep);
  /* defining the noise tree */
  TTree* SSCT5N = new TTree("SSCT5N", "Single scatter cut with noise");
  SSCT5N->Branch("ParticleEnergy", &ParticleEnergy, "ParticleEnergy/D");
  SSCT5N->Branch("CoinEnergyDep", &CoinEnergyDepNoise, "CoinEnergyDep/D");
  /* adding noise */
  for (int i=0; i<SSCT5->GetEntries(); i++) {
    SSCT5->GetEntry(i);
    CoinEnergyDepNoise = randgen->Gaus(CoinEnergyDep, 0.112);
    SSCT5N->Fill();
  }
  /* setting range to 100 to 300 */
  SSCT5N->SetBranchAddress("CoinEnergyDep", &CoinEnergy);
  SSCT5N->SetBranchAddress("ParticleEnergy", &ParticleEnergy);
  TH1F* histo5 = new TH1F ("histo5", "histo5", 20, 100, 300);
  for (int i=0; i<SSCT5N->GetEntries(); i++) {
    SSCT5N->GetEntry(i);
    if (CoinEnergy >= 100 && CoinEnergy <= 300) {
      histo5->Fill(CoinEnergy);
    }
  }

  /* lmao */
  /* making plot */
  /* lmao */
  histo1->SetLineColor(kBlack);

  TH1F *histo2d = (TH1F*)histo1->Clone("histo12");
  histo2d->Divide(histo2);
  histo2->SetLineColor(kRed);
  histo2d->SetLineColor(kRed);

  TH1F *histo3d = (TH1F*)histo1->Clone("histo13");
  histo3d->Divide(histo3);
  histo3->SetLineColor(kBlue);
  histo3d->SetLineColor(kBlue);

  TH1F *histo4d = (TH1F*)histo1->Clone("histo14");
  histo4d->Divide(histo4);
  histo4->SetLineColor(kGreen);
  histo4d->SetLineColor(kGreen);

  TH1F *histo5d = (TH1F*)histo1->Clone("histo15");
  histo5d->Divide(histo5);
  histo5->SetLineColor(kMagenta);
  histo5d->SetLineColor(kMagenta);

  histo1->SetAxisRange(400, 20000, "Y");
  histo1->GetYaxis()->SetTitle("Counts/10keV");
  histo1->GetYaxis()->SetTitleSize(0.055);
  histo1->GetYaxis()->SetLabelSize(0.05);

  histo2d->SetAxisRange(6, 13, "Y");
  histo2d->GetXaxis()->SetTitle("Energy [keV]");
  histo2d->GetXaxis()->SetTitleSize(0.12);
  histo2d->GetXaxis()->SetLabelSize(0.10);
  histo2d->GetYaxis()->SetLabelSize(0.10);
  histo2d->GetYaxis()->SetNdivisions(4);

  auto legend = new TLegend(0.46, 0.35, 0.7, 0.7);
  legend->AddEntry(histo1,"0cm");
  legend->AddEntry(histo2,"2cm");
  legend->AddEntry(histo3,"4cm");
  legend->AddEntry(histo4,"6cm");
  legend->AddEntry(histo5,"8cm");

  TCanvas* c = new TCanvas("c", "Single Scatter cut (100-300keV) with noise", 1024, 768);
  c->cd();
  c->Divide(2, 1, 1e-3, 1e-3);
  c->SetLogy();
  TPad *pu;
  /* = new TPad("pu","pu",  0.1,  0.3,  0.9,  0.9, -1, 1, -1); */
  TPad *pd;
  /* = new TPad("pd","pd",  0.1,  0.1,   0.9,  0.29, -1, 1, -1); */

  pu = (TPad*)c->cd(1);
  pd = (TPad*)c->cd(2);

  pu->SetPad(0.1,  0.4,  1,  1);
  pu->SetBottomMargin(0);
  pu->SetLogy();
  pd->SetPad(0.1,  0.1,  1,  0.4);
  pd->SetTopMargin(0);
  pd->SetBottomMargin(0.3);

  pu->cd();
  histo1->Draw("hist");
  histo2->Draw("hist same");
  histo3->Draw("hist same");
  histo4->Draw("hist same");
  histo5->Draw("hist same");
  legend->Draw();

  /* pd->Draw(); */
  pd->cd();
  histo2d->Draw("hist");
  histo3d->Draw("hist same");
  histo4d->Draw("hist same");
  histo5d->Draw("hist same");

  c->SetTitle("Single Scatter cut (100-300keV) with noise");
  c->SaveAs("combines_plot.png");
}
