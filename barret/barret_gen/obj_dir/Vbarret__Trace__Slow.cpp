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
        tracep->declBus(c+1,"din_a", false,-1, 21,0);
        tracep->declBus(c+2,"dout_r", false,-1, 10,0);
        tracep->declBus(c+1,"barret din_a", false,-1, 21,0);
        tracep->declBus(c+2,"barret dout_r", false,-1, 10,0);
        tracep->declBus(c+8,"barret mu_constant", false,-1, 21,0);
        tracep->declBus(c+3,"barret q_val", false,-1, 21,0);
        tracep->declBus(c+4,"barret q_hat", false,-1, 21,0);
        tracep->declBus(c+5,"barret t_val", false,-1, 21,0);
        tracep->declBus(c+6,"barret mult", false,-1, 21,0);
        tracep->declBus(c+7,"barret result", false,-1, 21,0);
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
        tracep->fullIData(oldp+1,(vlTOPp->din_a),22);
        tracep->fullSData(oldp+2,(vlTOPp->dout_r),11);
        tracep->fullIData(oldp+3,((0x3fffffU & (vlTOPp->din_a 
                                                >> 0xbU))),22);
        tracep->fullIData(oldp+4,((0x3fffffU & ((IData)(0x809U) 
                                                * (0x3fffffU 
                                                   & (vlTOPp->din_a 
                                                      >> 0xbU))))),22);
        tracep->fullIData(oldp+5,((0x7ffU & (((IData)(0x809U) 
                                              * (0x3fffffU 
                                                 & (vlTOPp->din_a 
                                                    >> 0xbU))) 
                                             >> 0xbU))),22);
        tracep->fullIData(oldp+6,((0x3fffffU & ((IData)(0x7f7U) 
                                                * (0x7ffU 
                                                   & (((IData)(0x809U) 
                                                       * 
                                                       (0x3fffffU 
                                                        & (vlTOPp->din_a 
                                                           >> 0xbU))) 
                                                      >> 0xbU))))),22);
        tracep->fullIData(oldp+7,(vlTOPp->barret__DOT__result),22);
        tracep->fullIData(oldp+8,(0x809U),22);
    }
}
