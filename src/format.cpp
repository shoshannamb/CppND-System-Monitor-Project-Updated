#include <cstdlib>
#include <string>

#include "format.h"

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
  std::div_t dv{};
  std::string time = "";
  dv.quot = seconds;
  dv = std::div(dv.quot, 3600);
  time += std::to_string(dv.quot) + "::";
  dv.quot = dv.rem;
  dv = std::div(dv.quot, 60);
  time += std::to_string(dv.quot) + "::" + std::to_string(dv.rem);
  return time;
}