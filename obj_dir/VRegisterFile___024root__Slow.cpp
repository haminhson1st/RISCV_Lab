// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRegisterFile.h for the primary calling header

#include "VRegisterFile__pch.h"
#include "VRegisterFile__Syms.h"
#include "VRegisterFile___024root.h"

void VRegisterFile___024root___ctor_var_reset(VRegisterFile___024root* vlSelf);

VRegisterFile___024root::VRegisterFile___024root(VRegisterFile__Syms* symsp, const char* v__name)
    : VerilatedModule{v__name}
    , vlSymsp{symsp}
 {
    // Reset structure values
    VRegisterFile___024root___ctor_var_reset(this);
}

void VRegisterFile___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

VRegisterFile___024root::~VRegisterFile___024root() {
}
