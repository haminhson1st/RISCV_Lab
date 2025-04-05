// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VRegisterFile__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

VRegisterFile::VRegisterFile(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VRegisterFile__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , addrA{vlSymsp->TOP.addrA}
    , addrB{vlSymsp->TOP.addrB}
    , addrD{vlSymsp->TOP.addrD}
    , reg_write{vlSymsp->TOP.reg_write}
    , dataD{vlSymsp->TOP.dataD}
    , dataA{vlSymsp->TOP.dataA}
    , dataB{vlSymsp->TOP.dataB}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VRegisterFile::VRegisterFile(const char* _vcname__)
    : VRegisterFile(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VRegisterFile::~VRegisterFile() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VRegisterFile___024root___eval_debug_assertions(VRegisterFile___024root* vlSelf);
#endif  // VL_DEBUG
void VRegisterFile___024root___eval_static(VRegisterFile___024root* vlSelf);
void VRegisterFile___024root___eval_initial(VRegisterFile___024root* vlSelf);
void VRegisterFile___024root___eval_settle(VRegisterFile___024root* vlSelf);
void VRegisterFile___024root___eval(VRegisterFile___024root* vlSelf);

void VRegisterFile::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VRegisterFile::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    VRegisterFile___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        VRegisterFile___024root___eval_static(&(vlSymsp->TOP));
        VRegisterFile___024root___eval_initial(&(vlSymsp->TOP));
        VRegisterFile___024root___eval_settle(&(vlSymsp->TOP));
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    VRegisterFile___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool VRegisterFile::eventsPending() { return false; }

uint64_t VRegisterFile::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VRegisterFile::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void VRegisterFile___024root___eval_final(VRegisterFile___024root* vlSelf);

VL_ATTR_COLD void VRegisterFile::final() {
    VRegisterFile___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VRegisterFile::hierName() const { return vlSymsp->name(); }
const char* VRegisterFile::modelName() const { return "VRegisterFile"; }
unsigned VRegisterFile::threads() const { return 1; }
void VRegisterFile::prepareClone() const { contextp()->prepareClone(); }
void VRegisterFile::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VRegisterFile::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void VRegisterFile___024root__trace_decl_types(VerilatedVcd* tracep);

void VRegisterFile___024root__trace_init_top(VRegisterFile___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    VRegisterFile___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VRegisterFile___024root*>(voidSelf);
    VRegisterFile__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(std::string{vlSymsp->name()}, VerilatedTracePrefixType::SCOPE_MODULE);
    VRegisterFile___024root__trace_decl_types(tracep);
    VRegisterFile___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VRegisterFile___024root__trace_register(VRegisterFile___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void VRegisterFile::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VRegisterFile::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    VRegisterFile___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
