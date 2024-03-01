// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vbarret.h for the primary calling header

#include "Vbarret.h"
#include "Vbarret__Syms.h"

//==========

void Vbarret::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vbarret::eval\n"); );
    Vbarret__Syms* __restrict vlSymsp = this->__VlSymsp;  // Setup global symbol table
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
#ifdef VL_DEBUG
    // Debug assertions
    _eval_debug_assertions();
#endif  // VL_DEBUG
    // Initialize
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) _eval_initial_loop(vlSymsp);
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Clock loop\n"););
        vlSymsp->__Vm_activity = true;
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("barret.v", 2, "",
                "Verilated model didn't converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

void Vbarret::_eval_initial_loop(Vbarret__Syms* __restrict vlSymsp) {
    vlSymsp->__Vm_didInit = true;
    _eval_initial(vlSymsp);
    vlSymsp->__Vm_activity = true;
    // Evaluate till stable
    int __VclockLoop = 0;
    QData __Vchange = 1;
    do {
        _eval_settle(vlSymsp);
        _eval(vlSymsp);
        if (VL_UNLIKELY(++__VclockLoop > 100)) {
            // About to fail, so enable debug to see what's not settling.
            // Note you must run make with OPT=-DVL_DEBUG for debug prints.
            int __Vsaved_debug = Verilated::debug();
            Verilated::debug(1);
            __Vchange = _change_request(vlSymsp);
            Verilated::debug(__Vsaved_debug);
            VL_FATAL_MT("barret.v", 2, "",
                "Verilated model didn't DC converge\n"
                "- See DIDNOTCONVERGE in the Verilator manual");
        } else {
            __Vchange = _change_request(vlSymsp);
        }
    } while (VL_UNLIKELY(__Vchange));
}

VL_INLINE_OPT void Vbarret::_combo__TOP__1(Vbarret__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarret::_combo__TOP__1\n"); );
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->barret__DOT__result = (0x3fffffU & (vlTOPp->din_a 
                                                - ((IData)(0x7f7U) 
                                                   * 
                                                   (0x7ffU 
                                                    & (((IData)(0x809U) 
                                                        * 
                                                        (0x3fffffU 
                                                         & (vlTOPp->din_a 
                                                            >> 0xbU))) 
                                                       >> 0xbU)))));
    vlTOPp->dout_r = (0x7ffU & ((0x7f7U <= vlTOPp->barret__DOT__result)
                                 ? (vlTOPp->barret__DOT__result 
                                    - (IData)(0x7f7U))
                                 : vlTOPp->barret__DOT__result));
}

void Vbarret::_eval(Vbarret__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarret::_eval\n"); );
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    vlTOPp->_combo__TOP__1(vlSymsp);
}

VL_INLINE_OPT QData Vbarret::_change_request(Vbarret__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarret::_change_request\n"); );
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    return (vlTOPp->_change_request_1(vlSymsp));
}

VL_INLINE_OPT QData Vbarret::_change_request_1(Vbarret__Syms* __restrict vlSymsp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarret::_change_request_1\n"); );
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    // Change detection
    QData __req = false;  // Logically a bool
    return __req;
}

#ifdef VL_DEBUG
void Vbarret::_eval_debug_assertions() {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vbarret::_eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((din_a & 0xffc00000U))) {
        Verilated::overWidthError("din_a");}
}
#endif  // VL_DEBUG
