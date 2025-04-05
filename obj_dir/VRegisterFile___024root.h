// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VRegisterFile.h for the primary calling header

#ifndef VERILATED_VREGISTERFILE___024ROOT_H_
#define VERILATED_VREGISTERFILE___024ROOT_H_  // guard

#include "verilated.h"


class VRegisterFile__Syms;

class alignas(VL_CACHE_LINE_BYTES) VRegisterFile___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(addrA,4,0);
    VL_IN8(addrB,4,0);
    VL_IN8(addrD,4,0);
    VL_IN8(reg_write,0,0);
    CData/*0:0*/ __VstlFirstIteration;
    CData/*0:0*/ __VicoFirstIteration;
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __Vtrigprevexpr___TOP__reset__0;
    CData/*0:0*/ __VactContinue;
    VL_IN(dataD,31,0);
    VL_OUT(dataA,31,0);
    VL_OUT(dataB,31,0);
    IData/*31:0*/ RegisterFile__DOT__i;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> RegisterFile__DOT__registers;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    VRegisterFile__Syms* const vlSymsp;

    // CONSTRUCTORS
    VRegisterFile___024root(VRegisterFile__Syms* symsp, const char* v__name);
    ~VRegisterFile___024root();
    VL_UNCOPYABLE(VRegisterFile___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
