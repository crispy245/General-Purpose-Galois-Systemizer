// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbarret.h for the primary calling header

#include "Vbarret.h"
#include "Vbarret__Syms.h"

//==========

VL_CTOR_IMP(Vbarret) {
    Vbarret__Syms* __restrict vlSymsp = __VlSymsp = new Vbarret__Syms(this, name());
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Reset internal values
    
    // Reset structure values
    _ctor_var_reset();
}

void Vbarret::__Vconfigure(Vbarret__Syms* vlSymsp, bool first) {
    if (false && first) {}  // Prevent unused
    this->__VlSymsp = vlSymsp;
    if (false && this->__VlSymsp) {}  // Prevent unused
    Verilated::timeunit(-12);
    Verilated::timeprecision(-12);
}

Vbarret::~Vbarret() {
    VL_DO_CLEAR(delete __VlSymsp, __VlSymsp = NULL);
}

void Vbarret::_eval_initial(Vbarret__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarret::_eval_initial\n"); );
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbarret::final() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarret::final\n"); );
    // Variables
    Vbarret__Syms* __restrict vlSymsp = this->__VlSymsp;
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
}

void Vbarret::_eval_settle(Vbarret__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarret::_eval_settle\n"); );
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

void Vbarret::_ctor_var_reset() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarret::_ctor_var_reset\n"); );
    // Body
    din_a = VL_RAND_RESET_I(22);
    dout_r = VL_RAND_RESET_I(11);
    barret__DOT__result = VL_RAND_RESET_I(22);
    { int __Vi0=0; for (; __Vi0<1; ++__Vi0) {
            __Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }}
}
