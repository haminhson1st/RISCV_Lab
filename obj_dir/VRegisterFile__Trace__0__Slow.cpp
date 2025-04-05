// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "VRegisterFile__Syms.h"


VL_ATTR_COLD void VRegisterFile___024root__trace_init_sub__TOP__0(VRegisterFile___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root__trace_init_sub__TOP__0\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    const int c = vlSymsp->__Vm_baseCode;
    // Body
    tracep->declBit(c+34,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"addrA",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+37,0,"addrB",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+38,0,"addrD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+39,0,"dataD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+40,0,"reg_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+41,0,"dataA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"dataB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("RegisterFile", VerilatedTracePrefixType::SCOPE_MODULE);
    tracep->declBit(c+34,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBit(c+35,0,"reset",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+36,0,"addrA",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+37,0,"addrB",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+38,0,"addrD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 4,0);
    tracep->declBus(c+39,0,"dataD",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBit(c+40,0,"reg_write",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1);
    tracep->declBus(c+41,0,"dataA",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->declBus(c+42,0,"dataB",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, false,-1, 31,0);
    tracep->pushPrefix("registers", VerilatedTracePrefixType::ARRAY_UNPACKED);
    for (int i = 0; i < 32; ++i) {
        tracep->declBus(c+1+i*1,0,"",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, true,(i+0), 31,0);
    }
    tracep->popPrefix();
    tracep->declBus(c+33,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, false,-1, 31,0);
    tracep->popPrefix();
}

VL_ATTR_COLD void VRegisterFile___024root__trace_init_top(VRegisterFile___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root__trace_init_top\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VRegisterFile___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VRegisterFile___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
VL_ATTR_COLD void VRegisterFile___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VRegisterFile___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp);
void VRegisterFile___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/);

VL_ATTR_COLD void VRegisterFile___024root__trace_register(VRegisterFile___024root* vlSelf, VerilatedVcd* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root__trace_register\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VRegisterFile___024root__trace_const_0, 0U, vlSelf);
    tracep->addFullCb(&VRegisterFile___024root__trace_full_0, 0U, vlSelf);
    tracep->addChgCb(&VRegisterFile___024root__trace_chg_0, 0U, vlSelf);
    tracep->addCleanupCb(&VRegisterFile___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VRegisterFile___024root__trace_const_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root__trace_const_0\n"); );
    // Init
    VRegisterFile___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRegisterFile___024root*>(voidSelf);
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VRegisterFile___024root__trace_full_0_sub_0(VRegisterFile___024root* vlSelf, VerilatedVcd::Buffer* bufp);

VL_ATTR_COLD void VRegisterFile___024root__trace_full_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root__trace_full_0\n"); );
    // Init
    VRegisterFile___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRegisterFile___024root*>(voidSelf);
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    VRegisterFile___024root__trace_full_0_sub_0((&vlSymsp->TOP), bufp);
}

VL_ATTR_COLD void VRegisterFile___024root__trace_full_0_sub_0(VRegisterFile___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VRegisterFile___024root__trace_full_0_sub_0\n"); );
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    // Body
    bufp->fullIData(oldp+1,(vlSelfRef.RegisterFile__DOT__registers[0]),32);
    bufp->fullIData(oldp+2,(vlSelfRef.RegisterFile__DOT__registers[1]),32);
    bufp->fullIData(oldp+3,(vlSelfRef.RegisterFile__DOT__registers[2]),32);
    bufp->fullIData(oldp+4,(vlSelfRef.RegisterFile__DOT__registers[3]),32);
    bufp->fullIData(oldp+5,(vlSelfRef.RegisterFile__DOT__registers[4]),32);
    bufp->fullIData(oldp+6,(vlSelfRef.RegisterFile__DOT__registers[5]),32);
    bufp->fullIData(oldp+7,(vlSelfRef.RegisterFile__DOT__registers[6]),32);
    bufp->fullIData(oldp+8,(vlSelfRef.RegisterFile__DOT__registers[7]),32);
    bufp->fullIData(oldp+9,(vlSelfRef.RegisterFile__DOT__registers[8]),32);
    bufp->fullIData(oldp+10,(vlSelfRef.RegisterFile__DOT__registers[9]),32);
    bufp->fullIData(oldp+11,(vlSelfRef.RegisterFile__DOT__registers[10]),32);
    bufp->fullIData(oldp+12,(vlSelfRef.RegisterFile__DOT__registers[11]),32);
    bufp->fullIData(oldp+13,(vlSelfRef.RegisterFile__DOT__registers[12]),32);
    bufp->fullIData(oldp+14,(vlSelfRef.RegisterFile__DOT__registers[13]),32);
    bufp->fullIData(oldp+15,(vlSelfRef.RegisterFile__DOT__registers[14]),32);
    bufp->fullIData(oldp+16,(vlSelfRef.RegisterFile__DOT__registers[15]),32);
    bufp->fullIData(oldp+17,(vlSelfRef.RegisterFile__DOT__registers[16]),32);
    bufp->fullIData(oldp+18,(vlSelfRef.RegisterFile__DOT__registers[17]),32);
    bufp->fullIData(oldp+19,(vlSelfRef.RegisterFile__DOT__registers[18]),32);
    bufp->fullIData(oldp+20,(vlSelfRef.RegisterFile__DOT__registers[19]),32);
    bufp->fullIData(oldp+21,(vlSelfRef.RegisterFile__DOT__registers[20]),32);
    bufp->fullIData(oldp+22,(vlSelfRef.RegisterFile__DOT__registers[21]),32);
    bufp->fullIData(oldp+23,(vlSelfRef.RegisterFile__DOT__registers[22]),32);
    bufp->fullIData(oldp+24,(vlSelfRef.RegisterFile__DOT__registers[23]),32);
    bufp->fullIData(oldp+25,(vlSelfRef.RegisterFile__DOT__registers[24]),32);
    bufp->fullIData(oldp+26,(vlSelfRef.RegisterFile__DOT__registers[25]),32);
    bufp->fullIData(oldp+27,(vlSelfRef.RegisterFile__DOT__registers[26]),32);
    bufp->fullIData(oldp+28,(vlSelfRef.RegisterFile__DOT__registers[27]),32);
    bufp->fullIData(oldp+29,(vlSelfRef.RegisterFile__DOT__registers[28]),32);
    bufp->fullIData(oldp+30,(vlSelfRef.RegisterFile__DOT__registers[29]),32);
    bufp->fullIData(oldp+31,(vlSelfRef.RegisterFile__DOT__registers[30]),32);
    bufp->fullIData(oldp+32,(vlSelfRef.RegisterFile__DOT__registers[31]),32);
    bufp->fullIData(oldp+33,(vlSelfRef.RegisterFile__DOT__i),32);
    bufp->fullBit(oldp+34,(vlSelfRef.clk));
    bufp->fullBit(oldp+35,(vlSelfRef.reset));
    bufp->fullCData(oldp+36,(vlSelfRef.addrA),5);
    bufp->fullCData(oldp+37,(vlSelfRef.addrB),5);
    bufp->fullCData(oldp+38,(vlSelfRef.addrD),5);
    bufp->fullIData(oldp+39,(vlSelfRef.dataD),32);
    bufp->fullBit(oldp+40,(vlSelfRef.reg_write));
    bufp->fullIData(oldp+41,(vlSelfRef.dataA),32);
    bufp->fullIData(oldp+42,(vlSelfRef.dataB),32);
}
