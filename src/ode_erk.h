#ifndef ODE_ERK_H_
#define ODE_ERK_H_

//! \file ode_erk.h

//!Base class with space for temporary solutions moving through RK stages
class OdeERK {

    public:
        //!constructs
        /*!
        \param[in] neq number of equations in ODE system
        */
        OdeERK (unsigned long neq);
        //destructs
        ~OdeERK ();

    protected:
        //!temporary solution vector
        double *soltemp_;
};

#endif
