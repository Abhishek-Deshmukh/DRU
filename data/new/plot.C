void plot() {

  TFile* f =new TFile("ssc_output_100000000.root");
  TH1F *h1 = new TH1F("h1", "Single Scatter cut", 250, 0, 20);
  h1->SetTitle("Single-scatter cut");
  h1->GetXaxis()->SetTitle("Counts");
  h1->GetYaxis()->SetTitle("Energy [keV]");

  /* TTree* SingleScatterCutTree; */
  /* SingleScatterCutTree = (TTree*)f->FindObject("SingleScatterCutTree"); */

  TCanvas* c = new TCanvas("c1", "Single scatter cut", 1024, 768);
  c->cd();
  SingleScatterCutTree->Draw("CoinEnergyDep>>h1");
  c->SetLogy();
  c->SaveAs("sscplot.png");
}
