/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2018 National University of Ireland, Maynooth
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as 
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 * Author: Joseph Finnegan <joseph.finnegan@mu.ie>
 */

#ifndef LORAWAN_RADIO_ENERGY_MODEL_HELPER_H
#define LORAWAN_RADIO_ENERGY_MODEL_HELPER_H

#include "ns3/energy-model-helper.h"
#include "ns3/lorawan-radio-energy-model.h"

namespace ns3 {

/**
 * \ingroup energy
 * \brief Assign LoRaWANRadioEnergyModel to LoRaWAN devices.
 *
 * This installer installs LoRaWANRadioEnergyModel for only LoRaWANNetDevice objects.
 *
 */
class LoRaWANRadioEnergyModelHelper : public DeviceEnergyModelHelper
{
public:
  /**
   * Construct a helper which is used to add a radio energy model to a node
   */
  LoRaWANRadioEnergyModelHelper ();

  /**
   * Destroy a RadioEnergy Helper
   */
  ~LoRaWANRadioEnergyModelHelper ();

  /**
   * \param name the name of the attribute to set
   * \param v the value of the attribute
   *
   * Sets an attribute of the underlying PHY object.
   */
  void Set (std::string name, const AttributeValue &v);

  /**
   * \param callback Callback function for energy depletion handling.
   *
   * Sets the callback to be invoked when energy is depleted.
   */
  void SetDepletionCallback (
    LoRaWANRadioEnergyModel::LoRaWANRadioEnergyDepletionCallback callback);

  /**
   * \param callback Callback function for energy recharged handling.
   *
   * Sets the callback to be invoked when energy is recharged.
   */
  void SetRechargedCallback (
    LoRaWANRadioEnergyModel::LoRaWANRadioEnergyRechargedCallback callback);

  /**
   * \param currentModel the name of the model to set
   *
   * Configure a Current model for this EnergySource.
   */
  void SetCurrentModel (std::string currentModel);

private:
  /**
   * \param device Pointer to the NetDevice to install DeviceEnergyModel.
   * \param source Pointer to EnergySource to install.
   *
   * Implements DeviceEnergyModel::Install.
   */
  virtual Ptr<DeviceEnergyModel> DoInstall (Ptr<NetDevice> device,
                                            Ptr<EnergySource> source) const;

private:
  ObjectFactory m_radioEnergy;
  LoRaWANRadioEnergyModel::LoRaWANRadioEnergyDepletionCallback m_depletionCallback;
  LoRaWANRadioEnergyModel::LoRaWANRadioEnergyRechargedCallback m_rechargedCallback;
  ObjectFactory m_currentModel;

};

} // namespace ns3

#endif /* LORAWAN_RADIO_ENERGY_MODEL_HELPER_H */

