#ifndef FEAT_COMP_HH_
#define FEAT_COMP_HH_

// C++
#include <iostream>
#include <string>
#include <map>
#include <vector>

// ROOT
#include <Math/VectorUtil.h>
#include <Math/LorentzVector.h>

using LorentzVector ROOT::Math::LorentzVector;

class FeatComp {
	/* Class for computing requested features for final-state LorentzVectors*/

private:
	// Variables
    bool _all, _verbose, _use_deep_csv;
    std::vector<std::string> _requested;
	std::vector<float> _csv_wps{0, 0.5426, 0.8484, 0.9535};  // TODO: Check these
	std::vector<float> _deep_csv_wps{0, 0.5426, 0.8484, 0.9535};  //TODO: Update these

	// Methods
	void _add_jet_flags(const float&, const float&, const float&, const float&, std::map<std::string, float>&);
	inline bool _feat_check(std::string);

public:
	// Classes
	enum Channel{tauTau=0, muTau=1, eTau=2};

    // Methods
	FeatComp(bool, std::vector<std::string>, bool, bool);
	~FeatComp();
	std::map<std::string, float> process(const LorentzVector&,  // b_1
										 const LorentzVector&,  // b_2
										 const LorentzVector&,  // l_1
										 const LorentzVector&,  // l_2
										 const LorentzVector&,  // MET
										 const LorentzVector&,  // SVFit
										 const float&,           // HH KinFit mass
										 const bool&, 			 // Is boosted
										 const float&,			 // b_1 CSV
										 const float&,			 // b_2 CSV
										 const float&,			 // b_1 Deep CSV
										 const float&,			 // b_2 Deep CSV
										 FeatComp::Channel);	 // Channel		
	inline float delta_eta(const LorentzVector&, const LorentzVector&);
	inline float delta_phi(const LorentzVector&, const LorentzVector&);
	inline float delta_r_boosted(const LorentzVector&, const LorentzVector&, const LorentzVector&);
	inline float calc_mt(const LorentzVector&, const LorentzVector&);
	inline float calc_phi(const LorentzVector&, const LorentzVector&, const LorentzVector&, const LorentzVector&, const LorentzVector&);
	inline float calc_phi_1(const LorentzVector&, const LorentzVector&, const LorentzVector&, const LorentzVector&);
	inline float calc_cos_delta_star(const LorentzVector&, const LorentzVector&);
	inline float calc_cos_delta(const LorentzVector&, const LorentzVector&);
};

#endif /* FEAT_COMP_HH__HH_ */
