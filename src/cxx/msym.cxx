#include <msym.hpp>
#include <iostream>

void MSym::GetSetElements_(std::vector<msym_element_t> &elements) {
  msym_error_t ret;

  ret = msymSetElements(ctx_,elements.size(),&elements[0]);
  ret = msymGetElements(ctx_,&mLength_,&melements_);
};

void MSym::GetCenterOfMass_() {
  msym_error_t ret;

  ret = msymGetCenterOfMass(ctx_,&cm_[0]);
};

void MSym::GetRadius_(){
  msym_error_t ret;

  ret = msymGetRadius(ctx_,&radius_);
};

void MSym::FindSymmetry_(){
  msym_error_t ret;

  ret = msymFindSymmetry(ctx_);

  point_group_.resize(6);
  ret = msymGetPointGroupName(ctx_,sizeof(char[6]),
    const_cast<char*>(point_group_.c_str()));

  ret = msymGetSubgroups(ctx_,&mSubGroupLength_,&mSubGroups_);
};
