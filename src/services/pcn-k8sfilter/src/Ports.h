/*
 * Copyright 2018 The Polycube Authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#pragma once

#include "../interface/PortsInterface.h"

#include "polycube/services/cube.h"
#include "polycube/services/fifo_map.hpp"
#include "polycube/services/port.h"
#include "polycube/services/utils.h"

#include <spdlog/spdlog.h>

class K8sfilter;

using namespace io::swagger::server::model;

class Ports : public polycube::service::Port, public PortsInterface {
 public:
  Ports(polycube::service::Cube<Ports> &parent,
        std::shared_ptr<polycube::service::PortIface> port,
        const PortsJsonObject &conf);
  virtual ~Ports();

  std::shared_ptr<spdlog::logger> logger();
  void update(const PortsJsonObject &conf) override;
  PortsJsonObject toJsonObject() override;

  /// <summary>
  /// ...
  /// </summary>
  PortsTypeEnum getType() override;

 private:
  K8sfilter &parent_;
  PortsTypeEnum port_type_;
};
