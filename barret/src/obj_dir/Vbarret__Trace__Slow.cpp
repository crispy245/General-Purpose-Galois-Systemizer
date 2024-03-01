// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vbarret__Syms.h"


//======================

void Vbarret::trace(VerilatedVcdC* tfp, int, int) {
    tfp->spTrace()->addInitCb(&traceInit, __VlSymsp);
    traceRegister(tfp->spTrace());
}

void Vbarret::traceInit(void* userp, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vbarret__Syms* __restrict vlSymsp = static_cast<Vbarret__Syms*>(userp);
    if (!Verilated::calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
                        "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->module(vlSymsp->name());
    tracep->scopeEscape(' ');
    Vbarret::traceInitTop(vlSymsp, tracep);
    tracep->scopeEscape('.');
}

//======================


void Vbarret::traceInitTop(void* userp, VerilatedVcd* tracep) {
    Vbarret__Syms* __restrict vlSymsp = static_cast<Vbarret__Syms*>(userp);
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceInitSub0(userp, tracep);
    }
}

void Vbarret::traceInitSub0(void* userp, VerilatedVcd* tracep) {
    Vbarret__Syms* __restrict vlSymsp = static_cast<Vbarret__Syms*>(userp);
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    const int c = vlSymsp->__Vm_baseCode;
    if (false && tracep && c) {}  // Prevent unused
    // Body
    {
        tracep->declBit(c+1,"clk", false,-1);
        tracep->declBus(c+2,"din_a", false,-1, 3,0);
        tracep->declBus(c+3,"din_m", false,-1, 3,0);
        tracep->declBus(c+4,"dout_r", false,-1, 1,0);
        tracep->declBit(c+1,"barret clk", false,-1);
        tracep->declBus(c+2,"barret din_a", false,-1, 3,0);
        tracep->declBus(c+3,"barret din_m", false,-1, 3,0);
        tracep->declBus(c+4,"barret dout_r", false,-1, 1,0);
        tracep->declBus(c+11,"barret mu_constant", false,-1, 3,0);
        tracep->declBus(c+5,"barret q_val", false,-1, 3,0);
        tracep->declBus(c+6,"barret q_hat", false,-1, 3,0);
        tracep->declBus(c+7,"barret t_val", false,-1, 3,0);
        tracep->declBus(c+8,"barret mult", false,-1, 3,0);
        tracep->declBus(c+9,"barret result", false,-1, 3,0);
        tracep->declBus(c+10,"barret test", false,-1, 3,0);
    }
}

void Vbarret::traceRegister(VerilatedVcd* tracep) {
    // Body
    {
        tracep->addFullCb(&traceFullTop0, __VlSymsp);
        tracep->addChgCb(&traceChgTop0, __VlSymsp);
        tracep->addCleanupCb(&traceCleanup, __VlSymsp);
    }
}

void Vbarret::traceFullTop0(void* userp, VerilatedVcd* tracep) {
    Vbarret__Syms* __restrict vlSymsp = static_cast<Vbarret__Syms*>(userp);
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    // Body
    {
        vlTOPp->traceFullSub0(userp, tracep);
    }
}

void Vbarret::traceFullSub0(void* userp, VerilatedVcd* tracep) {
    Vbarret__Syms* __restrict vlSymsp = static_cast<Vbarret__Syms*>(userp);
    Vbarret* const __restrict vlTOPp VL_ATTR_UNUSED = vlSymsp->TOPp;
    vluint32_t* const oldp = tracep->oldp(vlSymsp->__Vm_baseCode);
    if (false && oldp) {}  // Prevent unused
    // Body
    {
        tracep->fullBit(oldp+1,(vlTOPp->clk));
        tracep->fullCData(oldp+2,(vlTOPp->din_a),4);
        tracep->fullCData(oldp+3,(vlTOPp->din_m),4);
        tracep->fullCData(oldp+4,(vlTOPp->dout_r),2);
        tracep->fullCData(oldp+5,((0xfU & ((IData)(vlTOPp->din_a) 
                                           >> 2U))),4);
        tracep->fullCData(oldp+6,((0xfU & ((IData)(5U) 
                                           * (0xfU 
                                              & ((IData)(vlTOPp->din_a) 
                                                 >> 2U))))),4);
        tracep->fullCData(oldp+7,((3U & (((IData)(5U) 
                                          * (0xfU & 
                                             ((IData)(vlTOPp->din_a) 
                                              >> 2U))) 
                                         >> 2U))),4);
        tracep->fullCData(oldp+8,((0xfU & ((3U & (((IData)(5U) 
                                                   * 
                                                   (0xfU 
                                                    & ((IData)(vlTOPp->din_a) 
                                                       >> 2U))) 
                                                  >> 2U)) 
                                           * (IData)(vlTOPp->din_m)))),4);
        tracep->fullCData(oldp+9,((0xfU & ((IData)(vlTOPp->din_a) 
                                           - ((3U & 
                                               (((IData)(5U) 
                                                 * 
                                                 (0xfU 
                                                  & ((IData)(vlTOPp->din_a) 
                                                     >> 2U))) 
                                                >> 2U)) 
                                              * (IData)(vlTOPp->din_m))))),4);
        tracep->fullCData(oldp+10,(vlTOPp->barret__DOT__test),4);
        tracep->fullCData(oldp+11,(5U),4);
    }
}
