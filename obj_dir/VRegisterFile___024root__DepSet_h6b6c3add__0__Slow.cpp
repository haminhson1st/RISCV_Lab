// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRegisterFile.h for the primary calling header

#include "VRegisterFile__pch.h"
#include "VRegisterFile___024root.h"

VL_ATTR_COLD void VRegisterFile___024root___eval_static(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_static\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VRegisterFile___024root___eval_initial(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_initial\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__reset__0 = vlSelfRef.reset;
}

VL_ATTR_COLD void VRegisterFile___024root___eval_final(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_final\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VRegisterFile___024root___dump_triggers__stl(VRegisterFile___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VRegisterFile___024root___eval_phase__stl(VRegisterFile___024root* vlSelf);

VL_ATTR_COLD void VRegisterFile___024root___eval_settle(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_settle\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VstlIterCount;
    CData/*0:0*/ __VstlContinue;
    // Body
    __VstlIterCount = 0U;
    vlSelfRef.__VstlFirstIteration = 1U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        if (VL_UNLIKELY(((0x64U < __VstlIterCount)))) {
#ifdef VL_DEBUG
            VRegisterFile___024root___dump_triggers__stl(vlSelf);
#endif
            VL_FATAL_MT("RegisterFile.v", 1, "", "Settle region did not converge.");
        }
        __VstlIterCount = ((IData)(1U) + __VstlIterCount);
        __VstlContinue = 0U;
        if (VRegisterFile___024root___eval_phase__stl(vlSelf)) {
            __VstlContinue = 1U;
        }
        vlSelfRef.__VstlFirstIteration = 0U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VRegisterFile___024root___dump_triggers__stl(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___dump_triggers__stl\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VstlTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

void VRegisterFile___024root___ico_sequent__TOP__0(VRegisterFile___024root* vlSelf);

VL_ATTR_COLD void VRegisterFile___024root___eval_stl(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_stl\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VstlTriggered.word(0U))) {
        VRegisterFile___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_ATTR_COLD void VRegisterFile___024root___eval_triggers__stl(VRegisterFile___024root* vlSelf);

VL_ATTR_COLD bool VRegisterFile___024root___eval_phase__stl(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_phase__stl\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VstlExecute;
    // Body
    VRegisterFile___024root___eval_triggers__stl(vlSelf);
    __VstlExecute = vlSelfRef.__VstlTriggered.any();
    if (__VstlExecute) {
        VRegisterFile___024root___eval_stl(vlSelf);
    }
    return (__VstlExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VRegisterFile___024root___dump_triggers__ico(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___dump_triggers__ico\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VicoTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VRegisterFile___024root___dump_triggers__act(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___dump_triggers__act\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VactTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VactTriggered.word(0U))) {
        VL_DBG_MSGF("         'act' region trigger index 1 is active: @(negedge reset)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void VRegisterFile___024root___dump_triggers__nba(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___dump_triggers__nba\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U & (~ vlSelfRef.__VnbaTriggered.any()))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if ((1ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((2ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VL_DBG_MSGF("         'nba' region trigger index 1 is active: @(negedge reset)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VRegisterFile___024root___ctor_var_reset(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___ctor_var_reset\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->reset = VL_RAND_RESET_I(1);
    vlSelf->addrA = VL_RAND_RESET_I(5);
    vlSelf->addrB = VL_RAND_RESET_I(5);
    vlSelf->addrD = VL_RAND_RESET_I(5);
    vlSelf->dataD = VL_RAND_RESET_I(32);
    vlSelf->reg_write = VL_RAND_RESET_I(1);
    vlSelf->dataA = VL_RAND_RESET_I(32);
    vlSelf->dataB = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->RegisterFile__DOT__registers[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->RegisterFile__DOT__i = VL_RAND_RESET_I(32);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = VL_RAND_RESET_I(1);
    vlSelf->__Vtrigprevexpr___TOP__reset__0 = VL_RAND_RESET_I(1);
    for (int __Vi0 = 0; __Vi0 < 2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = 0;
    }
}
