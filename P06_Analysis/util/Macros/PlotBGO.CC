void PlotBGO(const char *file)
{
gROOT->Reset();
TFile *f = TFile::Open(file);
TCanvas * P_Canvas = new TCanvas("P_Canvas", "Energy Deposit");

TH1D * sum_eDep_1 = (TH1D*)f->Get("h1:0");
TH1D * sum_stepLength_1 = (TH1D*)f->Get("h1:1");
TH1D * sum_eDep_2 = (TH1D*)f->Get("h1:2");
TH1D * sum_stepLength_2 = (TH1D*)f->Get("h1:3");

P_Canvas->Divide(2,2);

P_Canvas->cd(1);
sum_eDep_1->Draw("HIST");

P_Canvas->cd(2);
sum_stepLength_1->Draw("HIST");

P_Canvas->cd(3);
sum_eDep_2->Draw("HIST");

P_Canvas->cd(4);
sum_stepLength_2->Draw("HIST");

}

