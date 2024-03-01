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
        tracep->chgBit(oldp+0,(vlTOPp->clk));
        tracep->chgCData(oldp+1,(vlTOPp->din_a),4);
        tracep->chgCData(oldp+2,(vlTOPp->din_m),4);
        tracep->chgCData(oldp+3,(vlTOPp->dout_r),2);
        tracep->chgCData(oldp+4,((0xfU & ((IData)(vlTOPp->din_a) 
                                          >> 2U))),4);
        tracep->chgCData(oldp+5,((0xfU & ((IData)(5U) 
                                          * (0xfU & 
                                             ((IData)(vlTOPp->din_a) 
                                              >> 2U))))),4);
        tracep->chgCData(oldp+6,((3U & (((IData)(5U) 
                                         * (0xfU & 
                                            ((IData)(vlTOPp->din_a) 
                                             >> 2U))) 
                                        >> 2U))),4);
        tracep->chgCData(oldp+7,((0xfU & ((3U & (((IData)(5U) 
                                                  * 
                                                  (0xfU 
                                                   & ((IData)(vlTOPp->din_a) 
                                                      >> 2U))) 
                                                 >> 2U)) 
                                          * (IData)(vlTOPp->din_m)))),4);
        tracep->chgCData(oldp+8,((0xfU & ((IData)(vlTOPp->din_a) 
                                          - ((3U & 
                                              (((IData)(5U) 
                                                * (0xfU 
                                                   & ((IData)(vlTOPp->din_a) 
                                                      >> 2U))) 
                                               >> 2U)) 
                                             * (IData)(vlTOPp->din_m))))),4);
        tracep->chgCData(oldp+9,(vlTOPp->barret__DOT__test),4);
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
