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

#ifndef TARCOGParams_hh_INCLUDED
#define TARCOGParams_hh_INCLUDED

// EnergyPlus Headers
#include <EnergyPlus.hh>

namespace EnergyPlus {

namespace TARCOGParams {

    // Data
    // REAL(r64), parameter :: StefanBoltzmannConst    = 5.6697d-8     ! Stefan-Boltzman constant (5.6697e-8 [W/m^2K^4])
    // REAL(r64), parameter :: GravityConstant = 9.807d0
    thread_local extern Real64 const e;
    // REAL(r64), parameter :: MaxHr = 100  ! used in iterations in case temperatures on surfaces reaches identical values
    thread_local extern Real64 const DeflectionRelaxation;  // Deflection relaxation parameter
    thread_local extern int const DeflectionMaxIterations;  // maximum number of deflection iterations
    thread_local extern Real64 const DeflectionErrorMargin; // maximum temperature difference on layers for deflection iterations
    // pi is moved to gasses since it is used there now
    // REAL(r64), parameter :: pi       = 3.14159265358979323846d0

    thread_local extern int const maxpan; // maximum number of monolithic glazing layers (100)
    // integer, parameter :: maxlay   = 1000         ! maximum number of layers (including laminates) (1000)
    thread_local extern int const maxlay;   // maximum number of layers (including laminates) (100)
    thread_local extern int const MaxGap;   // maximum number of gaps (between layers)
    thread_local extern int const maxlay1;  // maximum number of 'gaps', including in and out (maxlay+1)
    thread_local extern int const maxlay2;  // maximum number of glass surfaces (maxlay*2)
    thread_local extern int const maxlay3;  // maximum number of ? (maxlay2+1)
    thread_local extern int const maxlay4;  // maximum number of ? (maxlay*4)
    thread_local extern int const maxslice; // maximum nuber of slices (100)

    // integer, parameter :: MaxThetaArray = 200     ! maximum number for theta array

    // Debug flags
    thread_local extern int const noDebug;
    thread_local extern int const appendResultsToFile;
    thread_local extern int const resultsToNewFile;
    thread_local extern int const saveIntermediateResults; // this will create new file

    thread_local extern int const minDebugFlag;
    thread_local extern int const maxDebugFlag;

    // to keep info that certain file is not open for writing
    thread_local extern int const statusClosed;

    //  Layer types:
    thread_local extern int const SPECULAR;
    thread_local extern int const VENETBLIND_VERT;
    thread_local extern int const WOVSHADE;
    thread_local extern int const PERFORATED;
    thread_local extern int const DIFFSHADE;
    thread_local extern int const BSDF;
    thread_local extern int const VENETBLIND_HORIZ;

    thread_local extern int const MinLayType;
    thread_local extern int const MaxLayType;

    //  Thermal models:
    thread_local extern int const THERM_MOD_ISO15099;
    thread_local extern int const THERM_MOD_SCW;
    thread_local extern int const THERM_MOD_CSM;

    thread_local extern int const MinThermalMode;
    thread_local extern int const MaxThermalMode;

    thread_local extern int const NO_SupportPillar;
    thread_local extern int const YES_SupportPillar;

    // Deflection parameters
    thread_local extern int const NO_DEFLECTION_CALCULATION;
    thread_local extern int const DEFLECTION_CALC_TEMPERATURE;
    thread_local extern int const DEFLECTION_CALC_GAP_WIDTHS;

    // definition of parameters for deflection sum.  These parameters define maximum number of loop to which sum
    // will perform. By equation, these numbers will go to infinite and some test showed that going to nmax and mmax
    // values would produce enough precision
    thread_local extern int const mmax; // top m value for which "deflection sum" will be calculated
    thread_local extern int const nmax; // top n value for which "deflection sum" will be calculated

    //  CalcForcedVentilation flag:
    //  0 = Skip forced ventilation calc
    //  1 = Allow forced ventilation calc
    thread_local extern int const CalcForcedVentilation;

    //  Calculation outcome
    thread_local extern int const CALC_UNKNOWN;
    thread_local extern int const CALC_OK;
    thread_local extern int const CALC_DIVERGE;
    thread_local extern int const CALC_OSC_OK;

    thread_local extern int const NumOfIterations;

    // Program will examine convergence parameter in each iteration.  That convergence parameter should decrease each time.
    // In case that is not happening program will tolerate certain number of tries before declare convergence
    // (or decrease relaxation parameter)
    thread_local extern int const NumOfTries;
    // integer, parameter :: NewtonIterations = 75 ! shows when to swith to Newton
    thread_local extern Real64 const RelaxationStart;    // Has to be between 0 and 1
    thread_local extern Real64 const RelaxationDecrease; // Step for which relaxation parameter will decrease

    // Convergence parameters
    thread_local extern Real64 const tempCorrection;       // used in case outside or inside temperature approaches tamb or troom
    thread_local extern Real64 const ConvergenceTolerance; // tolerance used within iterations

    // Airflow iterations
    thread_local extern Real64 const AirflowConvergenceTolerance;
    thread_local extern Real64 const AirflowRelaxationParameter;

    thread_local extern Real64 const TemperatureQuessDiff; // in case outside and inside temperatures are identical

    thread_local extern Real64 const C1_VENET_HORIZONTAL;
    thread_local extern Real64 const C2_VENET_HORIZONTAL;
    thread_local extern Real64 const C3_VENET_HORIZONTAL;
    thread_local extern Real64 const C4_VENET_HORIZONTAL;

    thread_local extern Real64 const C1_VENET_VERTICAL;
    thread_local extern Real64 const C2_VENET_VERTICAL;
    thread_local extern Real64 const C3_VENET_VERTICAL;
    thread_local extern Real64 const C4_VENET_VERTICAL;

    thread_local extern Real64 const C1_SHADE;
    thread_local extern Real64 const C2_SHADE;
    thread_local extern Real64 const C3_SHADE;
    thread_local extern Real64 const C4_SHADE;

} // namespace TARCOGParams

} // namespace EnergyPlus

#endif
