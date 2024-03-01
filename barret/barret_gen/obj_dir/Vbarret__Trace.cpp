// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbarret__Syms.h"


void Vbarret::traceChgTop0(void* userp, VerilatedVcd* tracep) {
    Vbarret__Syms* __restrict vlSymsp = static_cast<Vbarret__Syms*>(userp);
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Variables
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    {
        vlTOPp->traceChgSub0(userp, tracep);
    }
}

void Vbarret::traceChgSub0(void* userp, VerilatedVcd* tracep) {
    Vbarret__Syms* __restrict vlSymsp = static_cast<Vbarret__Syms*>(userp);
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode + 1);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->chgIData(oldp+0,(vlTOPp->din_a),22);
        tracep->chgSData(oldp+1,(vlTOPp->dout_r),11);
        tracep->chgIData(oldp+2,((0x3fffffU & (vlTOPp->din_a 
                                               >> 0xbU))),22);
        tracep->chgIData(oldp+3,((0x3fffffU & ((IData)(0x809U) 
                                               * (0x3fffffU 
                                                  & (vlTOPp->din_a 
                                                     >> 0xbU))))),22);
        tracep->chgIData(oldp+4,((0x7ffU & (((IData)(0x809U) 
                                             * (0x3fffffU 
                                                & (vlTOPp->din_a 
                                                   >> 0xbU))) 
                                            >> 0xbU))),22);
        tracep->chgIData(oldp+5,((0x3fffffU & ((IData)(0x7f7U) 
                                               * (0x7ffU 
                                                  & (((IData)(0x809U) 
                                                      * 
                                                      (0x3fffffU 
                                                       & (vlTOPp->din_a 
                                                          >> 0xbU))) 
                                                     >> 0xbU))))),22);
        tracep->chgIData(oldp+6,(vlTOPp->barret__DOT__result),22);
    }
}

void Vbarret::traceCleanup(void* userp, VerilatedVcd* /*unused*/) {
    Vbarret__Syms* __restrict vlSymsp = static_cast<Vbarret__Syms*>(userp);
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlSymsp->__Vm_activity = false;
        vlTOPp->__Vm_traceActivity[0U] = 0U;
    }
}
