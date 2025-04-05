// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRegisterFile.h for the primary calling header

#include "VRegisterFile__pch.h"
#include "VRegisterFile__Syms.h"
#include "VRegisterFile___024root.h"

#ifdef VL_DEBUG
VL_ATTR_COLD void VRegisterFile___024root___dump_triggers__stl(VRegisterFile___024root* vlSelf);
#endif  // VL_DEBUG

VL_ATTR_COLD void VRegisterFile___024root___eval_triggers__stl(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_triggers__stl\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered.set(0U, (IData)(vlSelfRef.__VstlFirstIteration));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VRegisterFile___024root___dump_triggers__stl(vlSelf);
    }
#endif
}
