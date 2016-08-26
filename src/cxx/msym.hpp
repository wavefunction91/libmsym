#include <msym.h>
#include <cstdlib>
#include <array>
#include <vector>

class MSym {
  msym_context      ctx_;
  msym_element_t  * melements_;
  const msym_subgroup_t * mSubGroups_;
  int               mLength_;
  int               mSubGroupLength_;

  std::array<double,3> cm_;
  double               radius_;
  double               symerr_;

  std::string point_group_;

  void GetSetElements_(std::vector<msym_element_t> &);
  void GetCenterOfMass_();
  void GetRadius_();
  void FindSymmetry_();
public:
  MSym() = delete;
  MSym(std::vector<msym_element_t> &elements) : 
    ctx_(msymCreateContext()){

    GetSetElements_(elements); 
    GetCenterOfMass_();
    GetRadius_();
    FindSymmetry_();
  }

};
