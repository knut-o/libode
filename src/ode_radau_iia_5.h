#ifndef ODE_RADAU_IIA_5_H_
#define ODE_RADAU_IIA_5_H_

#include "ode_base.h"
#include "ode_irk.h"
#include "ode_newton_bridge.h"

//forward declaration to set up Newton class
class OdeRadauIIA5;

//!Nonlinear system solver for Radau IIA 5
class NewtonRadauIIA5 : public OdeNewtonIRK<OdeRadauIIA5> {
    public:
        //!constructs
        /*!
        \param[in] neq size of ODE system
        \param[in] nnew size of Newton system
        \param[in] integrator pointer to OdeRadauIIA5 object
        */
        NewtonRadauIIA5 (unsigned long neq, unsigned long nnew, OdeRadauIIA5 *integrator) : OdeNewtonIRK (neq, nnew, integrator) {};
    private:
        void f_Newton (double *x, double *y);
        void J_Newton (double *x, double **J);
};

//!The fifth-order, L-stable, fully-implicit Radau IIA method with 3 stages
class OdeRadauIIA5 : public OdeBase, private OdeIRK {
    //friends!
    friend class OdeNewtonBridge<OdeRadauIIA5>;
    friend class OdeNewtonIRK<OdeRadauIIA5>;

    public:
        //!constructs
        /*!
        \param[in] neq size of ODE sytem
        */
        OdeRadauIIA5 (unsigned long neq);

        //!destructs
        ~OdeRadauIIA5 ();

        //!returns the solver'sNewton system object
        NewtonRadauIIA5 get_newton () { return(*newton_); }
    private:
        double **a;
        double *b;
        NewtonRadauIIA5 *newton_;
        void step_ (double dt);
};

#endif