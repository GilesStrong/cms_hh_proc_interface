#include "cms_hh_proc_interface/processing/interface/feat_comp.hh"
#include <iostream>
#include <string>
#include <map>
#include <random>
#include <Math/VectorUtil.h>
#include <Math/LorentzVector.h>
#include <Math/PxPyPzM4D.h>

int main(int argc, char *argv[]) {
	using LorentzVector = ROOT::Math::LorentzVector<ROOT::Math::PxPyPzM4D<float>>;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_real_distribution<> mom(-100.,100.);
    std::uniform_real_distribution<> energy(20.,500.);
    std::uniform_real_distribution<> csv(-1.,1.);

    std::cout << "Instantiating FeatComp... ";
    FeatComp feat_comp;
    std::cout << "Instantiated\n ";

    std::cout << "Generating random event... ";
    LorentzVector b_1(mom(rng),mom(rng),mom(rng),energy(rng));
    LorentzVector b_2(mom(rng),mom(rng),mom(rng),energy(rng));
    LorentzVector l_1(mom(rng),mom(rng),mom(rng),energy(rng));
    LorentzVector l_2(mom(rng),mom(rng),mom(rng),energy(rng));
    LorentzVector met(mom(rng),mom(rng),0,       energy(rng));
    LorentzVector sv(mom(rng),mom(rng),mom(rng),energy(rng));
    LorentzVector vbf_1(mom(rng),mom(rng),mom(rng),energy(rng));
    LorentzVector vbf_2(mom(rng),mom(rng),mom(rng),energy(rng));
    float hh_kinfit_mass = energy(rng);
    bool is_boosted = csv(rng) > 1.;
    float csv_1(csv(rng)), csv_2(csv(rng));
    float b_1_cvsl(csv(rng)), b_2_cvsl(csv(rng)), vbf_1_cvsl(csv(rng)), vbf_2_cvsl(csv(rng));
    float b_1_cvsb(csv(rng)), b_2_cvsb(csv(rng)), vbf_1_cvsb(csv(rng)), vbf_2_cvsb(csv(rng));
    Channel channel = tauTau;
    Year year = y16;
    std::cout << "Generated\n";

    std::cout << "Processing event... ";
    std::map<std::string, float> feats = feat_comp.process(b_1, b_2, l_1, l_2, met, sv, vbf_1, vbf_2, hh_kinfit_mass, is_boosted,
                                                           csv_1, csv_2, channel, year, 0, true, true, b_1_cvsl, b_2_cvsl, vbf_1_cvsl, vbf_2_cvsl,
                                                           b_1_cvsb, b_2_cvsb, vbf_1_cvsb, vbf_2_cvsb);
    std::cout << "Processed\n";

    for (auto const& f : feats) std::cout << f.first << ":" << f.second << "\n";

    return 0;
}