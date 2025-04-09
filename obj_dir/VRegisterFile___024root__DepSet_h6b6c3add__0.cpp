// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VRegisterFile.h for the primary calling header

#include "VRegisterFile__pch.h"
#include "VRegisterFile___024root.h"

void VRegisterFile___024root___ico_sequent__TOP__0(VRegisterFile___024root* vlSelf);

void VRegisterFile___024root___eval_ico(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_ico\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1ULL & vlSelfRef.__VicoTriggered.word(0U))) {
        VRegisterFile___024root___ico_sequent__TOP__0(vlSelf);
    }
}

VL_INLINE_OPT void VRegisterFile___024root___ico_sequent__TOP__0(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___ico_sequent__TOP__0\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (vlSelfRef.reset) {
        vlSelfRef.dataA = vlSelfRef.RegisterFile__DOT__registers
            [vlSelfRef.addrA];
        vlSelfRef.dataB = vlSelfRef.RegisterFile__DOT__registers
            [vlSelfRef.addrB];
    } else {
        vlSelfRef.dataA = 0U;
        vlSelfRef.dataB = 0U;
    }
}

void VRegisterFile___024root___eval_triggers__ico(VRegisterFile___024root* vlSelf);

bool VRegisterFile___024root___eval_phase__ico(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_phase__ico\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VicoExecute;
    // Body
    VRegisterFile___024root___eval_triggers__ico(vlSelf);
    __VicoExecute = vlSelfRef.__VicoTriggered.any();
    if (__VicoExecute) {
        VRegisterFile___024root___eval_ico(vlSelf);
    }
    return (__VicoExecute);
}

void VRegisterFile___024root___eval_act(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_act\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

void VRegisterFile___024root___nba_sequent__TOP__0(VRegisterFile___024root* vlSelf);

void VRegisterFile___024root___eval_nba(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_nba\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((3ULL & vlSelfRef.__VnbaTriggered.word(0U))) {
        VRegisterFile___024root___nba_sequent__TOP__0(vlSelf);
        vlSelfRef.__Vm_traceActivity[1U] = 1U;
    }
}

VL_INLINE_OPT void VRegisterFile___024root___nba_sequent__TOP__0(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___nba_sequent__TOP__0\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VdlyVal__RegisterFile__DOT__registers__v0;
    __VdlyVal__RegisterFile__DOT__registers__v0 = 0;
    CData/*4:0*/ __VdlyDim0__RegisterFile__DOT__registers__v0;
    __VdlyDim0__RegisterFile__DOT__registers__v0 = 0;
    CData/*0:0*/ __VdlySet__RegisterFile__DOT__registers__v0;
    __VdlySet__RegisterFile__DOT__registers__v0 = 0;
    CData/*0:0*/ __VdlySet__RegisterFile__DOT__registers__v1;
    __VdlySet__RegisterFile__DOT__registers__v1 = 0;
    // Body
    __VdlySet__RegisterFile__DOT__registers__v0 = 0U;
    __VdlySet__RegisterFile__DOT__registers__v1 = 0U;
    if ((1U & (~ (IData)(vlSelfRef.reset)))) {
        vlSelfRef.RegisterFile__DOT__i = 0x20U;
    }
    if (vlSelfRef.reset) {
        if (vlSelfRef.reg_write) {
            if ((0U != (IData)(vlSelfRef.addrD))) {
                __VdlyVal__RegisterFile__DOT__registers__v0 
                    = vlSelfRef.dataD;
                __VdlyDim0__RegisterFile__DOT__registers__v0 
                    = vlSelfRef.addrD;
                __VdlySet__RegisterFile__DOT__registers__v0 = 1U;
            }
        }
    } else {
        __VdlySet__RegisterFile__DOT__registers__v1 = 1U;
    }
    if (__VdlySet__RegisterFile__DOT__registers__v0) {
        vlSelfRef.RegisterFile__DOT__registers[__VdlyDim0__RegisterFile__DOT__registers__v0] 
            = __VdlyVal__RegisterFile__DOT__registers__v0;
    }
    if (__VdlySet__RegisterFile__DOT__registers__v1) {
        vlSelfRef.RegisterFile__DOT__registers[0U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[1U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[2U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[3U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[4U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[5U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[6U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[7U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[8U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[9U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0xaU] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0xbU] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0xcU] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0xdU] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0xeU] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0xfU] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x10U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x11U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x12U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x13U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x14U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x15U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x16U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x17U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x18U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x19U] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x1aU] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x1bU] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x1cU] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x1dU] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x1eU] = 0U;
        vlSelfRef.RegisterFile__DOT__registers[0x1fU] = 0U;
    }
    if (vlSelfRef.reset) {
        vlSelfRef.dataA = vlSelfRef.RegisterFile__DOT__registers
            [vlSelfRef.addrA];
        vlSelfRef.dataB = vlSelfRef.RegisterFile__DOT__registers
            [vlSelfRef.addrB];
    } else {
        vlSelfRef.dataA = 0U;
        vlSelfRef.dataB = 0U;
    }
}

void VRegisterFile___024root___eval_triggers__act(VRegisterFile___024root* vlSelf);

bool VRegisterFile___024root___eval_phase__act(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_phase__act\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    VlTriggerVec<2> __VpreTriggered;
    CData/*0:0*/ __VactExecute;
    // Body
    VRegisterFile___024root___eval_triggers__act(vlSelf);
    __VactExecute = vlSelfRef.__VactTriggered.any();
    if (__VactExecute) {
        __VpreTriggered.andNot(vlSelfRef.__VactTriggered, vlSelfRef.__VnbaTriggered);
        vlSelfRef.__VnbaTriggered.thisOr(vlSelfRef.__VactTriggered);
        VRegisterFile___024root___eval_act(vlSelf);
    }
    return (__VactExecute);
}

bool VRegisterFile___024root___eval_phase__nba(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_phase__nba\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = vlSelfRef.__VnbaTriggered.any();
    if (__VnbaExecute) {
        VRegisterFile___024root___eval_nba(vlSelf);
        vlSelfRef.__VnbaTriggered.clear();
    }
    return (__VnbaExecute);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VRegisterFile___024root___dump_triggers__ico(VRegisterFile___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VRegisterFile___024root___dump_triggers__nba(VRegisterFile___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void VRegisterFile___024root___dump_triggers__act(VRegisterFile___024root* vlSelf);
#endif  // VL_DEBUG

void VRegisterFile___024root___eval(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    IData/*31:0*/ __VicoIterCount;
    CData/*0:0*/ __VicoContinue;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VicoIterCount = 0U;
    vlSelfRef.__VicoFirstIteration = 1U;
    __VicoContinue = 1U;
    while (__VicoContinue) {
        if (VL_UNLIKELY(((0x64U < __VicoIterCount)))) {
#ifdef VL_DEBUG
            VRegisterFile___024root___dump_triggers__ico(vlSelf);
#endif
            VL_FATAL_MT("RegisterFile.v", 1, "", "Input combinational region did not converge.");
        }
        __VicoIterCount = ((IData)(1U) + __VicoIterCount);
        __VicoContinue = 0U;
        if (VRegisterFile___024root___eval_phase__ico(vlSelf)) {
            __VicoContinue = 1U;
        }
        vlSelfRef.__VicoFirstIteration = 0U;
    }
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        if (VL_UNLIKELY(((0x64U < __VnbaIterCount)))) {
#ifdef VL_DEBUG
            VRegisterFile___024root___dump_triggers__nba(vlSelf);
#endif
            VL_FATAL_MT("RegisterFile.v", 1, "", "NBA region did not converge.");
        }
        __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
        __VnbaContinue = 0U;
        vlSelfRef.__VactIterCount = 0U;
        vlSelfRef.__VactContinue = 1U;
        while (vlSelfRef.__VactContinue) {
            if (VL_UNLIKELY(((0x64U < vlSelfRef.__VactIterCount)))) {
#ifdef VL_DEBUG
                VRegisterFile___024root___dump_triggers__act(vlSelf);
#endif
                VL_FATAL_MT("RegisterFile.v", 1, "", "Active region did not converge.");
            }
            vlSelfRef.__VactIterCount = ((IData)(1U) 
                                         + vlSelfRef.__VactIterCount);
            vlSelfRef.__VactContinue = 0U;
            if (VRegisterFile___024root___eval_phase__act(vlSelf)) {
                vlSelfRef.__VactContinue = 1U;
            }
        }
        if (VRegisterFile___024root___eval_phase__nba(vlSelf)) {
            __VnbaContinue = 1U;
        }
    }
}

#ifdef VL_DEBUG
void VRegisterFile___024root___eval_debug_assertions(VRegisterFile___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root___eval_debug_assertions\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.clk & 0xfeU)))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY(((vlSelfRef.reset & 0xfeU)))) {
        Verilated::overWidthError("reset");}
    if (VL_UNLIKELY(((vlSelfRef.addrA & 0xe0U)))) {
        Verilated::overWidthError("addrA");}
    if (VL_UNLIKELY(((vlSelfRef.addrB & 0xe0U)))) {
        Verilated::overWidthError("addrB");}
    if (VL_UNLIKELY(((vlSelfRef.addrD & 0xe0U)))) {
        Verilated::overWidthError("addrD");}
    if (VL_UNLIKELY(((vlSelfRef.reg_write & 0xfeU)))) {
        Verilated::overWidthError("reg_write");}
}
#endif  // VL_DEBUG
