/**
* synflood API generated from synflood.yang
*
* NOTE: This file is auto generated by polycube-codegen
* https://github.com/polycube-network/polycube-codegen
*/


/* Do not edit this file manually */


#include "SynfloodBase.h"

SynfloodBase::SynfloodBase(const std::string name) {
  logger()->set_pattern("[%Y-%m-%d %H:%M:%S.%e] [Synflood] [%n] [%l] %v");
}



SynfloodBase::~SynfloodBase() {}

void SynfloodBase::update(const SynfloodJsonObject &conf) {
  set_conf(conf.getBase());

  if (conf.statsIsSet()) {
    auto m = getStats();
    m->update(conf.getStats());
  }
}

SynfloodJsonObject SynfloodBase::toJsonObject() {
  SynfloodJsonObject conf;
  conf.setBase(to_json());

  conf.setName(getName());
  conf.setStats(getStats()->toJsonObject());

  return conf;
}

void SynfloodBase::replaceStats(const StatsJsonObject &conf) {
  // TODO: This is a basic default implementation, maybe you want to improve it
  delStats();
  addStats(conf);
}


