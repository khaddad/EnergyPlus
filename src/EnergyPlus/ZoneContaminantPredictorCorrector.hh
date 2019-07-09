// EnergyPlus, Copyright (c) 1996-2019, The Board of Trustees of the University of Illinois,
// The Regents of the University of California, through Lawrence Berkeley National Laboratory
// (subject to receipt of any required approvals from the U.S. Dept. of Energy), Oak Ridge
// National Laboratory, managed by UT-Battelle, Alliance for Sustainable Energy, LLC, and other
// contributors. All rights reserved.
//
// NOTICE: This Software was developed under funding from the U.S. Department of Energy and the
// U.S. Government consequently retains certain rights. As such, the U.S. Government has been
// granted for itself and others acting on its behalf a paid-up, nonexclusive, irrevocable,
// worldwide license in the Software to reproduce, distribute copies to the public, prepare
// derivative works, and perform publicly and display publicly, and to permit others to do so.
//
// Redistribution and use in source and binary forms, with or without modification, are permitted
// provided that the following conditions are met:
//
// (1) Redistributions of source code must retain the above copyright notice, this list of
//     conditions and the following disclaimer.
//
// (2) Redistributions in binary form must reproduce the above copyright notice, this list of
//     conditions and the following disclaimer in the documentation and/or other materials
//     provided with the distribution.
//
// (3) Neither the name of the University of California, Lawrence Berkeley National Laboratory,
//     the University of Illinois, U.S. Dept. of Energy nor the names of its contributors may be
//     used to endorse or promote products derived from this software without specific prior
//     written permission.
//
// (4) Use of EnergyPlus(TM) Name. If Licensee (i) distributes the software in stand-alone form
//     without changes from the version obtained under this License, or (ii) Licensee makes a
//     reference solely to the software portion of its product, Licensee must refer to the
//     software as "EnergyPlus version X" software, where "X" is the version number Licensee
//     obtained under this License and may not use a different name for the software. Except as
//     specifically required in this Section (4), Licensee shall not use in a company name, a
//     product name, in advertising, publicity, or other promotional activities any name, trade
//     name, trademark, logo, or other designation of "EnergyPlus", "E+", "e+" or confusingly
//     similar designation, without the U.S. Department of Energy's prior written consent.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR
// IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY
// AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
// CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
// THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
// OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#ifndef ZoneContaminantPredictorCorrector_hh_INCLUDED
#define ZoneContaminantPredictorCorrector_hh_INCLUDED

// EnergyPlus Headers
#include <EnergyPlus.hh>

namespace EnergyPlus {

namespace ZoneContaminantPredictorCorrector {

    // Data
    // MODULE PARAMETER DEFINITIONS:
    // na

    // DERIVED TYPE DEFINITIONS:
    // INTERFACE BLOCK SPECIFICATIONS:
    // na

    // MODULE VARIABLE DECLARATIONS:

    thread_local extern bool GetZoneAirContamInputFlag; // True when need to get input
    thread_local extern int TotGCGenConstant;           // Number of constant generic contaminant sources and sinks
    thread_local extern int TotGCGenPDriven;            // Number of pressure driven generic contaminant sources and sinks
    thread_local extern int TotGCGenCutoff;             // Number of cutoff model generic contaminant sources and sinks
    thread_local extern int TotGCGenDecay;              // Number of decay model generic contaminant sources and sinks
    thread_local extern int TotGCBLDiff;                // Number of boudary layer diffusion generic contaminant model
    thread_local extern int TotGCDVS;                   // Number of deposition velocity sink generic contaminant model
    thread_local extern int TotGCDRS;                   // Number of deposition rate sink generic contaminant model

    // SUBROUTINE SPECIFICATIONS:

    // Functions

    void clear_state();

    void ManageZoneContaminanUpdates(int const UpdateType, // Can be iGetZoneSetPoints, iPredictStep, iCorrectStep
                                     bool const ShortenTimeStepSys,
                                     bool const UseZoneTimeStepHistory, // if true then use zone timestep history, if false use system time step
                                     Real64 const PriorTimeStep // the old value for timestep length is passed for possible use in interpolating
    );

    void GetZoneContaminanInputs();

    void GetZoneContaminanSetPoints();

    void InitZoneContSetPoints();

    void PredictZoneContaminants(bool const ShortenTimeStepSys,
                                 bool const UseZoneTimeStepHistory, // if true then use zone timestep history, if false use system time step
                                 Real64 const PriorTimeStep         // the old value for timestep length is passed for possible use in interpolating
    );

    void PushZoneTimestepHistories();

    void PushSystemTimestepHistories();

    void RevertZoneTimestepHistories();

    void InverseModelCO2(int const ZoneNum,           // Zone number
                         Real64 &CO2Gain,             // Zone total CO2 gain
                         Real64 &CO2GainExceptPeople, // ZOne total CO2 gain from sources except for people
                         Real64 &ZoneMassFlowRate,    // Zone air mass flow rate
                         Real64 &CO2MassFlowRate,     // Zone air CO2 mass flow rate
                         Real64 &RhoAir               // Air density
    );

    void CorrectZoneContaminants(bool const ShortenTimeStepSys,
                                 bool const UseZoneTimeStepHistory, // if true then use zone timestep history, if false use system time step history
                                 Real64 const PriorTimeStep         // the old value for timestep length is passed for possible use in interpolating
    );

} // namespace ZoneContaminantPredictorCorrector

} // namespace EnergyPlus

#endif
