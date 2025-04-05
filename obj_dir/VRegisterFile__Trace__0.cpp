// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VRegisterFile__Syms.h"


void VRegisterFile___024root__trace_chg_0_sub_0(VRegisterFile___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VRegisterFile___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root__trace_chg_0\n"); );
    // Init
    VRegisterFile___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRegisterFile___024root*>(voidSelf);
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    VRegisterFile___024root__trace_chg_0_sub_0((&vlSymsp->TOP), bufp);
}

void VRegisterFile___024root__trace_chg_0_sub_0(VRegisterFile___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root__trace_chg_0_sub_0\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY((vlSelfRef.__Vm_traceActivity[1U]))) {
        bufp->chgIData(oldp+0,(vlSelfRef.RegisterFile__DOT__registers[0]),32);
        bufp->chgIData(oldp+1,(vlSelfRef.RegisterFile__DOT__registers[1]),32);
        bufp->chgIData(oldp+2,(vlSelfRef.RegisterFile__DOT__registers[2]),32);
        bufp->chgIData(oldp+3,(vlSelfRef.RegisterFile__DOT__registers[3]),32);
        bufp->chgIData(oldp+4,(vlSelfRef.RegisterFile__DOT__registers[4]),32);
        bufp->chgIData(oldp+5,(vlSelfRef.RegisterFile__DOT__registers[5]),32);
        bufp->chgIData(oldp+6,(vlSelfRef.RegisterFile__DOT__registers[6]),32);
        bufp->chgIData(oldp+7,(vlSelfRef.RegisterFile__DOT__registers[7]),32);
        bufp->chgIData(oldp+8,(vlSelfRef.RegisterFile__DOT__registers[8]),32);
        bufp->chgIData(oldp+9,(vlSelfRef.RegisterFile__DOT__registers[9]),32);
        bufp->chgIData(oldp+10,(vlSelfRef.RegisterFile__DOT__registers[10]),32);
        bufp->chgIData(oldp+11,(vlSelfRef.RegisterFile__DOT__registers[11]),32);
        bufp->chgIData(oldp+12,(vlSelfRef.RegisterFile__DOT__registers[12]),32);
        bufp->chgIData(oldp+13,(vlSelfRef.RegisterFile__DOT__registers[13]),32);
        bufp->chgIData(oldp+14,(vlSelfRef.RegisterFile__DOT__registers[14]),32);
        bufp->chgIData(oldp+15,(vlSelfRef.RegisterFile__DOT__registers[15]),32);
        bufp->chgIData(oldp+16,(vlSelfRef.RegisterFile__DOT__registers[16]),32);
        bufp->chgIData(oldp+17,(vlSelfRef.RegisterFile__DOT__registers[17]),32);
        bufp->chgIData(oldp+18,(vlSelfRef.RegisterFile__DOT__registers[18]),32);
        bufp->chgIData(oldp+19,(vlSelfRef.RegisterFile__DOT__registers[19]),32);
        bufp->chgIData(oldp+20,(vlSelfRef.RegisterFile__DOT__registers[20]),32);
        bufp->chgIData(oldp+21,(vlSelfRef.RegisterFile__DOT__registers[21]),32);
        bufp->chgIData(oldp+22,(vlSelfRef.RegisterFile__DOT__registers[22]),32);
        bufp->chgIData(oldp+23,(vlSelfRef.RegisterFile__DOT__registers[23]),32);
        bufp->chgIData(oldp+24,(vlSelfRef.RegisterFile__DOT__registers[24]),32);
        bufp->chgIData(oldp+25,(vlSelfRef.RegisterFile__DOT__registers[25]),32);
        bufp->chgIData(oldp+26,(vlSelfRef.RegisterFile__DOT__registers[26]),32);
        bufp->chgIData(oldp+27,(vlSelfRef.RegisterFile__DOT__registers[27]),32);
        bufp->chgIData(oldp+28,(vlSelfRef.RegisterFile__DOT__registers[28]),32);
        bufp->chgIData(oldp+29,(vlSelfRef.RegisterFile__DOT__registers[29]),32);
        bufp->chgIData(oldp+30,(vlSelfRef.RegisterFile__DOT__registers[30]),32);
        bufp->chgIData(oldp+31,(vlSelfRef.RegisterFile__DOT__registers[31]),32);
        bufp->chgIData(oldp+32,(vlSelfRef.RegisterFile__DOT__i),32);
    }
    bufp->chgBit(oldp+33,(vlSelfRef.clk));
    bufp->chgBit(oldp+34,(vlSelfRef.reset));
    bufp->chgCData(oldp+35,(vlSelfRef.addrA),5);
    bufp->chgCData(oldp+36,(vlSelfRef.addrB),5);
    bufp->chgCData(oldp+37,(vlSelfRef.addrD),5);
    bufp->chgIData(oldp+38,(vlSelfRef.dataD),32);
    bufp->chgBit(oldp+39,(vlSelfRef.reg_write));
    bufp->chgIData(oldp+40,(vlSelfRef.dataA),32);
    bufp->chgIData(oldp+41,(vlSelfRef.dataB),32);
}

void VRegisterFile___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root__trace_cleanup\n"); );
    // Init
    VRegisterFile___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRegisterFile___024root*>(voidSelf);
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
